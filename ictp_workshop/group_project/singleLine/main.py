import matplotlib.pyplot as plt
import matplotlib.pyplot as plt
from module import Car,plottingTX,animate
import numpy as np
from config import *

cars={}
tmpCarNumbers = 0

nsteps = int(tFinal/timeStep)
plt.figure(figsize=(15,10))

for i in range(nsteps):
    if ((i*timeStep/intervalAddingCar>tmpCarNumbers) & 
        (tmpCarNumbers<maxCarNumbers)):
        tmpCar = Car(t=t0 + i*20,x0=0,v0=v0[tmpCarNumbers],
                     targetVelocity=targetVelocity[tmpCarNumbers],
                     carID=tmpCarNumbers)
        #cars[tmpCarNumbers] = {'x':tmpCar.x,'v':tmpCar.v}
        cars[tmpCarNumbers] = tmpCar
        tmpCarNumbers = len(cars)
        
    for j in range(tmpCarNumbers):
        cars[j].move(timeStep,j,cars)
    #animate(i*timeStep,cars)
    plottingTX(i*timeStep,cars)