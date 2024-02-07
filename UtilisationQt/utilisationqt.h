#ifndef UTILISATIONQT_H
#define UTILISATIONQT_H

#include <QtGui/QMainWindow>
#include "ui_utilisationqt.h"
#include "Vehicule.h"
#include <vector>



class UtilisationQt : public QMainWindow
{
    Q_OBJECT


public:
    UtilisationQt(QWidget *parent = 0);
    ~UtilisationQt();
    void ajouterPromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
    void ajouterCamion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux);
    void supprimerVehicule(const std::string& p_niv);

private slots:
	//Ajouter un véhicule de promenade
	void dialogAjouterPromenade();
	void dialogAjouterCamion();
	void dialogSupprimerVehicule();

private:
    Ui::UtilisationQtClass ui;
};

#endif // UTILISATIONQT_H
