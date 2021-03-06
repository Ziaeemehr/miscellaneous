import sys
from PyQt4 import QtGui
from PyQt4 import QtCore # to add a button

class Window(QtGui.QMainWindow):
    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(50,50,500,300)
        self.setWindowTitle("PyQt tuts!")
        self.setWindowIcon(QtGui.QIcon('mainlogo.png'))
        self.home()

    def home(self):
        btn = QtGui.QPushButton("Quit", self)
        btn.clicked.connect(QtCore.QCoreApplication.instance().quit)
        btn.resize(100,50)
        btn.move(200,125)
        self.show()
def run():
    app = QtGui.QApplication(sys.argv)
    GUI = Window()
    sys.exit(app.exec_())

run()