import pylab as pl 
import numpy as np 
from mpl_toolkits.axes_grid1 import make_axes_locatable

delta = 4.05 - 4.0
R = np.genfromtxt("R.txt")
r = np.genfromtxt("r.txt")
Y = np.arange(0.5 , 2 , 0.1).tolist()
X = np.arange(0.1 , 17, 0.02)

f, axs = pl.subplots(2,figsize=(20,6))
im = [0,0]
im[0] = axs[0].imshow(R, interpolation='nearest', cmap='afmhot', aspect='auto')
im[1] = axs[1].imshow(r, interpolation='nearest', cmap='afmhot', aspect='auto')

axs[0].invert_yaxis()
axs[1].invert_yaxis()

divider = make_axes_locatable(axs[0])
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im[0], cax=cax)

divider = make_axes_locatable(axs[1])
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im[1], cax=cax)

for i in range(2):
    axs[i].set_xticks(np.arange(45, len(X), 50));
    axs[i].set_xticklabels(str("%.0f"%i)for i in X[45::50]);
    axs[i].set_yticks(np.arange(0, len(Y), 2));
    axs[i].set_yticklabels(str("%.1f"%i)for i in Y[::2]);

axs[0].set_ylabel(r"$R$"   ,fontsize=16)
axs[1].set_ylabel(r"$R_{local}$"   ,fontsize=16)
axs[1].set_xlabel(r"$\omega_0$",fontsize=16)
axs[0].set_ylim(0,8)
axs[1].set_ylim(0,8)

pl.savefig("R.png")
pl.show()
