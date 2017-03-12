from ITimeDependent import ITimeDependent
import numpy as np
class Clock(object):
    def __init__(self,timeStep,finalTime):
        self.timeStep=timeStep
        self.finalTime=finalTime
        self.listeners=[]
        
    def addListener(self,timeDependent):
        self.listeners.append(timeDependent)
    
    def start(self):   
        for t in np.arange(0,self.finalTime,self.timeStep):
            for i in self.listeners:
                i.update(t,self.timeStep)
        