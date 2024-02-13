/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonNext;
    QSlider *horizontalSliderProgress;
    QSlider *horizontalSliderVolume;
    QLabel *labelVolume;
    QLabel *labelFile;
    QLabel *labelDuration;
    QLabel *labelProgress;
    QTableView *tableViewPlaylist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 472);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ico/sound_icon-icons.com_74449.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonOpen = new QPushButton(centralwidget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(20, 400, 40, 24));
        pushButtonPrev = new QPushButton(centralwidget);
        pushButtonPrev->setObjectName(QString::fromUtf8("pushButtonPrev"));
        pushButtonPrev->setGeometry(QRect(70, 40, 40, 24));
        pushButtonPlay = new QPushButton(centralwidget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(120, 40, 40, 24));
        pushButtonPause = new QPushButton(centralwidget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(170, 40, 40, 24));
        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(220, 40, 40, 24));
        pushButtonNext = new QPushButton(centralwidget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(270, 40, 40, 24));
        horizontalSliderProgress = new QSlider(centralwidget);
        horizontalSliderProgress->setObjectName(QString::fromUtf8("horizontalSliderProgress"));
        horizontalSliderProgress->setGeometry(QRect(20, 100, 571, 16));
        horizontalSliderProgress->setOrientation(Qt::Horizontal);
        horizontalSliderVolume = new QSlider(centralwidget);
        horizontalSliderVolume->setObjectName(QString::fromUtf8("horizontalSliderVolume"));
        horizontalSliderVolume->setGeometry(QRect(420, 50, 171, 16));
        horizontalSliderVolume->setValue(70);
        horizontalSliderVolume->setOrientation(Qt::Horizontal);
        labelVolume = new QLabel(centralwidget);
        labelVolume->setObjectName(QString::fromUtf8("labelVolume"));
        labelVolume->setGeometry(QRect(470, 30, 81, 16));
        labelFile = new QLabel(centralwidget);
        labelFile->setObjectName(QString::fromUtf8("labelFile"));
        labelFile->setGeometry(QRect(20, 10, 581, 16));
        labelDuration = new QLabel(centralwidget);
        labelDuration->setObjectName(QString::fromUtf8("labelDuration"));
        labelDuration->setGeometry(QRect(496, 79, 91, 21));
        labelProgress = new QLabel(centralwidget);
        labelProgress->setObjectName(QString::fromUtf8("labelProgress"));
        labelProgress->setGeometry(QRect(20, 80, 181, 16));
        tableViewPlaylist = new QTableView(centralwidget);
        tableViewPlaylist->setObjectName(QString::fromUtf8("tableViewPlaylist"));
        tableViewPlaylist->setGeometry(QRect(20, 130, 571, 261));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MediaPlayerPD_321", nullptr));
        pushButtonOpen->setText(QString());
        pushButtonPrev->setText(QString());
        pushButtonPlay->setText(QString());
        pushButtonPause->setText(QString());
        pushButtonStop->setText(QString());
        pushButtonNext->setText(QString());
        labelVolume->setText(QCoreApplication::translate("MainWindow", "Volume:", nullptr));
        labelFile->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        labelDuration->setText(QCoreApplication::translate("MainWindow", "Duration:", nullptr));
        labelProgress->setText(QCoreApplication::translate("MainWindow", "Progress:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
