from pylab import *
import matplotlib.pyplot as plt

x, y = meshgrid(arange(0, 3, 0.1), arange(0, 3, 0.1))

xdot =   x - x * y
ydot = - y + x * y

streamplot(x, y, xdot, ydot, color='k', cmap=plt.cm.autumn)
axis([0,3,0,3])
xlabel("x")
ylabel("y")
show()
