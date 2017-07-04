#!/usr/bin/env python

"""
visualizing the simulation of a all to all network
of Kuramoto oscillators with constant delay.
output: phase evolutions of oscilltors vs time and
        Kuramoto order parameter vs time,
        in a mp4 file.
"""

import numpy as np 
import pylab as pl 
import matplotlib.animation as animation
import glob
xfile, = glob.glob("./../data/x*")
rfile, = glob.glob("./../data/r*")
data = np.loadtxt(xfile)

t = data[:,0]
x = data[:,1:]
nsteps, N = data.shape
N = N-1
dt = t[2]-t[1]
tfinal=2000
n = int(tfinal/dt)
rt = np.loadtxt(rfile)

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
#pl.show()
