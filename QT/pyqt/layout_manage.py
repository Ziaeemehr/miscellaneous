import sys
from PyQt4 import QtGui

def window():
    app = QtGui.QApplication(sys.argv)
    w   = QtGui.QWidget()
    
    b1 = QtGui.QPushButton("Button1")
    b2 = QtGui.QPushButton("Button2")

    # vbox = QtGui.QVBoxLayout()
    vbox = QtGui.QHBoxLayout()
    vbox.addWidget(b1)
    vbox.addStretch()
    vbox.addWidget(b2)
    w.setLayout(vbox)

    w.setGeometry(10,10,300,200)
    w.setWindowTitle('PyQt')
    w.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    window()
