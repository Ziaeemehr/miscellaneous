import sys
from PyQt4 import QtGui

def window():
    app = QtGui.QApplication(sys.argv)
    w   = QtGui.QWidget()
    
    b1 = QtGui.QPushButton("Button1")
    b2 = QtGui.QPushButton("Button2")

    vbox = QtGui.QVBoxLayout()
    vbox.addWidget(b1)
    vbox.addStretch()
    vbox.addWidget(b2)
    
    hbox = QtGui.QHBoxLayout()
    b3 = QtGui.QPushButton("Button3")
    b4 = QtGui.QPushButton("Button4")
    hbox.addWidget(b3)
    hbox.addStretch()
    hbox.addWidget(b4)

    vbox.addStretch()
    vbox.addLayout(hbox)
    w.setLayout(vbox)


    # w.setGeometry(10,10,300,200)
    w.setWindowTitle('PyQt')
    w.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    window()
