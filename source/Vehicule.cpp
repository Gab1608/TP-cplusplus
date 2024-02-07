/*
 * Vehicule.cpp
 *
 *  Created on: 2019-10-15
 *      Author: Gabriel Chabot
 */

#include "Vehicule.h"
#include "validationFormat.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace saaq
{

/**
 * \brief constructeur avec paramètres.
 * \param[in] p_niv un string représentant le numéro de série
 * \param[in] p_immatriculation un string représentant le numéro de plaque d'immatriculation
 * \pre p_niv n'est pas nul et respecte le format donné par util::validerNiv()
 * \pre p_immatriculation n'est pas nul et respecte le format donné par util::validerImmatriculationPromenade()
 * 	ou util::validerImmatriculationCamion
 * \post m_niv prend la valeur de p_niv
 * \post m_immatriculation prend la valeur de p_immatriculation
 */

Vehicule::Vehicule(const std::string& p_niv,
		const std::string& p_immatriculation) {
	PRECONDITION(!(p_niv.empty()) && util::validerNiv(p_niv));
	PRECONDITION(!(p_immatriculation.empty()) && (util::validerImmatriculationPromenade(p_immatriculation)
												|| util::validerImmatriculationCamion(p_immatriculation)));

	util::Date d0;
	m_dateEnregistrement = d0;
	m_niv = p_niv;
	m_immatriculation = p_immatriculation;

	POSTCONDITION(m_niv == p_niv);
	POSTCONDITION(m_immatriculation == p_immatriculation);

	INVARIANTS();
}

/**
 * \brief destructeur (n'est pas utilisé dans ce TP)
 */
Vehicule::~Vehicule() {

}

/**
 * \brief fonction accesseur récupérant le numéro de série du véhicule.
 * \return le numéro de série du véhicule
 */
const std::string& Vehicule::reqNiv() const {
	return m_niv;
}

/**
 * \brief fonction accesseur récupérant le numéro de la plaque d'immatriculation du véhicule.
 * \return le numéro de la plaque d'immatriculation du véhicule
 */
const std::string& Vehicule::reqImmatriculation() const {
	return m_immatriculation;
}

/**
 * \brief fonction accesseur récupérant la date d'enregistrement du véhicule.
 * \return la date d'enregistrement du véhicule
 */
const util::Date& Vehicule::reqDateEnregistrement() const {
	return m_dateEnregistrement;
}

/**
 * \brief assigne l'attribut de la plaque d'immatriculation avec la valeur passée en paramètre
 * \param[in] p_immatriculation respectant la fonction validerImmatriculation
 */
void Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
	PRECONDITION(!(p_immatriculation.empty()) && (util::validerImmatriculationPromenade(p_immatriculation)
												|| util::validerImmatriculationCamion(p_immatriculation)));

	m_immatriculation = p_immatriculation;

	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();
}

/**
 * \brief méthode retournant une chaine contenant l'ensemble des attributs formatés.
 * \return un objet string
 */
std::string Vehicule::reqVehiculeFormate() const{
	ostringstream os;
		os << "Numero de serie : " << m_niv << endl << "Numero d'immatriculation : "
				<< m_immatriculation << endl << "Date d'enregistrement : " << m_dateEnregistrement.reqDateFormatee()
				<< endl;
		return os.str();
}

/**
 * \brief surcharge de l’opérateur == permettant de comparer deux objets Vehicule et de vérifier s'il sont pareils.
 * \param[in] p_e un objet Vehicule qui est comparé au premier objet
 * \return un booléen permettant de savoir si les deux objets sont pareils
 */
bool Vehicule::operator ==(const Vehicule& p_e) const {
	if (m_niv == p_e.m_niv && m_immatriculation == p_e.m_immatriculation && m_dateEnregistrement == p_e.m_dateEnregistrement)
		return true;
	else
		return false;
}

/**
 * \brief Vérifie les invariants de la classe
 */
void Vehicule::verifieInvariant() const
{
	INVARIANT(!(m_niv.empty()));
	INVARIANT(!(m_immatriculation.empty()));

}

} //namespace saaq
