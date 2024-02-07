/*
 * Vehicule.h
 *
 *  Created on: 2019-10-15
 *      Author: Gabriel Chabot
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <string>
#include "Date.h"
#include "ContratException.h"

namespace saaq
{
/**
 * \class Vehicule
 * \brief Classe implémentant le concept de vehicule
 *
 * La classe Vehicule permet d'implanter le concept de vehicule
 *
 * Attributs:
 * 		string 	m_niv: 		            Le numéro de série du véhicule
 * 		string 	m_immatriculation:		Le numéro de plaque d'immatriculation du véhicule
 */


class Vehicule {
public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
	virtual ~Vehicule();
	virtual Vehicule* clone() const=0;
	virtual double tarificationAnnuelle() const =0;

	const std::string& reqNiv() const;
	const std::string& reqImmatriculation() const;
	const util::Date& reqDateEnregistrement() const;
	//void asgImmatriculation(const std::string& p_immatriculation);
	virtual std::string reqVehiculeFormate() const;
	bool operator==( const Vehicule& ) const;

protected:
	void asgImmatriculation(const std::string& p_immatriculation);



private:
	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;
	void verifieInvariant() const;

};

} //namespace saaq

#endif /* VEHICULE_H_ */
