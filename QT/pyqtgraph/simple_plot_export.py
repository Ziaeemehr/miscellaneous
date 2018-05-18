from pyqtgraph import exporters
import pyqtgraph as pg
import numpy as np
import sys

# x = np.random.normal(size=1000)
# y = np.random.normal(size=1000)

# fig = pg.plot(x, y, pen=None, symbol='o', title="example")

# # create an exporter instance, as an argument give it
# # the item you wish to export
# exporter = exporters.ImageExporter(fig.plotItem)
# exporter.parameters()['width'] = 100
# exporter.export('fig1.png')

# pg.QtGui.QApplication.exec_()





import pyqtgraph as pg
import pyqtgraph.exporters

# generate something to export
plt = pg.plot([1,5,2,4,3])

# create an exporter instance, as an argument give it
# the item you wish to export
exporter = pg.exporters.ImageExporter(plt.plotItem)

# set export parameters if needed
exporter.parameters()['width'] = 600   # (note this also affects height parameter)

# save to file
exporter.export('fileName.png')
pg.QtGui.QApplication.exec_()
