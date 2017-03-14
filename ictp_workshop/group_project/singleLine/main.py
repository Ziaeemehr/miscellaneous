import matplotlib.pyplot as plt
from module import Car
import numpy as np
from config import *

cars={}
tmpN = 0 #temporal number of cars

nsteps = int(tf/dt)
plt.figure(figsize=(10,7))

for i in range(nsteps):
    if ((i*dt/pause>tmpN) & (tmpN < N)):     #if puase time elapsed add a car 
        tmpCar = Car(t=t0+i*pause,
                     x0=0,
                     v0=v0[tmpN],
                     vf=vf[tmpN],
                     dm=dm,
                     carID=tmpN)
        cars[tmpN] = tmpCar
        tmpN = len(cars)
        
    for j in range(tmpN):                   # move all cars in each time step
        cars[j].move(dt,j,cars)
    
    Car.animate(i*dt,cars)                      #create a frame of animation for each time step
    #plottingTX(i*dt,cars)
plt.show()    