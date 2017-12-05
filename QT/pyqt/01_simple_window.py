import sys
from PyQt4 import QtGui



app = QtGui.QApplication(sys.argv)
w = QtGui.QWidget()
b = QtGui.QLabel(w)
b.setText("Hello World!")
w.setGeometry(50,50,500,300)
w.setWindowTitle("PyQt!")
w.show()
sys.exit(app.exec_())
