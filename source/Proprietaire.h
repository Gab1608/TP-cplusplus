/*
 * Proprietaire.h
 *
 *  Created on: 2019-11-25
 *      Author: etudiant
 */

#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_

#include "Vehicule.h"

#include <string>
#include <vector>

namespace saaq {

/**
 * \class Proprietaire
 * \brief Classe implémentant le concept d'appartenance d'un vehicule à un propriétaire
 *
 * La classe Vehicule permet d'implanter le concept d'appartenance d'un vehicule à un propriétaire selon le type de véhicule
 *
 * Attributs:
 * 		string 	m_nom: 		    Le nom du propriétaire
 * 		string 	m_prenom:		Le prénom du propriétaire
 */

class Proprietaire {
public:
	Proprietaire(const std::string& p_nom, const std::string& p_prenom);
	~Proprietaire();
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	std::string reqProprietaireFormate() const;
	void ajouterVehicule(const Vehicule& p_nouveauVehicule);
	void supprimerVehicule (const std::string& p_niv);

private:
	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;
	bool VehiculeEstDejaPresent(const std::string& p_niv) const;
	void verifieInvariant() const;
};

} /* namespace saaq */

#endif /* PROPRIETAIRE_H_ */
