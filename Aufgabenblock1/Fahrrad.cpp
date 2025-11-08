/*
 * Fahrrad.cpp
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad(const std::string sName) :
	Fahrzeug(sName)
{

}

Fahrrad::Fahrrad(const std::string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit)
{

}
