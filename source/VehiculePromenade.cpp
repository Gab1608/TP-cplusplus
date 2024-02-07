/*
 * VehiculePromenade.cpp
 *
 *  Created on: 2019-11-24
 *      Author: etudiant
 */

#include "VehiculePromenade.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>

using namespace std;

namespace saaq
{

/**
 * \brief constructeur avec paramètres.
 * \param[in] p_niv un string représentant le numéro de série
 * \param[in] p_immatriculation un string représentant le numéro de plaque d'immatriculation
 * \param[in] p_nbPlaces un int représentant le nombre de places
 * \pre p_niv n'est pas nul et respecte le format donné par util::validerNiv()
 * \pre p_immatriculation n'est pas nul et respecte le format donné par util::validerImmatriculationPromenade()
 * \pre p_nbPlaces est strictement plus grand que zéro
 * \post m_niv prend la valeur de p_niv
 * \post m_immatriculation prend la valeur de p_immatriculation
 * \post m_nbPlaces prend la valeur de p_nbPlaces
 */

VehiculePromenade::VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces) :
		Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces)
{
	PRECONDITION(util::validerImmatriculationPromenade(p_immatriculation));
	PRECONDITION(p_nbPlaces > 0);

	POSTCONDITION(m_nbPlaces == p_nbPlaces)

	INVARIANTS();

}

/**
 * \brief fonction accesseur récupérant le nombre de places du véhicule.
 * \return le nombre de places du véhicule
 */
int VehiculePromenade::reqNbPlaces() const
{
	return m_nbPlaces;
}

/*void VehiculePromenade::asgImmatriculation(const std::string& p_immatriculation) {
	PRECONDITION(!(p_immatriculation.empty()) && (util::validerImmatriculationPromenade(p_immatriculation)));

	m_immatriculation = p_immatriculation;

	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();
}*/

/**
 * \brief fonction retournant la tarification annuelle de l'immatriculation du véhicule.
 * \return la tarification annuelle de l'immatriculation du véhicule
 */
double VehiculePromenade::tarificationAnnuelle() const
{
	double tarificationPromenade = 224.04;
	return tarificationPromenade;
}

/**
 * \brief crée un clone de l'objet
 * \return un objet de type Proprietaire::VehiculePromenade qui possède les mêmes propriétés que l'objet initial.
 */
Vehicule* VehiculePromenade::clone() const
{
	return new VehiculePromenade(*this);
}

/**
 * \brief méthode retournant une chaine contenant l'ensemble des attributs formatés.
 * \return un objet string
 */
std::string VehiculePromenade::reqVehiculeFormate() const
{
	std::ostringstream oss;
	oss << Vehicule::reqVehiculeFormate() << "nombre de places : " << reqNbPlaces() << endl
	        << "tarif : " << tarificationAnnuelle() << "$" << endl;
	return oss.str();
}

/**
 * \brief Vérifie les invariants de la classe
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(m_nbPlaces > 0);

}

}

