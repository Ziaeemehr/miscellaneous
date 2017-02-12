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
ax.set_xlabel('xlabel')
ax.set_ylabel('ylabel')
colors=['red','blue','yellow','green']
for i in range(30,34):
    data = readfile('Position'+str(i)+'.dat')
    bins,counts, indx,indy = fhist(data,n)
    ax.bar(bins,counts,width,color=colors[i-30],label='Position'+str(i))
    ax.text(indx,indy+0.051*indy,str('%.2f'%indx))
    
plt.legend(frameon=False)
plt.savefig('fig.eps')

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
