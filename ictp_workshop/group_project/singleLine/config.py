import matplotlib.pyplot as plt
from module import Car,plottingTX,animate
import numpy as np

maxCarNumbers = 5
np.random.seed(123)
t0 = 0
timeStep = 0.1
tFinal = 20
intervalAddingCar = 20.*timeStep
minVelocity = 20
maxVelocity = 50
v0 = np.random.randint(10,size=maxCarNumbers)+10
targetVelocity = np.random.rand(maxCarNumbers)* \
    (maxVelocity-minVelocity)+ minVelocity