#include "utilisationqt.h"
#include <vector>
#include <iostream>
#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "ajouterpromenadegui.h"
#include "ajoutercamiongui.h"
#include "supprimervehiculegui.h"
#include "VehiculeException.h"
#include "Camion.h"
#include <QMessageBox>
#include <QTextStream>


using namespace std;
using namespace saaq;
Proprietaire proprietaire1("Gabriel", "Chabot");


UtilisationQt::UtilisationQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
}

UtilisationQt::~UtilisationQt()
{

}

void UtilisationQt::dialogAjouterPromenade()
{
	AjouterPromenadeGui saisiePromenade(this);
	if(saisiePromenade.exec()){
		ajouterPromenade(saisiePromenade.reqNiv().toStdString(),
				saisiePromenade.reqImmatriculation().toStdString(),
				saisiePromenade.reqNbPlaces().toInt());
	}
}

void UtilisationQt::ajouterPromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces)
{

	try{
		VehiculePromenade objet(p_niv, p_immatriculation, p_nbPlaces);
		proprietaire1.ajouterVehicule(objet);
		cout << proprietaire1.reqProprietaireFormate() << endl;
		ui.textBrowser->setText(proprietaire1.reqProprietaireFormate().c_str());

	} catch	(VehiculeDejaPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void UtilisationQt::dialogAjouterCamion()
{
	AjouterCamionGui saisieCamion(this);
	if(saisieCamion.exec()){
		ajouterCamion(saisieCamion.reqNiv().toStdString(),
				saisieCamion.reqImmatriculation().toStdString(),
				saisieCamion.reqPoids().toInt(),
				saisieCamion.reqNbEssieux().toInt());
		}
}

void UtilisationQt::ajouterCamion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux)
{

	try{
		Camion objet(p_niv, p_immatriculation, p_poids, p_nbEssieux);
		proprietaire1.ajouterVehicule(objet);
		cout << proprietaire1.reqProprietaireFormate() << endl;
		ui.textBrowser->setText(proprietaire1.reqProprietaireFormate().c_str());

	} catch	(VehiculeDejaPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void UtilisationQt::dialogSupprimerVehicule()
{
	SupprimerVehiculeGui saisieSupprimer(this);
	if(saisieSupprimer.exec()){
		supprimerVehicule(saisieSupprimer.reqNiv().toStdString());

	}
}

void UtilisationQt::supprimerVehicule(const std::string& p_niv)
{
	try{
		proprietaire1.supprimerVehicule(p_niv);
		cout << proprietaire1.reqProprietaireFormate() << endl;
		ui.textBrowser->setText(proprietaire1.reqProprietaireFormate().c_str());

	} catch(VehiculeAbsentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

	/*try{
		//Creation de mon employe commission
		VehiculePromenade vehiculepromenade(p_niv, p_immatriculation, p_nbPlaces);
		if (verifiePresenceEmploye(employeCommis))
			throw EmployeDejaPresentException("Impossible d'ajouter cet employe, il est deja inscrit");
		m_vEmploye.push_back(new EmployeCommission(employeCommis));//ajout de l'employe dans la liste
	} catch (EmployeDejaPresentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}*/

