/*
 * Fahrzeug.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug() :
	p_sName(""),
	p_iID(++p_iMaxID)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " erstellt."<< std::endl;
}

Fahrzeug::Fahrzeug(const std::string sName) :
	p_sName(sName),
	p_iID(++p_iMaxID)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " erstellt."<< std::endl;
}

Fahrzeug::~Fahrzeug() {
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " gelöscht."<< std::endl;
}
