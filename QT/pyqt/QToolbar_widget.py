import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class tooldemo(QMainWindow):
   def __init__(self, parent = None):
      super(tooldemo, self).__init__(parent)
      layout = QVBoxLayout()
      tb = self.addToolBar("File")
		
      new = QAction(QIcon("new.png"),"new",self)
      tb.addAction(new)
		
      open = QAction(QIcon("open.png"),"open",self)
      tb.addAction(open)
      save = QAction(QIcon("save.png"),"save",self)
      tb.addAction(save)
      tb.actionTriggered[QAction].connect(self.toolbtnpressed)
    #   self.setLayout(layout)
      self.setWindowTitle("toolbar demo")
      self.setGeometry(300,300,500,200)
		
   def toolbtnpressed(self,a):
      print "pressed tool button is", a.text()
		
def main():
   app = QApplication(sys.argv)
   ex = tooldemo()
   ex.show()
   sys.exit(app.exec_())
	
if __name__ == '__main__':
   main()