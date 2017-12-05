# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'pyqtdesigner.ui'
#
# Created by: PyQt5 UI code generator 5.5.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(406, 129)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.PushMe = QtWidgets.QPushButton(self.centralwidget)
        self.PushMe.setObjectName("PushMe")
        self.verticalLayout.addWidget(self.PushMe)
        self.OrMe = QtWidgets.QPushButton(self.centralwidget)
        self.OrMe.setObjectName("OrMe")
        self.verticalLayout.addWidget(self.OrMe)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.check3 = QtWidgets.QCheckBox(self.centralwidget)
        self.check3.setObjectName("check3")
        self.horizontalLayout.addWidget(self.check3)
        self.check1 = QtWidgets.QCheckBox(self.centralwidget)
        self.check1.setObjectName("check1")
        self.horizontalLayout.addWidget(self.check1)
        self.check4 = QtWidgets.QCheckBox(self.centralwidget)
        self.check4.setObjectName("check4")
        self.horizontalLayout.addWidget(self.check4)
        self.check2 = QtWidgets.QCheckBox(self.centralwidget)
        self.check2.setObjectName("check2")
        self.horizontalLayout.addWidget(self.check2)
        self.horizontalLayout_2.addLayout(self.horizontalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 406, 23))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        self.menuEdit = QtWidgets.QMenu(self.menubar)
        self.menuEdit.setObjectName("menuEdit")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionOpen = QtWidgets.QAction(MainWindow)
        self.actionOpen.setObjectName("actionOpen")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionExit = QtWidgets.QAction(MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionExit)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuEdit.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.PushMe.setText(_translate("MainWindow", "PushMe"))
        self.OrMe.setText(_translate("MainWindow", "Or Me"))
        self.check3.setText(_translate("MainWindow", "check3"))
        self.check1.setText(_translate("MainWindow", "check1"))
        self.check4.setText(_translate("MainWindow", "check4"))
        self.check2.setText(_translate("MainWindow", "check2"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.menuEdit.setTitle(_translate("MainWindow", "Edit"))
        self.actionOpen.setText(_translate("MainWindow", "Open"))
        self.actionSave.setText(_translate("MainWindow", "Save"))
        self.actionExit.setText(_translate("MainWindow", "Exit"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

