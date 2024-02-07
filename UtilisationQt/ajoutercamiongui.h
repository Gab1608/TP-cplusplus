#ifndef AJOUTERCAMIONGUI_H
#define AJOUTERCAMIONGUI_H

#include <QtGui/QDialog>
#include "ui_ajoutercamiongui.h"
#include "validationFormat.h"

class AjouterCamionGui : public QDialog
{
    Q_OBJECT

public:
    AjouterCamionGui(QWidget *parent = 0);
    ~AjouterCamionGui();
    QString reqNiv() const;
    QString reqImmatriculation() const;
    QString reqPoids() const;
    QString reqNbEssieux() const;

private slots:
	void validerCamion();

private:
    Ui::AjouterCamionGuiClass ui;
};

#endif // AJOUTERCAMIONGUI_H
