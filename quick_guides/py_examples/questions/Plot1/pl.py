import numpy as np
import matplotlib.pyplot as plt
from math import *

def readfile(address):
    ifile = open(address,'r')
    data = np.genfromtxt(ifile)
    ifile.close()
    return data

def fhist(x,n):
    x = np.sort(x)
    a = np.min(x)
    b = np.max(x)
    dl = (b-a)/float(n)
    lbin = dl
    counts = []
    bins = []
    counter = 0
    for i in range(x.size):
        if(x[i]<lbin):
            counter += 1
        else:
            counts.append(counter/float(x.size))
            bins.append(lbin)
            lbin += dl
            counter = 0
    ind = counts.index(max(counts))
    return bins,counts,bins[ind],counts[ind]
        
n = 100        
width = 0.05
fig = plt.figure(figsize=(20,10))
ax = fig.add_subplot(111)
ax.set_xlabel('Position',fontsize=30)
ax.set_ylabel('P(z)',fontsize=30)
plt.ylim((0,0.065))
plt.xlim((0,35))
colors=['red','blue','yellow','green']

indxs = []
indys = []
for i in range(30,40):
    data = readfile('Position'+str(i)+'.dat')
    bins,counts, indx,indy = fhist(data,n)
    ax.bar(bins,counts,width,color='dimgray',edgecolor = "none",label='Position'+str(i))
    ax.text(indx-indx*0.02,indy+0.019*indy,str('%.2f'%indx),fontsize=10,color='red')
    indxs.append(indx)
    indys.append(indy)


#------------------adding distances------------------#
for i in range(len(indxs)-1):
    ax.annotate(
        '', xy=(indxs[i]  , indys[i]), xycoords='data',
        xytext=(indxs[i+1], indys[i]), textcoords='data',
        arrowprops={'arrowstyle': '<->'})
    ax.annotate(
        str("%.2f"%(indxs[i+1]-indxs[i])) , xy=((indxs[i+1]+indxs[i])/2.0-0.5,indys[i]+indys[i]*0.01 ), xycoords='data',
        xytext=(5, 0), textcoords='offset points')




# ax.annotate(
#     '', xy=(3.07, 0.048), xycoords='data',
#     xytext=(6.05, 0.048), textcoords='data',
#     arrowprops={'arrowstyle': '<->'})
# ax.annotate(
#     str(6.05-3.07) , xy=((3.07+6.05)/2.0-0.5,0.048 ), xycoords='data',
#     xytext=(5, 0), textcoords='offset points')




#plt.legend(frameon=False)
plt.savefig('fig5.png')

plt.show()







#fig = plt.figure()
#ax = fig.add_subplot(111)
#n, bins, rectangles = ax.hist(data30, 100, normed=True)
#fig.canvas.draw()







#plt.hist(data30, weights=weights)
#plt.title("Histogram with 'auto' bins")
#plt.show()

#hist,bins = np.histogram(data30, bins='auto', density=True)
#weights = data30/(data30.size)
#hist , bin_edges = np.histogram(data30,bins=100,normed=True)
#plt.hist(hist)
