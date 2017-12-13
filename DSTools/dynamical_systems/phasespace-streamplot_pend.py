from pylab import *
import matplotlib.pyplot as plt
x1 = arange(-6, 6, 0.1)
y1 = arange(-3, 3, 0.1)
x, y = meshgrid(arange(-6, 6, 0.1), arange(-3, 3, 0.1))

g_over_l = 9.8

xdot =  y
ydot = - g_over_l * sin(x)

streamplot(x, y, xdot, ydot, color='k', cmap=plt.cm.autumn)
plot(x1, [0]* len(x1), lw=2, label=r"$\frac{d\theta}{dt}$")
labels = ["","",r"$\frac{d\omega}{dt}=0$"]
for i in range(3):
    plot([(i-1)*pi]*len(y1), y1, lw=2, c="r", label=labels[i])
# axis([0,6,0,6])
legend()
xlabel(r"$\theta$", fontsize=16)
ylabel(r"$\omega$", fontsize=16)
show()
