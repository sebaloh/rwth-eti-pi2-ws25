 /*
 * Fahrzeug.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"

void Fahrzeug::vAusgeben(std::ostream& os) const {
	Simulationsobjekt::vAusgeben(os);
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

std::string Fahrzeug::sName() const {
	return p_sName;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const {
    return this->p_dGesamtStrecke < other.p_dGesamtStrecke;
}

Fahrzeug::Fahrzeug(const std::string sName) :
	Simulationsobjekt(sName),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0)
{

}

Fahrzeug::Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit) :
	Simulationsobjekt(sName),
	p_dMaxGeschwindigkeit(dMaxGeschwindigkeit < 0.0 ? 0.0 : dMaxGeschwindigkeit),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0)
{

}
