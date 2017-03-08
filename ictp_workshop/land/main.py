#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

cor =np.fromfile('coordinates.bsq',dtype=np.int8) 
cor = np.reshape(cor,(21600,43200))

#plt.imshow(cor[::10,::10])
#plt.colorbar()
#plt.savefig('s.png')
#plt.show()
plt.figure(figsize=(5,5))
def plot_region(i_lon,i_lat,lon,lat):
   plt.clf()
   region = cor[i_lon-2000:i_lon+2000:10,i_lat-2000:i_lat+2000:10]
   plt.imshow(region)
   plt.plot(200,200,'ro')
   plt.axis([0,400,0,400])
   plt.savefig('./figs/'+str(lat)+'-'+str(lon)+'.png')
   
land_counter = 0
water_counter= 0
pixel = 0.00833

with open("events.txt",'r') as f:
   c = 0
   for line in f:
      data = line.split(';')
      c +=1
      if c>7:     
         lat = float(data[1]) + 180.
         lon = float(data[2]) + 90.
         i_lat = int(lat/pixel)  
         i_lon = int(-lon/pixel) 
         value = cor[i_lon,i_lat]
	 local= cor[i_lon-10:i_lon+10:2,i_lat-10:i_lat+10:2]
	 plot_region(i_lon,i_lat,lon,lat)
         if value ==0:
            print "%10.2f %10.2f %s" %(i_lat, i_lon, "Water") 
	    water_counter +=1
         else: 
            print "%10.2f %10.2f %s" %(i_lat, i_lon, "land") 
	    land_counter +=1


print "number of coordinates :", c-7
print "water points:" , water_counter
print "land points :", land_counter

