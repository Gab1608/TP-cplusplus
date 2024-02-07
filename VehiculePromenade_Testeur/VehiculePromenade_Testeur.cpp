/*
 * VehiculePromenade_Testeur.cpp
 *
 *  Created on: 2019-11-26
 *      Author: etudiant
 */

#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "VehiculePromenade.h"
using namespace saaq;
using namespace std;


/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet VehiculePromenade et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Immatriculation vide ou qui ne suit pas la fonction de validation validerImmatriculationPromenade (différent de la classe Véhicule)
 *		    NbPlaces inférieur à zéro
 *
 */
TEST(VehiculePromenade, Constructeur)
{
	VehiculePromenade UnVehiculePromenade("3VWFE21C04M000001", "IFT 006", 5);
	ASSERT_EQ("3VWFE21C04M000001", UnVehiculePromenade.reqNiv());
	ASSERT_EQ("IFT 006", UnVehiculePromenade.reqImmatriculation());
	ASSERT_EQ(5, UnVehiculePromenade.reqNbPlaces());
}

//cas invalides
TEST(VehiculePromenade,ConstructeurInvalideImmatriculation)
{
	ASSERT_THROW(VehiculePromenade unVehiculePromenade("3VWFE21C04M000001", "L123456", 5),PreconditionException);
}

TEST(VehiculePromenade,ConstructeurInvalideNbPlaces)
{
	ASSERT_THROW(VehiculePromenade unVehiculePromenade( "3VWFE21C04M000001", "IFT 006", -1),PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnVehiculePromenade: public ::testing::Test
{
public:
	UnVehiculePromenade() :
		unVehiculeProm( "3VWFE21C04M000001", "IFT 006", 5)
	{}
	;
	VehiculePromenade unVehiculeProm;
};

/**
 * \test Test de la méthode reqNbPlaces()
 *
 *     Cas valide: vérifier le retour du nombre de places.
 *     Cas invalide: aucun.
 */
TEST_F(UnVehiculePromenade, reqNbPlaces)
{
	ASSERT_EQ(5, unVehiculeProm.reqNbPlaces());
}

/**
 * \test Test de la méthode tarificationAnnuelle()
 *
 *     Cas valide: vérifier le retour de la tarification annuelle du véhicule de promenade (fixe 224.04).
 *     Cas invalide: aucun.
 */
TEST_F(UnVehiculePromenade,tarificationAnnuelle)
{

	ASSERT_EQ(224.04, unVehiculeProm.tarificationAnnuelle());
}

util::Date d0;
string enregistrement = d0.reqDateFormatee();

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet VehiculePromenade formaté
 *        Cas invalides: aucun
 */
TEST_F(UnVehiculePromenade, reqVehiculeFormate)
{
	ASSERT_EQ("Numero de serie : 3VWFE21C04M000001\nNumero d'immatriculation : IFT 006\nDate d'enregistrement : " + enregistrement + "\n"
			"nombre de places : 5\ntarif : 224.04$\n",
			unVehiculeProm.reqVehiculeFormate());
}

/**
 * \test Test de la méthode clone();
 *
 *        Cas valides: vérifier que le clone possède les mêmes propriétés que l'objet VehiculePromenade
 *        Cas invalides: aucun
 */
TEST_F(UnVehiculePromenade, clone)
{
	VehiculePromenade* pr_c = (VehiculePromenade*)unVehiculeProm.clone();
	pr_c -> reqVehiculeFormate();
}


