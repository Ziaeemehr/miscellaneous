from pylab import *
from scipy.optimize import fsolve
from numpy import linalg as LA
from scipy.integrate import odeint
import numpy as np

c = 3.0
a = 0.7
b = 0.8
t = np.arange(0,50,0.1)
# z=-1

def func(x0,t, z):
	x,y = x0
	return [c*(x-x**3/3.0+y+z),
			-((x-a+b*y)/float(c))]

def jac(x0):
	x, y = x0
	return np.array([[c * ( 1 - x * x ), c] , [ -1. / c, -b / c]])

def plot_phase_space(z):
	sol = odeint(func, [0,0], t, args=(z,))
	plot(sol[:,0], sol[:,1])
	# xticks(np.arange(-2,0,0.5))
	title("r="+str(z))



zs = np.arange(-2,0,0.01)
nz = len(zs)
fig, (ax1,ax2) = subplots(2)

for i in range(nz):
	z = zs[i]
	xeq, yeq = fsolve(func, [1, 1], args=(0, z,))
	ax1.plot(xeq,yeq,"ko", markersize=3)
	J = jac([xeq,yeq])
	w, v = LA.eig(J)
	# print z[i], w.real
	ax2.plot(z,w[0],'r>', markersize=4)
	ax2.plot(z,w[1],'bo', markersize=4)
ax1.set_xlabel(r"$x_{eq}$")
ax1.set_ylabel(r"$y_{eq}$")
ax2.plot(zs,[0]*nz, lw=2, ls='--', c='k')
ax2.set_ylabel(r"$Re(\lambda)$")
ax2.set_xlabel(r"$Z$")
grid()
figure(figsize=(15,6))
zs1 = [-1.5,-1.35, -0.8, -0.33, 0 ]
for i in range(len(zs1)):
	subplot(1,len(zs1),i+1)
	plot_phase_space(zs1[i])


show()

		


















# import sympy as sp 
# from sympy.abc import x,y,z

# sol = sp.solve([c*(x-x**3/3+y+z),-((x-a+b*y)/c)],[x,y],dict=True)
