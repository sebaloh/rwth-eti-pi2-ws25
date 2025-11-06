/*
 * Fahrzeug.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

void Fahrzeug::vKopf() {
	std::cout  << std::setiosflags(std::ios::left) << std::setw(4) << "ID" << std::setw(16) << "Name" << std::setw(24) << "MaxGeschwindigkeit" << std::setw(16) << "Gesamtstrecke" << std::endl;
	std::cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << std::endl;
}

void Fahrzeug::vAusgeben() const {
	std::cout << std::setiosflags(std::ios::left) << std::setw(4) << p_iID;
	std::cout << std::setiosflags(std::ios::left) << std::setw(16) << p_sName;
	std::cout << std::setiosflags(std::ios::left) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(24) << p_dMaxGeschwindigkeit;
	std::cout << std::setiosflags(std::ios::left) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << p_dGesamtStrecke;
}

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
