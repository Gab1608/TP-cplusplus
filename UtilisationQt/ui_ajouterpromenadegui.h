/********************************************************************************
** Form generated from reading UI file 'ajouterpromenadegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERPROMENADEGUI_H
#define UI_AJOUTERPROMENADEGUI_H

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

class Ui_AjouterPromenadeGuiClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leSerie;
    QLineEdit *leImmatriculation;
    QLineEdit *lePlaces;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *AjouterPromenadeGuiClass)
    {
        if (AjouterPromenadeGuiClass->objectName().isEmpty())
            AjouterPromenadeGuiClass->setObjectName(QString::fromUtf8("AjouterPromenadeGuiClass"));
        AjouterPromenadeGuiClass->resize(400, 300);
        label = new QLabel(AjouterPromenadeGuiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 101, 17));
        label_2 = new QLabel(AjouterPromenadeGuiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 101, 17));
        label_3 = new QLabel(AjouterPromenadeGuiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 111, 17));
        leSerie = new QLineEdit(AjouterPromenadeGuiClass);
        leSerie->setObjectName(QString::fromUtf8("leSerie"));
        leSerie->setGeometry(QRect(150, 30, 181, 27));
        leImmatriculation = new QLineEdit(AjouterPromenadeGuiClass);
        leImmatriculation->setObjectName(QString::fromUtf8("leImmatriculation"));
        leImmatriculation->setGeometry(QRect(150, 70, 181, 27));
        lePlaces = new QLineEdit(AjouterPromenadeGuiClass);
        lePlaces->setObjectName(QString::fromUtf8("lePlaces"));
        lePlaces->setGeometry(QRect(150, 110, 181, 27));
        pushButtonOK = new QPushButton(AjouterPromenadeGuiClass);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(140, 210, 80, 28));

        retranslateUi(AjouterPromenadeGuiClass);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), AjouterPromenadeGuiClass, SLOT(validerPromenade()));

        QMetaObject::connectSlotsByName(AjouterPromenadeGuiClass);
    } // setupUi

    void retranslateUi(QDialog *AjouterPromenadeGuiClass)
    {
        AjouterPromenadeGuiClass->setWindowTitle(QApplication::translate("AjouterPromenadeGuiClass", "AjouterPromenadeGui", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjouterPromenadeGuiClass", "Num\303\251ro de s\303\251rie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AjouterPromenadeGuiClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AjouterPromenadeGuiClass", "Nombre de places", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("AjouterPromenadeGuiClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjouterPromenadeGuiClass: public Ui_AjouterPromenadeGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERPROMENADEGUI_H
