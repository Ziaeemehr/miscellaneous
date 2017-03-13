import matplotlib.pyplot as plt
import matplotlib.pyplot as plt
import numpy as np

class Car(object):
    def __init__(self,t,x0,v0,targetVelocity,carID):
        self.t  = t
        self.x  = x0
        self.v  = v0
        self.targetVelocity = targetVelocity
        self.acceleration = 0
        self.positiveA = 0.5
        self.negativeA = -1.
        self.criticalDistance = 10

    def move(self, timeStep,carID,carList):
        if carID>0 :
            distance=abs(carList[carID-1].x - self.x)
            self.acceleration = self.positiveA if distance>self.criticalDistance else self.negativeA
        else:
            self.acceleration = self.positiveA
        
        if (self.v<self.targetVelocity) and (self.v>=0):
            self.v += self.acceleration * timeStep
            
            
        self.x += self.v * timeStep
        
        
        carList[carID].x = self.x
        carList[carID].v = self.v
        

def animate(t,carList):
    x = []
    for i in range(len(carList)):
        x.append(carList[i].x)
    plt.clf()
    plt.plot(x,[0]*len(x),'ko')
    plt.draw()
    plt.pause(0.01)

def plottingTX(t,carList):
    x = []
    for i in range(len(carList)):
        x.append(carList[i].x)
    plt.plot(x,[t]*len(x),'ro')
    plt.draw()
    plt.pause(0.01)