import numpy as np 
import networkx as nx
import pylab as pl
import igraph
from scipy.stats.stats import pearsonr 
from mpl_toolkits.axes_grid1 import make_axes_locatable
# pl.switch_backend('agg')

adrsf="../data/f/"
adrs="../data/"

#-------------------------------------------------------------------#    
def comm_weighted(data):
    '''Community structure based on the multilevel
       algorithm of Blondel et al.'''
  
    conn_indices = np.where(data)
    weights = data[conn_indices]
    edges = zip(*conn_indices)
    G = igraph.Graph(edges=edges, directed=False)
    G.es['weight'] = weights
    comm = G.community_multilevel(weights=weights, return_levels=False)
    return comm
#-------------------------------------------------------------------#    
def comm_unweighted(data):
    '''Community structure based on the multilevel
       algorithm of Blondel et al.'''

    conn_indices = np.where(data)
    edgs = zip(*conn_indices)
    G = igraph.Graph(edges=edgs, directed=False)
    comm = G.community_multilevel(weights=None, return_levels=False)
    return comm
#-------------------------------------------------------------------#    
def calculate_NMI(comm1,comm2):
    '''Compares two community structures using normalized 
    mutual information as defined by Danon et al (2005)'''

    nmi = igraph.compare_communities(comm1, comm2, method='nmi', remove_none=False)
    return nmi

#--------------------------------------------------------------#
def imshow_plot(data):
    from mpl_toolkits.axes_grid1 import make_axes_locatable
    fig = pl.figure(100,figsize=(6,6))
    pl.clf()
    ax = pl.subplot(111)
    im = ax.imshow(data,interpolation='nearest', cmap='afmhot') # , cmap=pl.cm.ocean
    ax.invert_yaxis()
    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="5%", pad=0.05)
    pl.colorbar(im, cax=cax)
#--------------------------------------------------------------#
def find_frequency_R(t, r, fc, ind, g, tau, sim):
    '''
    fc : frequenct_cut
    t  : times
    r  : array that its frequency should be calculated
      '''

    def drop_array(x,xcut):
        for count, elem in enumerate(x):
            if elem > xcut:
                return count

    xf,yf = find_frequencies(t[ind:], r[ind:])
    pl.figure(55)
    pl.plot(xf,yf, lw=2)
    pl.xlim(0, 0.1)
    pl.savefig(adrsf+"f-"+str("%09.6f"%g)+'-'+str("%09.6f"%tau)+'-'+str("%02d"%sim)+".png")
    pl.close()
    xf = xf[1:]; yf = yf[1:]   # drop the first element 
    index = drop_array(xf, fc)
    xf = xf[index:]
    yf = yf[index:]
    # a = yf>0.05
    # f = xf>0.0002
    # xf = xf[a & f]
    # yf = yf[a & f]
    try:
        freq = xf[np.argmax(yf)]
        amplitude = np.max(yf)
    except:
        freq, amplitude = [0, 0]
    
    return freq, amplitude
#---------------------------------------------------------#
def drop_array(x, xcut):
        for count, elem in enumerate(x):
            if elem > xcut:
                return count

#---------------------------------------------------------#
def find_dominant_frequency(xf,yf, fcut=0.0, 
                            xflimit=1.e-5, yflimit=0.09):

    index = drop_array(xf, fcut)
    xf = xf[index:]
    yf = yf[index:]
    # a = yf > yflimit
    # f = xf > xflimit
    # xf = xf[a & f]
    # yf = yf[a & f]
    try:
        freq = xf[np.argmax(yf)]
        pxx = np.max(yf)
    except:
        freq, pxx = [0, 0]

    return freq, pxx

#---------------------------------------------------------#
def find_frequencies(x, y, fs, method='FFT', scaling='density'):
    '''
    find power spectrum of a signal and return 
    frequencies and power spectrum
    '''
    if method == 'FFT':
        from scipy.fftpack import fft
        N = len(x)
        dt0 = x[2] - x[1]
        xf = np.linspace(0.0, 1.0 / (2.0 * dt0), N / 2)
        # xf = np.linspace(0, (N/2+1)*fs/N, N/2)
        yf = fft(y)
        yfplot = 2.0 / N * np.abs(yf[0:N // 2])
        return xf[1:], yfplot[1:]
    elif method == 'welch':
        from scipy.signal import welch
        f, pxx = welch(y, fs=fs, nperseg=len(y), scaling=scaling) # scaling='density', scaling='spectrum'
        # pl.semilogy(f, pxx)
        return f, pxx
#--------------------------------------------------------------#
def average_freq_neighbors(freq, G, g, tau, ti, sim=0):
    ''' 
    find average frequencies of neighbors of each node
    ti : time that frequencies are calculated in 
    output: list of averages
    '''
    freq = np.array(freq)
    omega_nb   = []
    N = len(G)
    for i in range(N):
        nb = G.neighbors(i) #list of neighbors
        omega_nb.append(np.mean(freq[nb])) 
    pl.figure(110,figsize=(7,6))
    pl.scatter(freq, omega_nb,s=50, alpha=0.65, c="k")
    pl.xlabel(r'$\omega_i$',fontsize=13)
    pl.ylabel(r'$<\omega>_{nb}^i$',fontsize=13)
    pl.savefig(adrsf+"fre-"+str("%09.6f"%g)+'-'+str("%09.6f"%tau)+'-'+str("%08.2f"%(ti))+'-'+str("%02d"%sim)+".png")
    pl.close()
#--------------------------------------------------------------#
def average_freq_neighbors_time(cor_step, times, sol, g, tau, dt, G, sim=0):
    '''  find average frequencies of neighbors of each node at
    time steps determined by cor_step '''

    rows ,colms = sol.shape
    nc = int(cor_step/dt)
    if nc<100 :
        print "too short data to calculate frequency from time series of data"
        exit(0)
    for  step in range(colms):
        if (step%nc == 0) & (step!=0):
            frequencies = []
            amplitudes = []

            for j in range(rows):
                xf,yf = find_frequencies(times,np.sin(sol[j,:step]))
                freq = xf[np.argmax(yf)]
                frequencies.append(freq)
                amplitudes.append(np.max(yf))
            average_freq_neighbors(frequencies, G, g, tau, step*dt, sim)
#--------------------------------------------------------------#
def binarize(data, threshold):
        data = np.asarray(data)
        upper, lower = 1,0
        data = np.where(data>=threshold,upper,lower)
        return data
#--------------------------------------------------------------#
def pearson_correlation(x):
    row,col = x.shape
    corr = np.identity(row)
    for i in range(row-1):
        for j in range(i+1,row):
            temp = pearsonr(x[i,:],x[j,:])
            corr[i,j] = temp[0]
            corr[j,i] = temp[0]
    return corr
#--------------------------------------------------------------#
def save_plot_xy(x1, y1, name, axs, SAVETXT=False, SAVEFIG=False):
    "save and plot x-y data"
    fig, ax = pl.subplots(1, figsize=(15, 5))
    # ax[0].plot(x2, y2, c="k", lw=0.5)
    # ax[0].set_xlim(np.min(x2), np.max(x2))
    ax.plot(x1,y1, c="r", lw=2)
    ax.set_xlim(axs[0], axs[1])
    ax.set_ylim(axs[2], axs[3])
    pl.savefig(name+".png")
    if SAVETXT:
        np.savetxt(name+".txt", 
                   zip(x1, y1),
                   fmt="%15.9f")
    pl.close()


#--------------------------------------------------------------#
def plot_R(R, Y, X, name="R0"):
    ''' plot time average of order parameter in 2D plane of 
    X and Y axises '''

    np.savetxt(adrsf+name+".txt", R, fmt="%15.9f")
    x_step = X[1]- X[0] 
    y_step = Y[1]  - Y[0]
    

    f, ax       = pl.subplots(1,figsize=(10,10))
    im          = ax.imshow(R, interpolation='nearest', cmap='afmhot')
    ax.invert_yaxis()

    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="5%", pad=0.05)
    pl.colorbar(im, cax=cax)
    step = 10
    ax.set_xticks(np.arange(0, len(X), step));
    ax.set_xticklabels(str("%.1f"%i)for i in X[0::step]);
    ax.set_yticks(np.arange(0, len(Y), step));
    ax.set_yticklabels(str("%.1f"%i)for i in Y[::step]);
    ax.set_ylabel(r"$g$" ,fontsize=16)
    ax.set_title(r"$R$")
    ax.set_xlabel(r"$\omega_0$",fontsize=16)

    pl.savefig(adrsf+name+".png")
    pl.close()
#--------------------------------------------------------------#
def points_on_boundary(X, Y, x, nb):
    ''' get to points X[0],X[1] and Y[0],Y[1],
    find a line between theme and returns points around 
    that line on array x with space dx '''

    dx = x[1]-x[0]

    def f(X,Y,x0):
        y = Y[0]+(Y[1]-Y[0])/float(X[1]-X[0]) + x0
        point = []
        for i in range(-1,2):   #-nb+nb/2+1, nb-nb/2
            point.append(y + i * dx)
        return point
        
    points = np.zeros((2,len(x)*nb))

    # map [x0,x1,...,xn] to [x0,x0,x0, x1,x1,x1, ...,xn,xn,xn]
    b = []
    for i in range(len(x)):
        for j in range(nb):
            b.append(x[i])

    points[0,:] = b
    for i in range(len(x)):
        points[1,i*nb:i*nb+nb] = f(X,Y,x[i])
    return points

    # X = [5, 6]
    # Y = [1, 2]
    # x = np.arange(5,6.1,0.2)
    # points = points_on_boundary(X,Y,x,3)
    # pl.plot(points[0,:], points[1,:], "bo")
#--------------------------------------------------------------#
def display_time(time):
    ''' 
    show real time elapsed
    '''

    hour = int(time/3600);
    minute = (int(time % 3600))/60;
    second = time-(3600.*hour+60.*minute);
    print "Done in %d hours %d minutes %09.6f seconds" \
        %(hour,minute,second)
#--------------------------------------------------------------#
def visualize_phase(ixdata, it, ir, clusters, g, tau, omega, step=10):
    '''
    output: Phase evolutions of oscilltors vs time and
        Kuramoto order parameter vs time,
        in a mp4 file.
    '''
    import matplotlib.animation as animation
    from math import pi
    import sys
    t = it[::step]
    r = ir[::step]
    xdata = ixdata[:,::step]

    N, nstep = xdata.shape
    dt = t[2]-t[1]
    tfinal = t[-1]

    fig, (ax1, ax2) = pl.subplots(2,1,figsize=(7,7))
    ax1 = pl.subplot(211, projection='polar')
    ax1.set_title("", va='bottom')
    ax1.set_rmax(1.1)
    ax1.set_yticklabels([])

    xT=pl.xticks()[0]
    labels = ["0", r"$\frac{\pi}{4}$",r"$\frac{\pi}{2}$",
            r"$\frac{3\pi}{4}$", r"$\pi$",
            r"$\frac{5\pi}{4}$", r"$\frac{3\pi}{2}$",
            r"$\frac{7\pi}{4}$"]

    pl.xticks(xT, labels)
    ax1.grid(True)
    ax2 = pl.subplot(212)
    ax2.set_xlim(0,t[-1])
    ax2.set_ylim(-0.05, 1.05)
    ax2.set_xlabel("Time", fontsize=16)
    ax2.set_ylabel(r"$R$", fontsize=16)

    def update_line(num,xdata,t,r,line):
        line[0].set_data(xdata[:14,num]%(2*pi), [1]*len(xdata[:14,num]))
        line[1].set_data(xdata[14:,num]%(2*pi), [1]*len(xdata[14:,num]))
        line[2].set_data(t[:num],r[:num])
        return line
    n = 12
    line = [0]*3
    line[0], = ax1.plot([0]*n, [1]*n,"bo")
    line[1], = ax1.plot([0]*n, [1]*n,"r>")
    line[2], = ax2.plot([],[],c="k",lw=2)

    line_ani = animation.FuncAnimation(fig, update_line, nstep, 
               fargs=(xdata, t, r, line), interval=20, repeat=False)
    filename = adrsf+"movie-"+str(g)+".mp4"               
    # pl.show()
    line_ani.save(filename)     
    
# ----------------------------------------- #
def savetex(x,y,name):
    ofile = open(adrsf+name+".txt","w")
    row,col = y.shape
    for i in range(col):
        ofile.write("%.6f" % x[i])
        for j in range(row):
            ofile.write("%15.6f" % y[j,i])
        ofile.write("\n")
    ofile.close()
# ----------------------------------------- #
def calculate_modularity(data, membership):
    conn_indices = np.where(data)
    edges = zip(*conn_indices)
    G = igraph.Graph(edges=edges, directed=False)
    return G.modularity(membership)
