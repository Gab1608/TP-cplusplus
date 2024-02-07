#include "supprimervehiculegui.h"
#include <QtGui/QMessageBox>

SupprimerVehiculeGui::SupprimerVehiculeGui(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

SupprimerVehiculeGui::~SupprimerVehiculeGui()
{

}

QString SupprimerVehiculeGui::reqNiv() const{
	return ui.leNiv->text();
}

void SupprimerVehiculeGui::validerSupprimerVehicule(){
	if (!(util::validerNiv(ui.leNiv->text().toStdString()))){
		QString message("Le numéro de série ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	accept();
}
