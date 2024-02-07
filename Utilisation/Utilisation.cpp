/*
 * Utilisation.cpp
 *
 *  Created on: 2019-11-26
 *      Author: etudiant
 */

#include <iostream>
#include "Vehicule.h"
#include "validationFormat.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"

using namespace std;
using namespace saaq;
using namespace util;

int main()
{
	//Variables nécessaires pour stocker les données entrées par l'utilisateur
	string numeroSeriePromenade;
	string numeroImmatriculationPromenade;
	int nombrePlaces;
	string numeroSerieCamion;
	string numeroImmatriculationCamion;
	int poids;
	int nombreEssieux;

	cout << "*******************************************************\n\nBienvenue a l'outil d'ajout de gestion "
			"de vehicule\n\n*******************************************************\n\n"; //Titre du programme

	cout << "-------------------------------------------------------\nAjouter un vehicule de promenade\n"
			"-------------------------------------------------------\n"; //Début de la section VehiculePromenade

	do
	{
		cout << "\nEntrez le numero de serie :" << endl;
		std::getline(std::cin, numeroSeriePromenade);
		if (!validerNiv(numeroSeriePromenade))
		{
			cout << "Ce numero de serie n'est pas valide"<< endl;
		}
	} while (!validerNiv(numeroSeriePromenade)); //Boucle qui continue jusqu'à ce que l'utilisateur
												 //entre un bon numéro de série

	do
	{
		cout << "\nEntrez le numero d'immatriculation :" << endl;
		std::getline(std::cin, numeroImmatriculationPromenade);
		if (!validerImmatriculationPromenade(numeroImmatriculationPromenade))
		{
			cout << "Ce numero d'immatriculation n'est pas valide"<< endl;
		}
	} while (!validerImmatriculationPromenade(numeroImmatriculationPromenade)); //Boucle qui continue jusqu'à ce que l'utilisateur
																				//entre un bon numéro d'immatriculation

	do
	{
		string nombrePlacesStr;
		cout << "\nEntrez le nombre de places > 0 :" << endl;
		std::getline(std::cin, nombrePlacesStr);
		nombrePlaces = std::stoi(nombrePlacesStr);
		if (nombrePlaces <= 0)
		{
			cout << "Le nombre de places n'est pas valide" << endl;
		}
	} while (nombrePlaces <= 0); //Boucle qui continue jusqu'à ce que l'utilisateur
	    						 //entre un bon nombre de places

	cout << "-------------------------------------------------------\nAjouter un camion\n"
			"-------------------------------------------------------\n"; //Début de la section Camion

	do
	{
		cout << "\nEntrez le numero de serie :" << endl;
		std::getline(std::cin, numeroSerieCamion);
		if (!validerNiv(numeroSerieCamion))
		{
			cout << "Ce numero de serie n'est pas valide"<< endl;
		}
	} while (!validerNiv(numeroSerieCamion)); //Boucle qui continue jusqu'à ce que l'utilisateur
											  //entre un bon numéro de série

	do
	{
		cout << "\nEntrez le numero d'immatriculation :" << endl;
		std::getline(std::cin, numeroImmatriculationCamion);
		if (!validerImmatriculationCamion(numeroImmatriculationCamion))
		{
			cout << "Ce numero d'immatriculation n'est pas valide"<< endl;
		}
	} while (!validerImmatriculationCamion(numeroImmatriculationCamion)); //Boucle qui continue jusqu'à ce que l'utilisateur
																		  //entre un bon numéro d'immatriculation

	do
	{
		string poidsStr;
		cout << "\nEntrez le poids du camion > 3000 kg :" << endl;
		std::getline(std::cin, poidsStr);
		poids = std::stoi(poidsStr);
		if (poids <= 3000)
		{
			cout << "Le poids du camion n'est pas valide" << endl;
		}
	} while (poids <= 3000); //Boucle qui continue jusqu'à ce que l'utilisateur
							 //entre un bon poids

	do
	{
		string nombreEssieuxStr;
		cout << "\nEntrez le nombre d'essieux >= 2 :" << endl;
		std::getline(std::cin, nombreEssieuxStr);
		nombreEssieux = std::stoi(nombreEssieuxStr);
		if (nombreEssieux < 2)
		{
			cout << "Le nombre d'essieux n'est pas valide" << endl;
		}
	} while (nombreEssieux < 2); //Boucle qui continue jusqu'à ce que l'utilisateur
								 //entre un bon nombre d'essieux

	Proprietaire proprietaire1("Chabot", "Gabriel"); //Création d'un objet Proprietaire
	VehiculePromenade vehiculePromenade1(numeroSeriePromenade, numeroImmatriculationPromenade, nombrePlaces); //Création d'un objet VehiculePromenade
	Camion camion1(numeroSerieCamion, numeroImmatriculationCamion, poids, nombreEssieux); //Création d'un objet Camion

	proprietaire1.ajouterVehicule(vehiculePromenade1); //Ajouter l'objet VehiculePromenade dans l'objet Proprietaire
	proprietaire1.ajouterVehicule(camion1); //Ajouter l'objet Camion dans l'objet Proprietaire

	cout << "\n" << proprietaire1.reqProprietaireFormate() << endl; //Montre l'objet Proprietaire et les objets Vehicule qui l'appartient

	return 0;
}

