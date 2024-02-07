/*
 * fonctionsUtilitaires.cpp
 *
 *  Created on: 2019-09-25
 *      Author: etudiant
 */

#include "validationFormat.h"

#include <iostream>
using namespace std;
namespace util
{



bool validerImmatriculationPromenade (const std::string& p_immatriculation)
{
	bool valide = false;

	if(p_immatriculation.length() == 7)
	{
		if (((p_immatriculation[0] >= 48) && (p_immatriculation[0] <= 57)) ||
		((p_immatriculation[0] >= 65) && (p_immatriculation[0] <= 90) && (p_immatriculation[0] != 79) && p_immatriculation[0] != 76))
		{
			if ((p_immatriculation[1] >= 48) && (p_immatriculation[1] <= 57))
			{
				if ((p_immatriculation[2] >= 48) && (p_immatriculation[2] <= 57))
				{
					if (p_immatriculation[3] == 32)
					{
						if ((p_immatriculation[4] >= 65) && (p_immatriculation[4] <= 90) && (p_immatriculation[4] != 79))
						{
							if ((p_immatriculation[5] >= 65) && (p_immatriculation[5] <= 90) && (p_immatriculation[5] != 79))
							{
								if ((p_immatriculation[6] >= 65) && (p_immatriculation[6] <= 90) && (p_immatriculation[6] != 79))
								{
									valide = true; /*Valide si la plaque est de type 000 ABC ou A00 ABC*/
								}
							}
						}
					}
					else
					{
						if ((p_immatriculation[3] >= 65) && (p_immatriculation[3] <= 90) && (p_immatriculation[3] != 79))
						{
							if ((p_immatriculation[4] >= 48) && (p_immatriculation[4] <= 57))
							{
								if ((p_immatriculation[5] >= 48) && (p_immatriculation[5] <= 57))
								{
									if ((p_immatriculation[6] >= 48) && (p_immatriculation[6] <= 57))
									{
										valide = true; /*Valide si la plaque est de la forme 000H000*/
									}
								}
							}
						}
					}
				}
			}
			else
			{
				if ((p_immatriculation[1] >= 65) && (p_immatriculation[1] <= 90) && (p_immatriculation[1] != 79))
				{
					if ((p_immatriculation[2] >= 65) && (p_immatriculation[2] <= 90) && (p_immatriculation[2] != 79))
					{
						if (p_immatriculation[3] == 32)
						{
							if ((p_immatriculation[4] >= 48) && (p_immatriculation[4] <= 57))
							{
								if ((p_immatriculation[5] >= 48) && (p_immatriculation[5] <= 57))
								{
									if ((p_immatriculation[6] >= 48) && (p_immatriculation[6] <= 57))
									{
										valide = true; /*Valide si la plaque est de la forme ABC 000*/
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if(p_immatriculation.length() == 4)
		{
			if ((p_immatriculation[0] >= 65) && (p_immatriculation[0] <= 90) && (p_immatriculation[0] != 79))
			{
				if ((p_immatriculation[1] >= 65) && (p_immatriculation[1] <= 90) && (p_immatriculation[1] != 79))
				{
					if ((p_immatriculation[2] >= 65) && (p_immatriculation[2] <= 90) && (p_immatriculation[2] != 79))
					{
						if ((p_immatriculation[3] >= 65) && (p_immatriculation[3] <= 90) && (p_immatriculation[3] != 79))
						{
							valide = true; /*Valide si la plaque est de la forme SAAQ*/
						}
					}
				}
			}
		}
	}

	return valide;
}

bool validerImmatriculationCamion (const std::string& p_immatriculation)
{
	bool valide = false;
	if(p_immatriculation[0] == 76)
	{
		if ((p_immatriculation[1] >= 48) && (p_immatriculation[1] <= 57))
		{
			if ((p_immatriculation[2] >= 48) && (p_immatriculation[2] <= 57))
			{
				if ((p_immatriculation[3] >= 48) && (p_immatriculation[3] <= 57))
				{
					if ((p_immatriculation[4] >= 48) && (p_immatriculation[4] <= 57))
					{
						if ((p_immatriculation[5] >= 48) && (p_immatriculation[5] <= 57))
						{
							if ((p_immatriculation[6] >= 48) && (p_immatriculation[6] <= 57))
							{
								valide = true; /*Valide si la plaque est de la forme L000000*/
							}
						}
					}
				}
			}
		}
	}

	return valide;
}



bool validerNiv (const std::string& p_niv)
{
	bool valide = true;
	if(p_niv.length() != 17)
	{
		valide = false; /*S'assure que p_niv soit de longueur 17*/
	}

	for (unsigned int i = 0; i < p_niv.length(); ++i)
	{
		int c = p_niv[i];
		if ((c == 73) || (c == 79) || (c == 81))
		{
			valide = false; /*S'assure que p_niv ne contient pas de I, de O ni de Q*/
		}
		if (((c < 48) || (c > 57)) && ((c < 65) || (c > 90)))
		{
			valide = false; /*S'assure que p_niv ne contient que des lettres majuscules et des chiffres*/
		}
	}

	if (((p_niv[8] < 48) || (p_niv[8] > 57)) && (p_niv[8] != 88))
		{
			valide = false; /*S'assure que la position 9 soit adéquat (un chiffre ou X)*/
		}

	for (unsigned int i = 12; i < p_niv.length(); ++i)
	{
		int c = p_niv[i];
		if ((c < 48) || (c > 57))
		{
			valide = false; /*S'assure que les positions 13 à 17 soient numériques*/
		}
	}

	if ((p_niv[9] == 85) || (p_niv[9] == 90))
	{
		valide = false; /*S'assure que la position 10 de p_niv ne contient pas de U ni de Z*/
	}


	if (valide == true) /*On ne peut procéder avec les calculs sans que la forme du niv soit bonne*/
	{
		int tableau[17];
		for (unsigned int i = 0; i < p_niv.length(); ++i)
			{
				int c = p_niv[i];

				if ((c >= 65) && (c <= 90)) /*Il faut transformer les lettres du niv en chiffres et sont insérés dans un tableau à part*/
				{
					if ((c == 65) || (c == 74))
					{
						tableau[i] = 1;
					}
					if ((c == 66) || (c == 75) || (c == 83))
					{
						tableau[i] = 2;
					}
					if ((c == 67) || (c == 76) || (c == 84))
					{
						tableau[i] = 3;
					}
					if ((c == 68) || (c == 77) || (c == 85))
					{
						tableau[i] = 4;
					}
					if ((c == 69) || (c == 78) || (c == 86))
					{
						tableau[i] = 5;
					}
					if ((c == 70) || (c == 87))
					{
						tableau[i] = 6;
					}
					if ((c == 71) || (c == 80) || (c == 88))
					{
						tableau[i] = 7;
					}
					if ((c == 72) || (c == 89))
					{
						tableau[i] = 8;
					}
					if ((c == 82) || (c == 90))
					{
						tableau[i] = 9;
					}
					if (c == 88)
					{
						tableau[i] = 10;
					}
				}
				else
				{
					tableau[i] = (c - 48);
				}
			}
		/*cout << tableau[0] << endl;
		cout << tableau[1] << endl;
		cout << tableau[2] << endl;
		cout << tableau[3] << endl;
		cout << tableau[4] << endl;
		cout << tableau[5] << endl;
		cout << tableau[6] << endl;
		cout << tableau[7] << endl;
		cout << tableau[8] << endl;
		cout << tableau[9] << endl;
		cout << tableau[10] << endl;
		cout << tableau[11] << endl;
		cout << tableau[12] << endl;
		cout << tableau[13] << endl;
		cout << tableau[14] << endl;
		cout << tableau[15] << endl;*/

		int tableauMultiplication[17];
		int somme = 0;

		for (unsigned int i = 0; i < p_niv.length(); ++i) /*Multiplication du poids lié à chaque position et sa valeur
		et la contenir dans une variable nommée somme*/
		{
			if ((i >= 0) && (i <= 6))
			{
				tableauMultiplication[i] = tableau[i] * (8 - i);
			}
			if (i == 7)
			{
				tableauMultiplication[i] = tableau[i] * 10;
			}
			if (i == 8)
			{
				tableauMultiplication[i] = tableau[i] * 0;
			}
			if ((i >= 9) && (i <= 16))
			{
				int poids = i - 2 * (i - 9);
				tableauMultiplication[i] = tableau[i] * poids;
			}
		}

		/*cout << tableauMultiplication[0] << endl;
		cout << tableauMultiplication[1] << endl;
		cout << tableauMultiplication[2] << endl;
		cout << tableauMultiplication[3] << endl;
		cout << tableauMultiplication[4] << endl;
		cout << tableauMultiplication[5] << endl;
		cout << tableauMultiplication[6] << endl;
		cout << tableauMultiplication[7] << endl;
		cout << tableauMultiplication[8] << endl;
		cout << tableauMultiplication[9] << endl;
		cout << tableauMultiplication[10] << endl;
		cout << tableauMultiplication[11] << endl;
		cout << tableauMultiplication[12] << endl;
		cout << tableauMultiplication[13] << endl;
		cout << tableauMultiplication[14] << endl;
		cout << tableauMultiplication[15] << endl;
		cout << tableauMultiplication[16] << endl;*/

		for (unsigned int i = 0; i < p_niv.length(); ++i) /*La somme de tous les éléments multipliés*/
		{
			somme = somme + tableauMultiplication[i];
		}

		/*cout << somme << endl;*/

		int division;
		division = somme % 11; /*Le reste de la division servant à identifier le numéro de vérification*/

		/*cout << division << endl;*/

		if (division != tableau[8]) /*Vérifier si le restant de la division est le même que le chiffre < la position 9 du niv*/
		{
			valide = false;
		}

	}


	return valide;
}

} // namespace util
