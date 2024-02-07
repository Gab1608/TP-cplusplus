/********************************************************************************
** Form generated from reading UI file 'supprimervehiculegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERVEHICULEGUI_H
#define UI_SUPPRIMERVEHICULEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerVehiculeGuiClass
{
public:
    QLabel *label;
    QLineEdit *leNiv;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *SupprimerVehiculeGuiClass)
    {
        if (SupprimerVehiculeGuiClass->objectName().isEmpty())
            SupprimerVehiculeGuiClass->setObjectName(QString::fromUtf8("SupprimerVehiculeGuiClass"));
        SupprimerVehiculeGuiClass->resize(400, 300);
        label = new QLabel(SupprimerVehiculeGuiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 101, 17));
        leNiv = new QLineEdit(SupprimerVehiculeGuiClass);
        leNiv->setObjectName(QString::fromUtf8("leNiv"));
        leNiv->setGeometry(QRect(140, 70, 221, 27));
        pushButtonOK = new QPushButton(SupprimerVehiculeGuiClass);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(150, 200, 80, 28));

        retranslateUi(SupprimerVehiculeGuiClass);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), SupprimerVehiculeGuiClass, SLOT(validerSupprimerVehicule()));

        QMetaObject::connectSlotsByName(SupprimerVehiculeGuiClass);
    } // setupUi

    void retranslateUi(QDialog *SupprimerVehiculeGuiClass)
    {
        SupprimerVehiculeGuiClass->setWindowTitle(QApplication::translate("SupprimerVehiculeGuiClass", "SupprimerVehiculeGui", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SupprimerVehiculeGuiClass", "Num\303\251ro de s\303\251rie", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("SupprimerVehiculeGuiClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupprimerVehiculeGuiClass: public Ui_SupprimerVehiculeGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERVEHICULEGUI_H
