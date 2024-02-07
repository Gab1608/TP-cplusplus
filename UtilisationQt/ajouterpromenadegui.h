#ifndef AJOUTERPROMENADEGUI_H
#define AJOUTERPROMENADEGUI_H

#include <QtGui/QDialog>
#include "ui_ajouterpromenadegui.h"
#include "validationFormat.h"

class AjouterPromenadeGui : public QDialog
{
    Q_OBJECT

public:
    AjouterPromenadeGui(QWidget *parent = 0);
    ~AjouterPromenadeGui();
    QString reqNiv() const;
    QString reqImmatriculation() const;
    QString reqNbPlaces() const;

private slots:
	void validerPromenade();

private:
    Ui::AjouterPromenadeGuiClass ui;
};

#endif // AJOUTERPROMENADEGUI_H
