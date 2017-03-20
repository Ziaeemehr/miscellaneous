import matplotlib.animation as animation
import matplotlib.gridspec as gridspec
import matplotlib.pyplot as plt
from module import Car
import numpy as np
from config import *

cars = {}
tmpN = 0  #temporal number of cars
nsteps = int(tf/dt)

X = {0: [0]}
for i in range(1, nsteps):
    if ((i*dt/pause > tmpN) & (tmpN < N)):    # if puase time elapsed add a car
        tmpCar = Car(t=t0+i*pause,
                     x0=0,
                     v0=v0[tmpN],
                     vf=vf[tmpN],
                     dm=dm,
                     carID=tmpN)
        cars[tmpN] = tmpCar
        tmpN = len(cars)

    for j in range(tmpN):
        cars[j].move(dt, j, cars)
    Car.monitor(i*dt, cars, X)

#Car.animate(X,gs)

fig1 = plt.figure(figsize=(10,7))
gs   = gridspec.GridSpec(4, 1)
ax1  = plt.subplot(gs[0:3, 0])

line1,= plt.plot([],[],'ro')
maxX = 3000
ax2 = plt.subplot(gs[3, 0])
line2,= plt.plot([],[],'ks')
plt.plot(range(maxX), [1]*maxX,'k-' , linewidth=5)
plt.plot(range(maxX), [-1]*maxX,'k-', linewidth=5)
plt.plot(range(maxX), [0]*maxX,'k--', linewidth=2)

def update_line2(num, l, X):
    t = num*dt
    x = X[t]
    l.set_data(x, [-0.2]*len(x))
    line1.set_data(x,[t]*len(x))
    plt.draw()
    plt.pause(0.001)
    return l,           
line_ani2 = animation.FuncAnimation(fig1, update_line2, 
                                    nsteps, fargs=(line2,X),
                                    interval=50,repeat=True)
#line_ani2.save("street.mp4")
plt.xlim(0, maxX)
plt.ylim(-1.2, 1.2)
plt.show()    



#for i in range(nsteps):
    #t = i*dt
    #print t,X[t]
    
#def update_line(num,l,X):
    #t = num*dt
    #x = X[t]
    #l.set_data(x,[t]*len(x))
    #return l,