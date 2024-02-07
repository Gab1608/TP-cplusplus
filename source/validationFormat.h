/*
 * fonctionsUtilitaires.h
 *
 *  Created on: 2019-09-25
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util
{



bool validerImmatriculationPromenade (const std::string& p_immatriculation);

bool validerImmatriculationCamion (const std::string& p_immatriculation);

bool validerNiv (const std::string& p_niv);

} // namespace util

#endif /* VALIDATIONFORMAT_H_ */
