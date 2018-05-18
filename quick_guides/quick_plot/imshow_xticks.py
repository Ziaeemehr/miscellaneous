#!/usr/bin/env python
import matplotlib.pyplot as plt
import numpy as np

#Generate random histogram
N = 25
middle = N/2
hist = np.random.random_sample((N, N))

#Ticks at even numbers, data centered at 0
ticks = np.arange(-100, middle+2, 2)

extent = (-middle, middle, -middle, middle)
plt.imshow(hist, interpolation='nearest', 
extent=extent, origin='lower')
plt.xticks(ticks)
plt.show()
