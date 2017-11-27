import numpy as np  
import pylab as pl 
from mpl_toolkits.axes_grid1 import make_axes_locatable

# handling input from terminal
try:
    x= float(sys.argv[1])
    y = float(sys.argv[2])
except IndexError:
    print "Usage: filename.py <x> <y> "
    sys.exit(1)
print x, y

pl.switch_backend('agg')

# -------------------------------------------------------------#
# -------------------------------------------------------------#
def discrete_cmap(N, base_cmap=None):
    """Create an N-bin discrete colormap from the specified input map"""
    base = pl.cm.get_cmap(base_cmap)
    color_list = base(np.linspace(0, 1, N))
    cmap_name = base.name + str(N)
    return base.from_list(cmap_name, color_list, N)
# -------------------------------------------------------------#
# -------------------------------------------------------------#
def binarize(data,threshold):
    upper, lower = 1,0
    data = np.where(data>=threshold,upper,lower)
    return data
# -------------------------------------------------------------#
# -------------------------------------------------------------#
# marker, color, size, linewidth
pl.plot(x,y,marker='o',c='k',markersize=2)
pl.plot(x,y,'k',linewidth=1)

# -------------------------------------------------------------#

def imshow_plot(data):
    from mpl_toolkits.axes_grid1 import make_axes_locatable
    fig = pl.figure(100,figsize=(10,10))
    pl.clf()
    ax = pl.subplot(111)
    im = ax.imshow(data,interpolation='nearest', cmap='afmhot') # , cmap=pl.cm.ocean
    ax.invert_yaxis()
    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="5%", pad=0.05)
    pl.colorbar(im, cax=cax)


# imshow , subplot
a = np.loadtxt("filename.txt")
fig, axs = pl.subplots(2,figsize=(10,10))
im = axs[0].imshow(a,interpolation='nearest')
axs[0].invert_yaxis()
divider = make_axes_locatable(axs[0])
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im, cax=cax)
axs[1].hist(np.sum(a,axis=1))
axs[1].set_title('title')
axs[1].set_xlabel('xlabel')
pl.savefig("filename.png")    
# axarr[0].set_xticks(range(0,ntau,5), map(str,tau[0:-1:5]))
# axarr[0].set_title('Hamming Distance')
# -------------------------------------------------------------#
# -------------------------------------------------------------#
# imshow with changed xticks and yticks
# xlabels = xs
# ylabels = ys
xlabels = range(5,8)
ylabels = range(1,6)
ind_xlabels = [xs.index(i) for i in xlabels]
ind_ylabels = [ys.index(i)   for i in ylabels]
f,ax = pl.subplots(1,figsize=(15,10))
im = ax.imshow(n_comm,interpolation='nearest',
               vmin=2,vmax=12,
               cmap=discrete_cmap(11,'afmhot'))
pl.xticks(ind_xlabels, map(str,xlabels))
pl.yticks(ind_ylabels, map(str,ylabels))
pl.xlabel("")
pl.ylabel("")
pl.title("")
divider = make_axes_locatable(ax)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im, cax=cax,ticks=range(2,13))
pl.savefig("filename.png")
# -------------------------------------------------------------#
# -------------------------------------------------------------#
# read data in plane format and convert to 3d
# col1   col2   col3    col4
# k      tau    omega   R_ave
k=data[:,0].tolist(); k=list(set(k)); k.sort()
tau=data[:,1].tolist(); tau=list(set(tau));tau.sort()
w=data[:,2].tolist(); w=list(set(w)); w.sort()
nk = len(k); ntau=len(tau); nw=len(w)
rave = data[:,3]
rave = np.reshape(rave,(nk,ntau,mw))
# -------------------------------------------------------------#
# subplot , update_line , polar plot, animation(delay_k_w_range)
# -------------------------------------------------------------#
def update_line(num,data,t,rt,line):
    line[0].set_xdata(data[num,1:]%(2*np.pi))
    line[1].set_data(t[:num],rt[:num,1])
    return line
fig, (ax1, ax2) = pl.subplots(2,1,figsize=(15,15))
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
ax2.set_xlim(0,t[n-1])
ax2.set_ylim(0,1.1)
ax2.set_xlabel("Time", fontsize=10)
ax2.set_ylabel(r"$R$", fontsize=10)

colors = np.random.rand(N)
line1, = ax1.plot([0]*N, [1]*N,"bo")
line2, = ax2.plot([],[],"k-")
line = [line1,line2]

line_ani = animation.FuncAnimation(fig, update_line,n, 
            fargs=(data, t, rt, line),
            interval=30, repeat=False)
line_ani.save("./../data/line.mp4",writer=None)

# different color in range, line between 
tl = t[t<=10]
tm = t[(10<t)& (t<68)]
th = t[t>=68]
pl.plot(tl,r_ave[t<=10],'bo',markersize=4)
pl.plot(tm,r_ave[(10<t)& (t<68)],'go',markersize=4)
pl.plot(th,r_ave[t>=68],'ro',markersize=4)
pl.plot([10]*10,np.linspace(0,1,10),'r--',linewidth=3)
pl.plot([68]*10,np.linspace(0,1,10),'r--',linewidth=3)
x = np.linspace(10,68,59)
pl.xticks(np.arange(min(t), max(t)+1, 10),fontsize=15)
pl.yticks(fontsize=15)
pl.ylim(0,1)
pl.xlim(0,90)
pl.grid()


#inset plot
#akuederle.com/matplotlib-zoomed-up-inset
#'upper right'  : 1,
#'upper left'   : 2,
#'lower left'   : 3,
#'lower right'  : 4
fig, ax = plt.subplots() # create a new figure with a default 111 subplot
ax.plot(overview_data_x, overview_data_y)
from mpl_toolkits.axes_grid.inset_locator import zoomed_inset_axes, InsetPosition
axins = zoomed_inset_axes(ax, 2.5, loc=2) # zoom-factor: 2.5, location: upper-left
locate the position of inset
ip = InsetPosition(ax, [0.1,0.05,0.4,0.3]) #left down width hight fraction of main axix
axins.set_axes_locator(ip)

axins.plot(overview_data_x, overview_data_y)
x1, x2, y1, y2 = 47, 60, 3.7, 4.6 # specify the limits
axins.set_xlim(x1, x2) # apply the x-limits
axins.set_ylim(y1, y2) # apply the y-limits
plt.yticks(visible=False)
plt.xticks(visible=False)
from mpl_toolkits.axes_grid1.inset_locator import mark_inset
mark_inset(ax, axins, loc1=2, loc2=4, fc="none", ec="0.5")


# Error bar:

# example data
x = np.arange(0.1, 4, 0.5)
y = np.exp(-x)

plt.errorbar(x, y, xerr=0.2, yerr=0.4, capthick=2, capsize=5, ecolor='g', fmt='--o')
plt.title("Simplest errorbars, 0.2 in x, 0.4 in y")


#xticks interval
ax1.set_xticks(np.arange(0, 6, 0.5))












