/*
 * PKW.cpp
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#include "PKW.h"

PKW::PKW(const std::string sName) :
	Fahrzeug(sName)
{

}

PKW::PKW(const std::string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit)
{

}
