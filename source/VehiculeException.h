/*
 * VehiculeException.h
 *
 *  Created on: 2019-12-03
 *      Author: etudiant
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_

#include <stdexcept>

class VehiculeException : public std::runtime_error{
public:
	VehiculeException(const std::string& p_raison): std::runtime_error(p_raison){}
};

class VehiculeDejaPresentException: public VehiculeException{
public:
	VehiculeDejaPresentException(const std::string& p_raison): VehiculeException(p_raison){}
};

class VehiculeAbsentException: public VehiculeException{
public:
	VehiculeAbsentException(const std::string& p_raison): VehiculeException(p_raison){}
};




#endif /* VEHICULEEXCEPTION_H_ */
