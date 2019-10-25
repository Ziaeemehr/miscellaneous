from scipy import spatial
import numpy as np 
from glob import glob 
import pylab as pl 
from mpl_toolkits.axes_grid1 import make_axes_locatable
from sys import exit

def plot(R, X, Y, name="f"):
    

    f, ax = pl.subplots(1, figsize=(15, 15))
    im = ax.imshow(R)
    ax.invert_yaxis()

    divider = make_axes_locatable(ax)
    cax = divider.append_axes("right", size="5%", pad=0.05)
    pl.colorbar(im, cax=cax)
    ax.set_xticks(np.arange(len(X)))
    ax.set_xticklabels((str("%s" % i)for i in X), rotation='vertical')
    ax.set_yticks(np.arange(len(Y)))
    ax.set_yticklabels(str("%s" % i)for i in Y)

    pl.savefig(name+".pdf")
    # pl.close()
#--------------------------------------------------------------#


flist = np.sort(glob("dat/*.txt"))
n = len(flist)
C = np.zeros((n, n))
labels = [i.split(".")[0] for i in flist]
labels = [i.split("/")[1] for i in labels]

for i in range(n):
    for j in range(n):
        data1 = np.genfromtxt(flist[i])[:,0]
        data2 = np.genfromtxt(flist[j])[:,0]        
        C[i, j] = 1 - spatial.distance.cosine(data1, data2)


plot(C, labels, labels)
# pl.show()
