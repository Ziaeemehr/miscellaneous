import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class combobox(QWidget):
    def __init__(self, parent=None):
      super(combobox, self).__init__(parent)
		
      layout = QHBoxLayout()
      self.cb = QComboBox()
      self.cb.addItem("C")
      self.cb.addItem("C++")
      self.cb.addItems(["Java","C#","Python"])
      self.cb.currentIndexChanged.connect(self.selectionchange)
      layout.addWidget(self.cb)
      self.setLayout(layout)
      self.setWindowTitle("combo box demo")
      self.setGeometry(50,50,300,100)


    def selectionchange(self, i):
        print "Items in the list area :"

        for count in range(self.cb.count()):
            print self.cb.itemText(count)
        print "Current index", i, "selection changed ", self.cb.currentText()
            
def main():
   app = QApplication(sys.argv)
   ex  = combobox()
   ex.show()
   sys.exit(app.exec_())
	
if __name__ == '__main__':
   main()