# -*- coding: utf-8 -*-
"""
Created on Thu Feb 06 16:40:40 2014

@author: Edgar Haener
"""
 
import matplotlib.pyplot as plt
import numpy as np
#creating something to plot
x=np.arange(start=0, stop=10000, step=100)
y=np.random.rand(len(x))
y=x*y
#ploting something here
fig, ax = plt.subplots(1)
ax.plot(x,y, 'ro', markersize=12)
ax.ticklabel_format(axis='both', style='sci', scilimits=(-2,2))
plt.show()




#import numpy as np
#import matplotlib.pyplot as plt
#import matplotlib.ticker as mtick

#fig = plt.figure()
#ax = fig.add_subplot(111)
#x = np.linspace(0, 300, 20)
#y = np.linspace(0,300, 20)
#y = y*1e10
#ax.plot(x,y)
#ax.yaxis.set_major_formatter(mtick.FormatStrFormatter('%.2e'))
#plt.show()
