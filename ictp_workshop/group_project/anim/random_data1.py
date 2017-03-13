"""
===========
Random data
===========

An animation of random data.

"""

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig, ax = plt.subplots()
x = np.random.rand(20)*6
line, = ax.plot(np.sin(x),'ro')
#ax.set_ylim(0, 1)


def update(data):
    line.set_ydata(data)
    return line,


def data_gen():
    while True:
        yield np.random.rand(20)*6

ani = animation.FuncAnimation(fig, update, 
                              data_gen, 
                              interval=500)
plt.show()
