import sys
from PyQt4 import QtCore, QtGui, uic

qtCreatorFile = "tempconv.ui" # Enter file here.

form_class, QtBaseClass = uic.loadUiType(qtCreatorFile)

class MyWindow(QtGui.QMainWindow, form_class):
    def __init__(self, parent=None):
        QtGui.QMainWindow.__init__(self,parent)
        self.setupUi(self)
        form_class.__init__(self)

        self.btn_CtoF.clicked.connect(self.btn_CtoF_clicked) # Bind the event handlers
        self.btn_FtoC.clicked.connect(self.btn_FtoC_clicked)

    def btn_CtoF_clicked(self):
        cel  = float(self.editCel.text())
        fahr = cel *9/5.0 + 32
        self.spinFahr.setValue(int(fahr+0.5))
    
    def btn_FtoC_clicked(self):
        fahr = self.spinFahr.value()
        cel  = (fahr - 32) * 5 / 9.0
        self.editCel.setText(str(cel))

app = QtGui.QApplication(sys.argv)
window = MyWindow(None)
window.show()
app.exec_()