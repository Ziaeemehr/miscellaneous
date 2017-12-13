from pylab import *

# x = arange(-1.5,1.5,0.01)
# r = -x+x**3
# plot(r,x, lw=2, c='k')

r = arange(.01,5,0.01)
x1 = [0]*len(r)
x2 = -1+1.0/r

plot(r,x1,lw=2,c='b')
plot(r,x2,lw=2,c='r')
ylim(-2,10)

grid()
show()