from pylab import *
import matplotlib.pyplot as plt
x1 = arange(0, 6, 0.1)
y1 = arange(0, 3, 0.1)
x, y = meshgrid(x1, y1)

a = b = 1.0

xdot =  -a*x*y
ydot = a * x * y - b * y

streamplot(x, y, xdot, ydot, color='k', cmap=plt.cm.autumn)
plot([0]*len(y1),y1, lw=2, label=r"$\frac{dS}{dt}=0$")
plot(x1,[0]*len(x1), lw=2, label=r"$\frac{dS}{dt}=0, \frac{dI}{dt}=0$")
plot([b/a]*len(y1), y1, lw=2, label=r"$\frac{dI}{dt}=0$")
legend()
xlabel(r"$S$", fontsize=16)
ylabel(r"$I$", fontsize=16)
show()
