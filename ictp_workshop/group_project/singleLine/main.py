import matplotlib.pyplot as plt
from module import Car,plottingTX,animate
import numpy as np
from config import *

cars={}
tmpN = 0 #temporal number of cars

nsteps = int(tf/dt)
plt.figure(figsize=(10,7))

for i in range(nsteps):
    if ((i*dt/pause>tmpN) & (tmpN < N)):
        tmpCar = Car(t=t0+i*pause,x0=0,v0=v0[tmpN],
                     vf=vf[tmpN],
                     dm=dm,
                     carID=tmpN)
        cars[tmpN] = tmpCar
        tmpN = len(cars)
        
    for j in range(tmpN):
        cars[j].move(dt,j,cars)
    
    animate(i*dt,cars)
    #plottingTX(i*dt,cars)
plt.show()    