import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class sliderdemo(QWidget):
    def __init__(self, parent=None):
        super(sliderdemo, self).__init__(parent)
            
        layout = QVBoxLayout()
        self.l1 = QLabel("Hello")
        self.l1.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.l1)

        self.sl = QSlider(Qt.Horizontal)
        self.sl.setMinimum(10)
        self.sl.setMaximum(20)
        self.sl.setValue(15)
        self.sl.setTickPosition(1)

        layout.addWidget(self.sl)
        self.sl.valueChanged.connect(self.valuechange)
        self.setLayout(layout)
        
        self.setWindowTitle("SliderBox demo")
        self.setGeometry(300,300,500,300)


    def valuechange(self):
        size = self.sl.value()
        self.l1.setFont(QFont("Arial", size))

            
def main():
   app = QApplication(sys.argv)
   ex  = sliderdemo()
   ex.show()
   sys.exit(app.exec_())
	
if __name__ == '__main__':
   main()