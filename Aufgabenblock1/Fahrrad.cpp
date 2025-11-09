/*
 * Fahrrad.cpp
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#include "Fahrrad.h"

void Fahrrad::vAusgeben() const {
	Fahrzeug::vAusgeben();

	std::cout << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << "";
	std::cout << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << "";

	std::cout << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << dGeschwindigkeit();
}

void Fahrrad::vSimulieren() {
	double dDeltaZeit = dGlobaleZeit - p_dZeit;
	double dGefahreneStrecke = dGeschwindigkeit() * dDeltaZeit;

	// Wenn Delta < 0.5 wurde bei einem Simulationsschritt von 0.5 schon aktualisiert.
	if (dDeltaZeit >= 0.5) {
		p_dGesamtStrecke += dGefahreneStrecke;
		p_dGesamtZeit += dDeltaZeit;
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrrad::dGeschwindigkeit() const {
	double dTatsaechlicheGeschwindigkeit = p_dMaxGeschwindigkeit * (1.0 - (p_dGesamtStrecke / 200.0));
	return dTatsaechlicheGeschwindigkeit < 12.0 ? 12.0 : dTatsaechlicheGeschwindigkeit;
}

Fahrrad::Fahrrad(const std::string sName) :
	Fahrzeug(sName)
{

}

Fahrrad::Fahrrad(const std::string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit)
{

}
