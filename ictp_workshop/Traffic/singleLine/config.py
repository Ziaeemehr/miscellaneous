import matplotlib.pyplot as plt
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
N = 100
t0 = 0
dt = 0.1            
tf = 150
pause = 40.*dt
dm = 25 
minV = 20
maxV = 25
v0 = []
vf = []

for i in range(N):
    v0.append(np.random.randint(minV,maxV))
    vf.append(np.random.randint(minV,maxV))
    