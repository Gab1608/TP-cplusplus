/*
 * Proprietaire.cpp
 *
 *  Created on: 2019-11-25
 *      Author: etudiant
 */

#include "Proprietaire.h"
#include "ContratException.h"
#include "VehiculeException.h"

#include <sstream>
#include <vector>


namespace saaq {

/**
 * \brief constructeur avec paramètres.
 * \param[in] p_nom un string représentant le nom du propriétaire
 * \param[in] p_prenom un string représentant le prénom du propriétaire
 * \pre p_nom n'est pas nul
 * \pre p_prenom n'est pas nul
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 * \post m_vVehicules est vide
 */
Proprietaire::Proprietaire(const std::string& p_nom, const std::string& p_prenom) :
	m_nom(p_nom), m_prenom(p_prenom)
{
	PRECONDITION(!(p_nom.empty()));
	PRECONDITION(!(p_prenom.empty()));

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	INVARIANTS();

}

/**
 * \brief destructeur
 */
Proprietaire::~Proprietaire() {
	std::vector<Vehicule*>::iterator it;
	for(it = m_vVehicules.begin(); it < m_vVehicules.end(); it++){
			it = m_vVehicules.erase(it);
		}
}

/**
 * \brief ajoute un véhicule au propriétaire
 * \param[in] p_nouveauVehicule
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
{
	//Creation d'un véhicule d'une classe voulue
	Vehicule* veh = p_nouveauVehicule.clone();
	if (VehiculeEstDejaPresent(veh->reqNiv())){
		throw VehiculeDejaPresentException("Impossible d'ajouter ce véhicule, il existe déjà");
	}
	m_vVehicules.push_back(veh);//ajout du véhicule dans la liste


	//PRECONDITION(!(VehiculeEstDejaPresent(veh->reqNiv())));

	//POSTCONDITION(VehiculeEstDejaPresent(veh->reqNiv()));
	//INVARIANTS();
}

/**
 * \brief supprime un véhicule au propriétaire
 * \param[in] p_niv
 */
void Proprietaire::supprimerVehicule (const std::string& p_niv)
{
	if (!VehiculeEstDejaPresent(p_niv)){
		throw VehiculeAbsentException("Impossible de supprimer un véhicule qui n'existe pas dans la "
				"liste");
	}
	std::vector<Vehicule*>::iterator it;
	for(it = m_vVehicules.begin(); it < m_vVehicules.end(); it++){
		if((*it)->reqNiv() == p_niv){
			delete (*it);
			it = m_vVehicules.erase(it);
		}
	}

}

/**
 * \brief méthode retournant une chaine contenant l'ensemble des attributs formatés.
 * \return un objet string
 */
std::string Proprietaire::reqProprietaireFormate() const /*à revenir!!!!!*/
{
	std::ostringstream oss;
	oss << "Proprietaire" << "\n" << "-------------------" << "\n" << "Nom     : " << reqNom() << "\n" << "Prenom  : " << reqPrenom()<< "\n";
	for (unsigned int i = 1; i <= m_vVehicules.size(); i++)
	{
		oss << "-------------------" << "\n"
		        << m_vVehicules[i - 1]->reqVehiculeFormate() << "";
	}
	return oss.str();
}

/**
 * \brief vérifie si le véhicule appartient déjà à un propriétaire en vérifiant si le numéro de série
 * appartient déjà à un des véhicules du propriétaire.
 * \param[in] p_niv le string du numéro de série du véhicule à vérifier.
 * @return
 */
bool Proprietaire::VehiculeEstDejaPresent(
        const std::string& p_niv) const
{
	bool vehiculePresent = false;
	std::vector<Vehicule *>::const_iterator it;
	for(it = m_vVehicules.begin(); it < m_vVehicules.end(); it++){
		if ((*it)->reqNiv() == p_niv)
			vehiculePresent = true;
	}

	return vehiculePresent;

}

/**
 * \brief fonction accesseur récupérant le nom du propriétaire.
 * \return le nom du propriétaire
 */
const std::string& Proprietaire::reqNom() const
{
	return m_nom;
}

/**
 * \brief fonction accesseur récupérant le prénom du propriétaire.
 * \return le prénom du propriétaire
 */
const std::string& Proprietaire::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Vérifie les invariants de la classe
 */
void Proprietaire::verifieInvariant() const
{
	INVARIANT(!(m_nom.empty()));
	INVARIANT(!(m_prenom.empty()));
}

} /* namespace saaq */
