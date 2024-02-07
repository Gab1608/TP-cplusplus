/*
 * Camion.cpp
 *
 *  Created on: 2019-11-25
 *      Author: etudiant
 */

#include "Camion.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>

using namespace std;

namespace saaq {

/**
 * \brief constructeur avec paramètres.
 * \param[in] p_niv un string représentant le numéro de série
 * \param[in] p_immatriculation un string représentant le numéro de plaque d'immatriculation
 * \param[in] p_poids un int représentant le poids du véhicule
 * \param[in] p_nbEssieux un int représentant le nombre d'essieux du véhicule
 * \pre p_niv n'est pas nul et respecte le format donné par util::validerNiv()
 * \pre p_immatriculation n'est pas nul et respecte le format donné par util::validerImmatriculationCamion
 * \pre p_poids est strictement plus grand que 3000 kg
 * \pre p_nbEssieux est plus grand ou égal à 2
 * \post m_niv prend la valeur de p_niv
 * \post m_immatriculation prend la valeur de p_immatriculation
 * \post m_poids prend la valeur de p_poids
 * \post m_nbEssieux prend la valeur de p_nbEssieux
 */

Camion::Camion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux) :
		Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
	PRECONDITION(util::validerImmatriculationCamion(p_immatriculation));
	PRECONDITION(p_poids > 3000);
	PRECONDITION(p_nbEssieux >= 2);

	POSTCONDITION(m_poids == p_poids);
	POSTCONDITION(m_nbEssieux == p_nbEssieux);

	INVARIANTS();

}

/**
 * \brief fonction accesseur récupérant le poids du véhicule.
 * \return le poids du véhicule
 */
int Camion::reqPoids() const
{
	return m_poids;
}

/**
 * \brief fonction accesseur récupérant le nombre d'essieux du véhicule.
 * \return le nombre d'essieux du véhicule
 */
int Camion::reqNbEssieux() const
{
	return m_nbEssieux;
}

/*void Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
	PRECONDITION(!(p_immatriculation.empty()) && (util::validerImmatriculationCamion(p_immatriculation)));

	m_immatriculation = p_immatriculation;

	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();
}*/

/**
 * \brief fonction retournant la tarification annuelle de l'immatriculation du véhicule.
 * \return la tarification annuelle de l'immatriculation du véhicule
 */
double Camion::tarificationAnnuelle() const
{
	double tarificationCamion;
	if ((m_poids >= 3001 && m_poids <= 4000) && m_nbEssieux == 2)
		tarificationCamion = 570.28;
	if (m_poids > 4000 && m_nbEssieux == 2)
		tarificationCamion = 905.28;
	if (m_nbEssieux == 3)
		tarificationCamion = 1566.19;
	if (m_nbEssieux == 4)
		tarificationCamion = 2206.19;
	if (m_nbEssieux == 5)
		tarificationCamion = 2821.76;
	if (m_nbEssieux >= 6)
		tarificationCamion = 3729.76;
	return tarificationCamion;
}

/**
 * \brief crée un clone de l'objet
 * \return un objet de type Proprietaire::Camion qui possède les mêmes propriétés que l'objet initial.
 */
Vehicule* Camion::clone() const
{
	return new Camion(*this);
}

/**
 * \brief méthode retournant une chaine contenant l'ensemble des attributs formatés.
 * \return un objet string
 */
std::string Camion::reqVehiculeFormate() const
{
	std::ostringstream oss;
	oss << Vehicule::reqVehiculeFormate() << "nombre d'essieux : " << reqNbEssieux() << endl
			<< "poids : " << reqPoids() << " kg" << endl << "tarif : " << tarificationAnnuelle() << "$" << endl;
	return oss.str();
}

/**
 * \brief Vérifie les invariants de la classe
 */
void Camion::verifieInvariant() const
{
	INVARIANT(m_poids > 3000);
	INVARIANT(m_nbEssieux >= 2);

}


} /* namespace saaq */
