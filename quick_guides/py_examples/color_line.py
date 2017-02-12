import numpy as np
import matplotlib.pyplot as plt
import itertools

x = np.arange(0,2,.1)
y = np.sin(x)
colors = itertools.cycle(['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black','gold','lightcoral','lawngreen','darkblue'])
s = [i*.5 for i in range(11)]
for i in range(11):
    color = colors.next()
    plt.plot(x,y+s[i],'o',c=color)
plt.axis([0,3,0,5])
plt.show()
