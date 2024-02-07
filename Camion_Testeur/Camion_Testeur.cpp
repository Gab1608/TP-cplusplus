/*
 * Camion_Testeur.cpp
 *
 *  Created on: 2019-11-26
 *      Author: etudiant
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Camion.h"
using namespace saaq;
using namespace std;


/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Camion et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Immatriculation vide ou qui ne suit pas la fonction de validation validerImmatriculationCamion (différent de la classe Véhicule)
 *		    Poids inférieur ou égal à 3000
 *		    NbEssieux inférieur à 2
 *
 */
TEST(Camion, Constructeur)
{
	Camion UnCamion("3VWFE21C04M000001", "L123456", 4500, 4);
	ASSERT_EQ("3VWFE21C04M000001", UnCamion.reqNiv());
	ASSERT_EQ("L123456", UnCamion.reqImmatriculation());
	ASSERT_EQ(4500, UnCamion.reqPoids());
	ASSERT_EQ(4, UnCamion.reqNbEssieux());

}

//cas invalides
TEST(Camion,ConstructeurInvalideImmatriculation)
{
	ASSERT_THROW(Camion UnCamion("3VWFE21C04M000001", "IFT 006", 4500, 4),PreconditionException);
}

TEST(Camion,ConstructeurInvalidePoids)
{
	ASSERT_THROW(Camion unCamion( "3VWFE21C04M000001", "L123456", 2999, 4),PreconditionException);
}

TEST(Camion,ConstructeurInvalideNbEssieux)
{
	ASSERT_THROW(Camion unCamion( "3VWFE21C04M000001", "L123456", 4500, 1),PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnCamion: public ::testing::Test
{
public:
	UnCamion() :
		unCamionRouge( "3VWFE21C04M000001", "L123456", 4500, 4)
	{}
	;
	Camion unCamionRouge;
};

/**
 * \test Test de la méthode reqPoids()
 *
 *     Cas valide: vérifier le retour du poids.
 *     Cas invalide: aucun.
 */
TEST_F(UnCamion, reqPoids)
{
	ASSERT_EQ(4500, unCamionRouge.reqPoids());
}

/**
 * \test Test de la méthode reqNbEssieux()
 *
 *     Cas valide: vérifier le retour du nombre d'essieux.
 *     Cas invalide: aucun.
 */
TEST_F(UnCamion, reqNbEssieux)
{
	ASSERT_EQ(4, unCamionRouge.reqNbEssieux());
}

/**
 * \test Test de la méthode tarificationAnnuelle()
 *
 *     Cas valide: vérifier le retour de la tarification annuelle du camion
 *     	(varie selon le poids et le nombre d'essieux).
 *     Cas invalide: aucun.
 */
TEST_F(UnCamion,tarificationAnnuelle)
{

	ASSERT_EQ(2206.19, unCamionRouge.tarificationAnnuelle());
}

util::Date d0;
string enregistrement = d0.reqDateFormatee();

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Camion formaté
 *        Cas invalides: aucun
 */
TEST_F(UnCamion, reqVehiculeFormate)
{
	ASSERT_EQ("Numero de serie : 3VWFE21C04M000001\nNumero d'immatriculation : L123456\nDate d'enregistrement : " + enregistrement + "\n"
			"nombre d'essieux : 4\npoids : 4500 kg\ntarif : 2206.19$\n",
			unCamionRouge.reqVehiculeFormate());
}

/**
 * \test Test de la méthode clone();
 *
 *        Cas valides: vérifier que le clone possède les mêmes propriétés que l'objet Camion
 *        Cas invalides: aucun
 */
TEST_F(UnCamion, clone)
{
	Camion* pr_c = (Camion*)unCamionRouge.clone();
	pr_c -> reqVehiculeFormate();
}
