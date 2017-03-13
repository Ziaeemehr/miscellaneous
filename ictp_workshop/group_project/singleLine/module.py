import matplotlib.pyplot as plt
import matplotlib.pyplot as plt
import numpy as np

class Car(object):
    def __init__(self,t,x0,v0,vf,
                 dm,carID):
        self.t  = t
        self.x  = x0
        self.v  = v0
        self.vf = vf
        self.posAcc = 1.        #positive acceleration
        self.negAcc = -1.       #negative acceleration
        self.dm = dm
        self.acc = self.posAcc  #instantatious acceleration

    def move(self, dt,carID,carList):
        if carID>0 :
            distance = (carList[carID-1].x - self.x)
            #choose proper acceleration to seed up or break
            if (distance > self.dm) :
                self.acc = self.posAcc
            else :
                self.acc = -(self.v*self.v)/float(2*self.distance)
        
        #decrease the speed 
        if (self.v<self.vf) and (self.v>=0):
            self.v += self.acc * dt
            
        self.x += self.v * dt
        
        carList[carID].x = self.x
        carList[carID].v = self.v
        

def animate(t,carList):
    x = []
    for i in range(len(carList)):
        x.append(carList[i].x)
    plt.clf()
    line, = plt.plot(x,[0]*len(x),'ko')
    plt.xlim([0,200])
    plt.draw()
    plt.pause(0.01)

def plottingTX(t,carList):
    x = []
    for i in range(len(carList)):
        x.append(carList[i].x)
    plt.plot(x,[t]*len(x),'ro')
    plt.draw()
    plt.pause(0.01)