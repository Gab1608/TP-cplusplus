/********************************************************************************
** Form generated from reading UI file 'ajoutercamiongui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERCAMIONGUI_H
#define UI_AJOUTERCAMIONGUI_H

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

class Ui_AjouterCamionGuiClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *leNiv;
    QLineEdit *leImma;
    QLineEdit *lePoids;
    QLineEdit *leEssieux;
    QPushButton *pushButtonOkay;

    void setupUi(QDialog *AjouterCamionGuiClass)
    {
        if (AjouterCamionGuiClass->objectName().isEmpty())
            AjouterCamionGuiClass->setObjectName(QString::fromUtf8("AjouterCamionGuiClass"));
        AjouterCamionGuiClass->resize(400, 300);
        label = new QLabel(AjouterCamionGuiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 101, 17));
        label_2 = new QLabel(AjouterCamionGuiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 101, 17));
        label_3 = new QLabel(AjouterCamionGuiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 53, 17));
        label_4 = new QLabel(AjouterCamionGuiClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 160, 111, 17));
        leNiv = new QLineEdit(AjouterCamionGuiClass);
        leNiv->setObjectName(QString::fromUtf8("leNiv"));
        leNiv->setGeometry(QRect(160, 40, 191, 27));
        leImma = new QLineEdit(AjouterCamionGuiClass);
        leImma->setObjectName(QString::fromUtf8("leImma"));
        leImma->setGeometry(QRect(160, 80, 191, 27));
        lePoids = new QLineEdit(AjouterCamionGuiClass);
        lePoids->setObjectName(QString::fromUtf8("lePoids"));
        lePoids->setGeometry(QRect(160, 120, 191, 27));
        leEssieux = new QLineEdit(AjouterCamionGuiClass);
        leEssieux->setObjectName(QString::fromUtf8("leEssieux"));
        leEssieux->setGeometry(QRect(160, 160, 191, 27));
        pushButtonOkay = new QPushButton(AjouterCamionGuiClass);
        pushButtonOkay->setObjectName(QString::fromUtf8("pushButtonOkay"));
        pushButtonOkay->setGeometry(QRect(150, 230, 80, 28));

        retranslateUi(AjouterCamionGuiClass);
        QObject::connect(pushButtonOkay, SIGNAL(clicked()), AjouterCamionGuiClass, SLOT(validerCamion()));

        QMetaObject::connectSlotsByName(AjouterCamionGuiClass);
    } // setupUi

    void retranslateUi(QDialog *AjouterCamionGuiClass)
    {
        AjouterCamionGuiClass->setWindowTitle(QApplication::translate("AjouterCamionGuiClass", "AjouterCamionGui", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjouterCamionGuiClass", "Num\303\251ro de s\303\251rie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AjouterCamionGuiClass", "Immatriculation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AjouterCamionGuiClass", "Poids", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AjouterCamionGuiClass", "Nombre d'essieux", 0, QApplication::UnicodeUTF8));
        pushButtonOkay->setText(QApplication::translate("AjouterCamionGuiClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjouterCamionGuiClass: public Ui_AjouterCamionGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERCAMIONGUI_H
