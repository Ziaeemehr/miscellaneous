import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import numpy as np

class Car(object):
    def __init__(self,t,x0,v0,vf,
                 dm,carID):
        self.t  = t
        self.x  = x0
        self.v  = v0
        self.vf = vf
        self.posAcc = 1.        #positive acceleration
        self.negAcc = -1.       #negative acceleration (later is changed by velocity)
        self.dm = dm
        self.acc = self.posAcc  #instantatious acceleration

    def move(self, dt,carID,carList):
        if carID>0 :
            distance = (carList[carID-1].x - self.x)
            #choose proper acceleration to seed up or break
            if (distance > self.dm) :
                self.acc = self.posAcc
            else :
                self.acc = -1#(self.v*self.v)/float(2*distance)
        
        #decrease the speed 
        if (self.v<self.vf) and (self.v>=0):
            self.v += self.acc * dt
            
        self.x += self.v * dt
        
        carList[carID].x = self.x
        carList[carID].v = self.v
    
    @staticmethod
    def monitor(t,carList,X):
        x = []
        for i in range(len(carList)):
            x.append(carList[i].x)
        X[t] = x
        
    
    #@staticmethod
    #def animate(t,carList,gs):
        #x = []
        #for i in range(len(carList)):
            #x.append(carList[i].x)
        #ax1 = plt.subplot(gs[0:3, 0])
        #plt.plot(x,[t]*len(x),'ro')
        #plt.ylabel('Time')
        #plt.xlim([0,250])
        #plt.tick_params(
            #axis='x',          # changes apply to the x-axis
            #which='both',      # both major and minor ticks are affected
            #bottom='off',      # ticks along the bottom edge are off
            #top='off',         # ticks along the top edge are off
            #labelbottom='off') # labels along the bottom edge are off
        #ax2 = plt.subplot(gs[3, 0])
        #line, = plt.plot(x,[0]*len(x),'ko')
        ##line.remove()
        ##del line
        #plt.xlim([0,250])
        #plt.xlabel("position")
        
        #plt.draw()
        #plt.pause(0.01)