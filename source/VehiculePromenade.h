/*
 * VehiculePromenade.h
 *
 *  Created on: 2019-11-24
 *      Author: etudiant
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include "Vehicule.h"
#include <string>

namespace saaq
{

/**
 * \class VehiculePromenade
 * \brief Classe implémentant le concept d'appartenance d'un vehicule de promenade à un propriétaire
 *
 * La classe VehiculePromenade permet d'implanter le concept d'appartenance d'un vehicule de promenade à un propriétaire
 *
 * Attributs:
 * 		string  m_niv: 		            Le numéro de série du véhicule
 * 		string 	m_immatriculation:		Le numéro de plaque d'immatriculation du véhicule
 * 		int     m_nbPlaces:             Le nombre de places du véhicule
 */

class VehiculePromenade: public Vehicule
{
public:
	VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
	int reqNbPlaces() const;
	void asgImmatriculation(const std::string& p_immatriculation);
	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;
private:
	int m_nbPlaces;
	void verifieInvariant() const;

};

} // namespace saaq

#endif /* VEHICULEPROMENADE_H_ */
