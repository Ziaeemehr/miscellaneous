import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

class menudemo(QMainWindow):
   def __init__(self, parent = None):
      super(menudemo, self).__init__(parent)
		
      layout = QHBoxLayout()
      bar = self.menuBar()
      file = bar.addMenu("File")
      file.addAction("New")
		
      save = QAction("Save",self)
      save.setShortcut("Ctrl+S")
      file.addAction(save)
		
      edit = file.addMenu("Edit")
      edit.addAction("copy")
      edit.addAction("paste")
		
      quit = QAction("Quit",self) 
      quit.setShortcut("Ctrl+Q")
      file.addAction(quit)
      file.triggered[QAction].connect(self.processtrigger)
    #   self.setLayout(layout)
      self.setWindowTitle("menu demo")
      self.setGeometry(300,300, 500, 200)
		
   def processtrigger(self,q):
      print q.text()+" is triggered"
      if q.text() == "Quit":
          sys.exit(0)
		
def main():
   app = QApplication(sys.argv)
   ex = menudemo()
   ex.show()
   sys.exit(app.exec_())
	
if __name__ == '__main__':
   main()