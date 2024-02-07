/*
 * Proprietaire_Testeur.cpp
 *
 *  Created on: 2019-11-26
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Proprietaire.h"
#include "Camion.h"
#include "VehiculePromenade.h"
using namespace std;
using namespace saaq;

/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Vehicule et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Nom vide
 *		    Prenom vide
 */
TEST(Proprietaire, Constructeur)
{
	Proprietaire UnProprietaire("Chabot", "Gabriel");

	ASSERT_EQ("Chabot", UnProprietaire.reqNom());
	ASSERT_EQ("Gabriel", UnProprietaire.reqPrenom());
}

//cas invalides
TEST(Proprietaire,ConstructeurInvalideNom)
{
	ASSERT_THROW(Proprietaire UnProprietaire("", "Gabriel"),ContratException);

}

TEST(Proprietaire,ConstructeurInvalidePrenom)
{
	ASSERT_THROW(Proprietaire UnProprietaire("Chabot", ""),ContratException);

}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnProprietaire: public ::testing::Test
{
public:
	UnProprietaire() :
		proprietaire1("Marois", "Nicolas"),
		VehiculePromenade1("3VWFE21C04M000001", "IFT 006", 5),
		VehiculePromenade2("1ZVBP8CHXA5100001", "GLI 200", 7),
		Camion1("1HGBH41JXMN109186", "L123456", 4500, 4),
		Camion2("1HTMKADN43H561298", "L987654", 3100, 2)
	{}
	;
	Proprietaire proprietaire1;
	VehiculePromenade VehiculePromenade1;
	VehiculePromenade VehiculePromenade2;
	Camion Camion1;
	Camion Camion2;

};

/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour du nom du propriétaire.
 *     Cas invalide: aucun.
 */
TEST_F(UnProprietaire, reqNom)
{
	ASSERT_EQ("Marois", proprietaire1.reqNom());
}

/**
 * \test Test de la méthode reqPrenom()
 *
 *     Cas valide: vérifier le retour du prénom du propriétaire.
 *     Cas invalide: aucun.
 */
TEST_F(UnProprietaire, reqPrenom)
{
	ASSERT_EQ("Nicolas", proprietaire1.reqPrenom());
}

/**
 * \test Test de la méthode ajouterVehicule();
 *
 *        Cas valides: vérifier le retour des information sur le vecteur m_vVehicules en utilisant reqProprietaireFormate
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, ajouterVehicule)
{
	ASSERT_EQ("Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n",
	        proprietaire1.reqProprietaireFormate());
	proprietaire1.ajouterVehicule(VehiculePromenade1);
	proprietaire1.ajouterVehicule(VehiculePromenade2);
	proprietaire1.ajouterVehicule(Camion1);
	std::ostringstream oss;
	oss << "Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n" << "-------------------\n"
	        << VehiculePromenade1.reqVehiculeFormate() << "-------------------\n"
	        << VehiculePromenade2.reqVehiculeFormate() << "-------------------\n"
	        << Camion1.reqVehiculeFormate();
	ASSERT_EQ(oss.str(), proprietaire1.reqProprietaireFormate());
}

/**
 * \test Test de la méthode supprimerVehicule();
 *
 *        Cas valides: vérifier le retour des information sur le vecteur m_vVehicules en utilisant reqProprietaireFormate
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, supprimerVehicule)
{
	ASSERT_EQ("Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n",
	        proprietaire1.reqProprietaireFormate());
	proprietaire1.ajouterVehicule(VehiculePromenade1);
	proprietaire1.ajouterVehicule(VehiculePromenade2);
	proprietaire1.ajouterVehicule(Camion1);
	proprietaire1.supprimerVehicule("3VWFE21C04M000001");
	std::ostringstream oss;
	oss << "Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n" << "-------------------\n"
	        << VehiculePromenade2.reqVehiculeFormate() << "-------------------\n"
	        << Camion1.reqVehiculeFormate();
	ASSERT_EQ(oss.str(), proprietaire1.reqProprietaireFormate());
}

/**
 * \test Test de la méthode std::string reqProprietaireFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Proprietaire formaté
 *        Cas invalides: aucun
 */
TEST_F(UnProprietaire, reqProprietaireFormate)
{
	ASSERT_EQ("Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n",
	        proprietaire1.reqProprietaireFormate());
	proprietaire1.ajouterVehicule(VehiculePromenade1);
	proprietaire1.ajouterVehicule(VehiculePromenade2);
	proprietaire1.ajouterVehicule(Camion1);
	std::ostringstream oss;
	oss << "Proprietaire\n-------------------\nNom     : Marois\nPrenom  : Nicolas\n" << "-------------------\n"
	        << VehiculePromenade1.reqVehiculeFormate() << "-------------------\n"
	        << VehiculePromenade2.reqVehiculeFormate() << "-------------------\n"
	        << Camion1.reqVehiculeFormate();
	ASSERT_EQ(oss.str(), proprietaire1.reqProprietaireFormate());
}
