import matplotlib.pyplot as plt
from module import Car,plottingTX,animate
import numpy as np

''' variables:
dt    : time step
tf    : final time of simulation
pause : pause to add another car
dm    : min distance to car break
minV  : min velocity 
maxV  : max velocity
v0    : initial velocity
N     : max number of cars
'''

#np.random.seed(123)
N = 5
t0 = 0
dt = 0.1            
tf = 30
pause = 20.*dt
dm = 10 
minV = 20
maxV = 30
v0 = np.random.randint(10,size=N)+10
vf = np.random.rand(N)*(maxV-minV)+ minV