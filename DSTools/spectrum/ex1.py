from scipy.fftpack import fft
import numpy as np 
import pylab as pl 


def find_frequencies(x,y): 
    N = len(x)
    dt0 = x[2]-x[1]
    xf = np.linspace(0.0, 1.0/(2.0*dt0), N/2)
    yf = fft(y)
    yfplot = 2.0/N * np.abs(yf[0:N//2])
    return xf, yfplot

N = 400         # Number of sample points
dt = 1.0/800.0   # sample spacing
x = np.linspace(0.0,N*dt,N)
nu1 = 50.0
nu2 = 80.0

y = 2*np.sin(nu1 * 2.0*np.pi*x) + np.sin(nu2 * 2.0*np.pi*x)

a,b = find_frequencies(x,y)
pl.plot(a,b)

pl.figure()
from spectrum import *
p = Periodogram(y, sampling=1./dt)
p.run()
p.plot( marker="o")

pl.show()
