# PyQtGraph’s Helper Functions
# http://www.pyqtgraph.org/documentation/functions.html#pyqtgraph.mkPen

# change line properties
import pyqtgraph as pg

pg.setConfigOption('background', (255, 255, 200))
pg.setConfigOption('foreground', 'k')

y=[1,1,1,1,1]
pg.plot(y, pen=pg.mkPen('b', width=5))
pg.plot(xdata, ydata, pen='r')
pg.plot(xdata, ydata, pen=pg.mkPen('r'))
pg.plot(xdata, ydata, pen=QPen(QColor(255, 0, 0)))