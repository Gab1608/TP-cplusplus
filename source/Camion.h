/*
 * Camion.h
 *
 *  Created on: 2019-11-25
 *      Author: etudiant
 */

#ifndef CAMION_H_
#define CAMION_H_

#include "Vehicule.h"
#include <string>

namespace saaq {

/**
 * \class Camion
 * \brief Classe implémentant le concept d'appartenance d'un camion à un propriétaire
 *
 * La classe Vehicule permet d'implanter le concept d'appartenance d'un camion à un propriétaire
 *
 * Attributs:
 * 		string 	m_niv: 		            Le numéro de série du véhicule
 * 		string 	m_immatriculation:		Le numéro de plaque d'immatriculation du véhicule
 * 		int     m_poids:                Le poids du véhicule
 * 		int     m_nbEssieux:            Le nombre d'essieux du véhicule
 */

class Camion: public Vehicule {
public:
	Camion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux);
	int reqPoids() const;
	int reqNbEssieux() const;
	void asgImmatriculation(const std::string& p_immatriculation);
	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;


private:
	int m_poids;
	int m_nbEssieux;
	void verifieInvariant() const;
};

} /* namespace saaq */

#endif /* CAMION_H_ */
