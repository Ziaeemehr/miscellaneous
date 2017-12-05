import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class spindemo(QWidget):
    def __init__(self, parent=None):
        super(spindemo, self).__init__(parent)
            
        layout = QVBoxLayout()
        self.l1 = QLabel("current value:")
        self.l1.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.l1)
        self.setLayout(layout)
        self.sp = QSpinBox()

        layout.addWidget(self.sp)
        self.sp.setRange(-100,100)
        self.sp.setSingleStep(5)
        self.sp.valueChanged.connect(self.valuechange)
        self.setLayout(layout)
        
        self.setWindowTitle("SpinBox demo")
        self.setGeometry(300,300,300,100)


    def valuechange(self):
        self.l1.setText("current value : "+str(self.sp.value()))

            
def main():
   app = QApplication(sys.argv)
   ex  = spindemo()
   ex.show()
   sys.exit(app.exec_())
	
if __name__ == '__main__':
   main()