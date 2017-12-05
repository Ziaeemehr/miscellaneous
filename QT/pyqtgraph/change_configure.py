import pyqtgraph as pg
import numpy as np
import sys

pg.setConfigOption('background', 'w')
pg.setConfigOption('foreground', 'k')

np.random.seed(123)


N = 5
x = np.arange(N,dtype='int')
y = np.random.normal(size=(3,N))


plotWidget = pg.plot(title="Three plot curves")

for i in range(3):
    plotWidget.plot(x, y[i], pen=pg.mkPen(i,3, width=3))

pg.QtGui.QApplication.exec_()
