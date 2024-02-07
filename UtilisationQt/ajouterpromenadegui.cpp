#include "ajouterpromenadegui.h"
#include <QtGui/QMessageBox>
#include "validationFormat.h"

AjouterPromenadeGui::AjouterPromenadeGui(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

AjouterPromenadeGui::~AjouterPromenadeGui()
{

}

QString AjouterPromenadeGui::reqNiv() const{
	return ui.leSerie->text();
}

QString AjouterPromenadeGui::reqImmatriculation() const{
	return ui.leImmatriculation->text();
}

QString AjouterPromenadeGui::reqNbPlaces() const{
	return ui.lePlaces->text();
}

void AjouterPromenadeGui::validerPromenade(){
	if (!(util::validerNiv(ui.leSerie->text().toStdString()))){
		QString message("Le numéro de série ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	if(!(util::validerImmatriculationPromenade(ui.leImmatriculation->text().toStdString()))){
		QString message("Le numéro d'immatriculation ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	if(ui.lePlaces->text().toInt() <= 0 || ui.lePlaces->text().isEmpty()){
		QString message("Le nombre de places ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	accept();
}
