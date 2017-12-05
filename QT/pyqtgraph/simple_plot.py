import pyqtgraph as pg
import numpy as np

data = np.random.normal(size=1000)
pg.plot(data, title="Simplest possible plotting example")

data = np.random.normal(size=(500,500))
pg.image(data, title="Simplest possible image example")

import sys
# if sys.flags.interactive != 1 or not hasattr(QtCore, 'PYQT_VERSION'):
pg.QtGui.QApplication.exec_()
