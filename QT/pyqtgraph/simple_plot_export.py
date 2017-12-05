from pyqtgraph import exporters
import pyqtgraph as pg
import numpy as np
import sys

x = np.random.normal(size=1000)
y = np.random.normal(size=1000)

fig = pg.plot(x, y, pen=None, symbol='o', title="example")

# create an exporter instance, as an argument give it
# the item you wish to export
exporter = exporters.ImageExporter(fig.plotItem)
exporter.parameters()['width'] = 100
exporter.export('fig1.png')

pg.QtGui.QApplication.exec_()
