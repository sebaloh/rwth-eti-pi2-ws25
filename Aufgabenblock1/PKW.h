/*
 * PKW.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug {
public:
	PKW(const std::string sName);
	PKW(const std::string sName, const double dMaxGeschwindigkeit);
};

#endif /* PKW_H_ */
