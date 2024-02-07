/********************************************************************************
** Form generated from reading UI file 'utilisationqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILISATIONQT_H
#define UI_UTILISATIONQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UtilisationQtClass
{
public:
    QAction *actionQuitter;
    QAction *actionPromenade;
    QAction *actionCamion;
    QAction *actionSupprimer_V_hicule;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAjouter_V_hicule;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UtilisationQtClass)
    {
        if (UtilisationQtClass->objectName().isEmpty())
            UtilisationQtClass->setObjectName(QString::fromUtf8("UtilisationQtClass"));
        UtilisationQtClass->resize(800, 600);
        actionQuitter = new QAction(UtilisationQtClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionPromenade = new QAction(UtilisationQtClass);
        actionPromenade->setObjectName(QString::fromUtf8("actionPromenade"));
        actionCamion = new QAction(UtilisationQtClass);
        actionCamion->setObjectName(QString::fromUtf8("actionCamion"));
        actionSupprimer_V_hicule = new QAction(UtilisationQtClass);
        actionSupprimer_V_hicule->setObjectName(QString::fromUtf8("actionSupprimer_V_hicule"));
        centralwidget = new QWidget(UtilisationQtClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 40, 551, 491));
        UtilisationQtClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UtilisationQtClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAjouter_V_hicule = new QMenu(menuFile);
        menuAjouter_V_hicule->setObjectName(QString::fromUtf8("menuAjouter_V_hicule"));
        UtilisationQtClass->setMenuBar(menubar);
        statusbar = new QStatusBar(UtilisationQtClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UtilisationQtClass->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuitter);
        menuFile->addAction(menuAjouter_V_hicule->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSupprimer_V_hicule);
        menuAjouter_V_hicule->addAction(actionPromenade);
        menuAjouter_V_hicule->addAction(actionCamion);

        retranslateUi(UtilisationQtClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), UtilisationQtClass, SLOT(close()));
        QObject::connect(actionPromenade, SIGNAL(triggered()), UtilisationQtClass, SLOT(dialogAjouterPromenade()));
        QObject::connect(actionCamion, SIGNAL(triggered()), UtilisationQtClass, SLOT(dialogAjouterCamion()));
        QObject::connect(actionSupprimer_V_hicule, SIGNAL(triggered()), UtilisationQtClass, SLOT(dialogSupprimerVehicule()));

        QMetaObject::connectSlotsByName(UtilisationQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *UtilisationQtClass)
    {
        UtilisationQtClass->setWindowTitle(QApplication::translate("UtilisationQtClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("UtilisationQtClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionPromenade->setText(QApplication::translate("UtilisationQtClass", "Promenade", 0, QApplication::UnicodeUTF8));
        actionCamion->setText(QApplication::translate("UtilisationQtClass", "Camion", 0, QApplication::UnicodeUTF8));
        actionSupprimer_V_hicule->setText(QApplication::translate("UtilisationQtClass", "Supprimer V\303\251hicule", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("UtilisationQtClass", "File", 0, QApplication::UnicodeUTF8));
        menuAjouter_V_hicule->setTitle(QApplication::translate("UtilisationQtClass", "Ajouter V\303\251hicule", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UtilisationQtClass: public Ui_UtilisationQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILISATIONQT_H
