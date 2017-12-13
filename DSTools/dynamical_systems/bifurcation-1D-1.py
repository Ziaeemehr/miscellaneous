import scipy as s
from pylab import *


r = linspace(0,5,1000)
iteration = 300
x = ones(len(r))

for i in range(iteration):
    x = r - x*x

for i in range(iteration):
    x = r - x*x
    plot(r,x,'.', color='k', markersize=2)

show()
