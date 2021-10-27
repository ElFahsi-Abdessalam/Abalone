/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *black;
    QLabel *white;
    QLabel *current;
    QPushButton *pushButton_2;
    QLabel *erreur;
    QLabel *endGame;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(712, 480);
        MainWindow->setMinimumSize(QSize(712, 480));
        MainWindow->setMaximumSize(QSize(712, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-20, 0, 571, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 210, 93, 41));
        black = new QLabel(centralwidget);
        black->setObjectName(QString::fromUtf8("black"));
        black->setGeometry(QRect(480, 50, 211, 20));
        white = new QLabel(centralwidget);
        white->setObjectName(QString::fromUtf8("white"));
        white->setGeometry(QRect(500, 340, 231, 21));
        current = new QLabel(centralwidget);
        current->setObjectName(QString::fromUtf8("current"));
        current->setGeometry(QRect(530, 170, 171, 16));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 270, 93, 28));
        erreur = new QLabel(centralwidget);
        erreur->setObjectName(QString::fromUtf8("erreur"));
        erreur->setGeometry(QRect(490, 150, 171, 20));
        endGame = new QLabel(centralwidget);
        endGame->setObjectName(QString::fromUtf8("endGame"));
        endGame->setGeometry(QRect(570, 350, 131, 91));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 712, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        black->setText(QString());
        white->setText(QString());
        current->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reset selection", nullptr));
        erreur->setText(QString());
        endGame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
