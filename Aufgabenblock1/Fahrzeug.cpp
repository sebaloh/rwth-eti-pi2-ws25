 /*
 * Fahrzeug.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"

double dGlobaleZeit = 0.0;
int Fahrzeug::p_iMaxID = 0;

void Fahrzeug::vKopf() {
	std::cout  << std::setiosflags(std::ios::left) << std::setw(4) << "ID" << std::setw(16) << "Name" << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<  std::setw(24) << "MaxGeschwindigkeit" << std::setw(16) << "Gesamtstrecke" << std::setw(16) << "Gesamtverbrauch" << std::setw(16) << "Tankinhalt" << std::setw(16) << "Geschwindigkeit" << std::endl;
	std::cout << std::setfill('-') << std::setw(108) << "" << std::setfill(' ') << std::endl;
}

void Fahrzeug::vAusgeben(std::ostream& os) const {
	os << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(4) << p_iID;
	os << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(16) << p_sName;
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(24) << p_dMaxGeschwindigkeit;
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren() {
	double dDeltaZeit = dGlobaleZeit - p_dZeit;
	double dGefahreneStrecke = p_dMaxGeschwindigkeit * dDeltaZeit;

	// Wenn Delta < 0.5 wurde bei einem Simulationsschritt von 0.5 schon aktualisiert.
	if (dDeltaZeit >= 0.5) {
		p_dGesamtStrecke += dGefahreneStrecke;
		p_dGesamtZeit += dDeltaZeit;
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double dMenge) {
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const {
	return p_dMaxGeschwindigkeit;
}

Fahrzeug::Fahrzeug() :
	p_sName(""),
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug (#" << p_iID << ") \"" << p_sName << "\" erstellt."<< std::endl;
}

Fahrzeug::Fahrzeug(const std::string sName) :
	p_sName(sName),
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug (#" << p_iID << ") \"" << p_sName << "\" erstellt."<< std::endl;
}

Fahrzeug::Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit) :
	p_sName(sName),
	p_iID(++p_iMaxID),
	p_dMaxGeschwindigkeit(dMaxGeschwindigkeit < 0.0 ? 0.0 : dMaxGeschwindigkeit),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dZeit(0.0)
{
	std::cout << "Fahrzeug (#" << p_iID << ") \"" << p_sName << "\" erstellt."<< std::endl;
}

Fahrzeug::~Fahrzeug() {
	std::cout << "Fahrzeug (#" << p_iID << ") \"" << p_sName << "\" gelöscht."<< std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug) {
    fahrzeug.vAusgeben(os);
    return os;
}
