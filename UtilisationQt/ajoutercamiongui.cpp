#include "ajoutercamiongui.h"
#include <QtGui/QMessageBox>

AjouterCamionGui::AjouterCamionGui(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

AjouterCamionGui::~AjouterCamionGui()
{

}

QString AjouterCamionGui::reqNiv() const{
	return ui.leNiv->text();
}

QString AjouterCamionGui::reqImmatriculation() const{
	return ui.leImma->text();
}

QString AjouterCamionGui::reqPoids() const{
	return ui.lePoids->text();
}

QString AjouterCamionGui::reqNbEssieux() const{
	return ui.leEssieux->text();
}

void AjouterCamionGui::validerCamion(){
	if (!(util::validerNiv(ui.leNiv->text().toStdString()))){
		QString message("Le numéro de série ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	if(!(util::validerImmatriculationCamion(ui.leImma->text().toStdString()))){
		QString message("Le numéro d'immatriculation ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	if(ui.lePoids->text().toInt() <= 3000 || ui.lePoids->text().isEmpty()){
		QString message("Le poids ne doit pas etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}

	if(ui.leEssieux->text().toInt() < 2 || ui.leEssieux->text().isEmpty()){
			QString message("Le nombre d'essieux ne doit pas etre valide");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}
	accept();
}
