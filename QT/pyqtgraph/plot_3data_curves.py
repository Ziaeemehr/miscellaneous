from pyqtgraph import exporters
import pyqtgraph as pg
import numpy as np
import sys

np.random.seed(123)

N = 5
x = np.arange(N,dtype='int')
y = np.random.normal(size=(3,N))

for i in range(3):
    print y[i]
plotWidget = pg.plot(title="Three plot curves")

for i in range(3):
    plotWidget.plot(x, y[i], pen=(i,3))

pg.QtGui.QApplication.exec_()
