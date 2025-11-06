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
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " erstellt."<< std::endl;
}

Fahrzeug::Fahrzeug(const std::string sName) :
	p_sName(sName),
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " erstellt."<< std::endl;
}

Fahrzeug::Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit) :
	p_sName(sName),
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(dMaxGeschwindigkeit < 0.0 ? 0.0 : dMaxGeschwindigkeit),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " erstellt."<< std::endl;
}

Fahrzeug::~Fahrzeug() {
	std::cout << "Fahrzeug \"" << p_sName << "\" #" << p_iID << " gelöscht."<< std::endl;
}
