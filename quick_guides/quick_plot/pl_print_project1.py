import numpy as np
import pylab as pl
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from mpl_toolkits.axes_grid1 import make_axes_locatable
import matplotlib


fig = plt.figure(figsize=(8,10))
gs0 = gridspec.GridSpec(1, 2)

gs00 = gridspec.GridSpecFromSubplotSpec(24, 1, 
                                        subplot_spec=gs0[0],)
                                        # hspace=1)
gs01 = gridspec.GridSpecFromSubplotSpec(4, 1, 
                                        subplot_spec=gs0[1], 
                                        hspace=0.02,
                                        wspace=0.05)


def binarize(data, threshold):
        data = np.asarray(data)
        upper, lower = 1, 0
        data = np.where(data >= threshold, upper, lower)
        return data


R = np.genfromtxt("R.txt")
con = np.genfromtxt("con.txt")
cor1 = np.genfromtxt("cor1.txt")
cor2 = np.genfromtxt("cor2.txt")
cor3 = np.genfromtxt("cor3.txt")
cor4 = np.genfromtxt("cor4.txt")

nmi = np.genfromtxt('nmi.txt')
g = np.arange(0.1, 3.1, 0.02)
mu = np.arange(4.9, 6, 0.02)

ax0 = plt.subplot(gs00[:8, 0])
ax1 = plt.subplot(gs00[8:18, 0])
ax2 = plt.subplot(gs00[18:, 0])
ax3 = plt.subplot(gs01[0,0])
ax4 = plt.subplot(gs01[1, 0])
ax5 = plt.subplot(gs01[2, 0])
ax6 = plt.subplot(gs01[3, 0])

# ax0.set_aspect('equal', 'box')
ax3.set_aspect('equal', 'box')
ax4.set_aspect('equal', 'box')
ax5.set_aspect('equal', 'box')
ax6.set_aspect('equal', 'box')

ax0.set_xticks([])
ax0.set_yticks([])
ax3.set_xticks([])
ax3.set_yticks([])
ax4.set_xticks([])
ax4.set_yticks([])
ax5.set_xticks([])
ax5.set_yticks([])
ax6.set_xticks([])
ax6.set_yticks([])

im0 = ax0.imshow(con, interpolation='nearest',
                 cmap='afmhot', aspect='auto')  # , cmap=pl.cm.ocean
ax0.invert_yaxis()
ax0.text(-10, 55, "(a)", fontsize=15)
divider = make_axes_locatable(ax0)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im0, cax=cax, ticks=[i*0.1 for i in range(0, 11,5)])



im = ax1.imshow(R, interpolation='bicubic', cmap='afmhot',
                aspect='auto')  # , cmap=pl.cm.ocean, gist_gray
ax1.invert_yaxis()
nxi, nxf, nxstep = 5, len(mu), 20
nyi, nyf, nystep = 20, len(g), 25
ax1.set_xticks(np.arange(nxi, nxf, nxstep))
ax1.set_yticks(np.arange(nyi, nyf, nystep))
ax1.set_xticklabels(str("%.1f" % i)for i in mu[nxi::nxstep])
ax1.set_yticklabels(str("%.1f" % i)for i in g[nyi::nystep])
ax1.text(-10, 125, "(b)", fontsize=15)
ax1.set_xlim(-0.5,60)
ax1.set_ylim(0, 130)
divider = make_axes_locatable(ax1)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im, cax=cax, ticks=[0.2 * i for i in range(5)])
ax1.set_xlabel(r"$\omega_0$", fontsize=13)
ax1.set_ylabel("K", fontsize=13, rotation=0, labelpad=10)
ax1.set_xticks([])


ax2.plot(nmi[:, 0], nmi[:, 1], lw=2, c='k')
ax2.set_ylabel('NMI', rotation=0, fontsize=13, labelpad=15)
x = nmi[:, 0]
y = nmi[:, 1]
ax2.set_xticks(np.arange(5, 6.5, 0.5))
ax2.set_yticks(np.arange(min(y), max(y), 0.2))
ax2.set_xlim(min(nmi[:, 0]), max(nmi[:, 0])+0.1)
ax2.set_ylim(0, 0.75)
ax2.text(4.7, 0.65, "(c)", fontsize=15)
ax2.set_xlabel(r"$\omega_0$", fontsize=16)


im3 = ax3.imshow(cor1, 
                 interpolation='nearest',
                 cmap='afmhot')  # , cmap=pl.cm.ocean
ax3.invert_yaxis()
ax3.text(-10, 53, "(d)", fontsize=15)
divider = make_axes_locatable(ax3)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im3, cax=cax, ticks=[0.994, 1], format="%.2f")

im4 = ax4.imshow(cor2, 
                interpolation='nearest', 
                cmap='afmhot', 
                alpha=0.9,
                # vmin=0, vmax=1
                )  # , cmap=pl.cm.ocean
ax4.invert_yaxis()
ax4.text(-10, 53, "(e)", fontsize=15)
divider = make_axes_locatable(ax4)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im4, cax=cax, ticks=[0.1 * i for i in range(-10, 11, 5)])

im5 = ax5.imshow(cor3, interpolation='nearest',
                 cmap='afmhot')  # , cmap=pl.cm.ocean
ax5.invert_yaxis()
ax5.text(-10, 53, "(f)", fontsize=15)
divider = make_axes_locatable(ax5)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im5, cax=cax, ticks=[0.1 * i for i in range(-10, 10, 5)])

im6 = ax6.imshow(cor4, interpolation='nearest',
                 cmap='afmhot')  # , cmap=pl.cm.ocean
ax6.invert_yaxis()
ax6.text(-10, 53, "(g)", fontsize=15)
divider = make_axes_locatable(ax6)
cax = divider.append_axes("right", size="5%", pad=0.05)
pl.colorbar(im6, cax=cax, ticks=[0.1 * i for i in range(-10, 11, 5)])

fig.tight_layout()
pl.savefig("tot.png")  # facecolor='#edfffa'
pl.savefig("tot.eps")

# pl.show()
