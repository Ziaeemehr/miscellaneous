import pylab as pl
import numpy as np 

g = 2
tau = np.arange(5,7,1./32)
R = []
fig,ax = pl.subplots(1,figsize=(10,5))
for i in tau:
    filename = "r-"+str("%.6f"%g)+"-"+str("%.6f"%i)+".txt"
    data = np.genfromtxt(filename)
    R.append(np.mean(data[:,1]))

ax.plot(tau,R,lw=2)
ax.plot(tau,R,"ro",label="g = 2")
ax.set_xlabel(r"$\tau$",fontsize=16)
ax.set_ylabel("R",fontsize=16)
ax.annotate('A', xy=(6.78125, 0.1), xytext=(6.75, 0.1))
ax.annotate('B', xy=(6.81,0.16), xytext=(6.76, 0.16))
ax.annotate('C', xy=(6.84, 0.24), xytext=(6.79, 0.24))


            # arrowprops=dict(facecolor='black', shrink=0.05),

            # )
y1 = np.linspace(-0.1,0.5,10)
# ax.plot([5.0625 ]*10,y1, c="k",ls="--")
# ax.plot([5.18725]*10,y1, c="k",ls="--")
# ax.plot([6.78125]*10,y1, c="k",ls="--")
# ax.plot([6.9375 ]*10,y1, c="k",ls="--")
ax.fill_between([5.0625,5.18725], [-1,-1],[1,1] , facecolor='lightgray')
ax.fill_between([6.78125,6.9375], [-1,-1],[1,1] , facecolor='lightgray')
ax.set_ylim(-0.01,0.36)
pl.legend(loc="upper center")
pl.savefig("1.png")
pl.show()    
    
