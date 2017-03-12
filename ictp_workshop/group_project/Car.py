from ITimeDependent import ITimeDependent

class Car(ITimeDependent):
    def __init__(self,t,v0,x0,targetVelocity,carID):
        self.t  = t
        self.v0 = v0
        self.x0 = x0
        self.x  = 0
        self.v  = 0
        self.targetVelocity = targetVelocity
        self.frontCar = frontCar
        self.acceleration = 0
        self.name = name
        self.positiveA = 0.5
        self.negativeA = -1.
        self.criticalDistance = 10
        
    def move():
        
        
        
        
    def update(self, time,timeStep):
        distance=(self.frontCar.x - self.x)
        self.acceleration = self.positiveA if distance>self.criticalDistance else self.negativeA
        
        if (self.v<self.targetVelocity) and (self.v>=0):
            self.v+=self.acceleration * timeStep
            
        self.x+= self.v * timeStep
        file=open("report/{}.dat".format(self.name),"a")
        file.write("{}     {}\n".format(time,self.x))
        file.close()      