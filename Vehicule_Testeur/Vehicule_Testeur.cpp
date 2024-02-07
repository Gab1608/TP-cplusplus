/*
 * Vehicule_Testeur.cpp
 *
 *  Created on: 2019-11-25
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Vehicule.h"
#include <iostream>
#include <sstream>
using namespace saaq;
using namespace std;

/**
 * \class VehiculeTest
 * \brief classe de test permettant de tester la classe abstraite Vehicule
 */
namespace saaq
{
	class VehiculeTest: public Vehicule
	{
	public:
		VehiculeTest(const std::string& p_niv, const std::string& p_immatriculation):
			Vehicule(p_niv, p_immatriculation)
		{
		}
		;
		virtual Vehicule* clone() const
		{
			return new VehiculeTest(*this);

		}
		;
		virtual double tarificationAnnuelle() const
		{
			return 0.0;
		}
		;
	};

}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class vehTest: public ::testing::Test
{
	public:
		vehTest() :
				vehiculeTest("3VWFE21C04M000001", "IFT 006"),
				vehiculeTest2("3VWFE21C04M000001", "IFT 006")


		{
		}
		VehiculeTest vehiculeTest;
		VehiculeTest vehiculeTest2;
};

/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Vehicule et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Niv vide ou qui ne suit pas la fonction de validation validerNiv
 *		    Immatriculation vide ou qui ne suit pas la fonction de validation validerImmatriculationPromenade
 *		    ou validerImmatriculationCamion
 */
TEST(Vehicule, Constructeur)
{
	VehiculeTest UnVehicule("3VWFE21C04M000001", "IFT 006");
	ASSERT_EQ("3VWFE21C04M000001", UnVehicule.reqNiv());
	ASSERT_EQ("IFT 006", UnVehicule.reqImmatriculation());
}

//cas invalides
TEST(Vehicule, ConstructeurInvalideNIV)
{
	ASSERT_THROW(VehiculeTest UnVehicule("", "IFT 006"), ContratException);
	ASSERT_THROW(VehiculeTest UnVehicule("3VWFE21C04M003001", "IFT 006"), ContratException);
}

TEST(Vehicule, ConstructeurInvalideImmatriculation)
{
	ASSERT_THROW(VehiculeTest UnVehicule("3VWFE21C04M000001", ""), ContratException);
	ASSERT_THROW(VehiculeTest UnVehicule("3VWFE21C04M000001", "AB1 100"), ContratException);
}

/**
 * \test Test de la méthode reqNiv()
 *
 *     Cas valide: vérifier le retour du numéro de série.
 *     Cas invalide: aucun.
 */
TEST_F(vehTest, reqNiv)
{
	ASSERT_EQ("3VWFE21C04M000001", vehiculeTest.reqNiv());
}

/**
 * \test Test de la méthode reqImmatriculation()
 *
 *     Cas valide: vérifier le retour du numéro d'immatriculation.
 *     Cas invalide: aucun.
 */
TEST_F(vehTest, reqImmatriculation)
{
	ASSERT_EQ("IFT 006", vehiculeTest.reqImmatriculation());
}

util::Date d0;
string enregistrement = d0.reqDateFormatee();

/**
 * \test Test de la méthode reqDateEnregistrement()
 *
 *     Cas valide: vérifier le retour de la date d'enregistrement.
 *     Cas invalide: aucun.
 */
TEST_F(vehTest, reqDateEnregistrement)
{
	ASSERT_EQ(d0, vehiculeTest.reqDateEnregistrement());
}

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Vehicule formaté
 *        Cas invalides: aucun
 */
TEST_F(vehTest, reqVehiculeFormate)
{
	ASSERT_EQ("Numero de serie : 3VWFE21C04M000001\nNumero d'immatriculation : IFT 006\nDate d'enregistrement : " + enregistrement + "\n",
	        vehiculeTest.reqVehiculeFormate());
}

/**
 * \test Test de la surcharge de l'opérateur ==;
 *
 *        Cas valides: vérifier si deux objets sont identiques
 *        Cas invalides: aucun
 */
TEST_F(vehTest, operator)
{
	ASSERT_EQ(vehiculeTest, vehiculeTest2);
}


/*TEST(Vehicule, GoogleFonctionne)
{
	ASSERT_EQ(1,1);
}*/


