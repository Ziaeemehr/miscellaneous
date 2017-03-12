from Car import Car
from Clock import Clock

cars=[]
t0 = 0
for i in range(5):
    cars.append(Car(t=t0 + 20,v0=10,x0=0,targetVelocity=20,carID="car{}".format(i)))
    clock.addListener
    
    



tmpCar1=Car(10,15,20,"car1")
cars.append(tmpCar1)

clock=Clock(.1, 20)

for i in range(2,10):
    tmpCar2=Car(10,15,20,"car{}".format(i))
    tmpCar2.setFrontCar(tmpCar1)
    cars.append(tmpCar2)
    clock.addListener(tmpCar2)
    tmpCar1=tmpCar2
    
cars[0].frontCar=cars[-1]

for i in cars:
    print(i.name,i.frontCar.name)


clock.start()