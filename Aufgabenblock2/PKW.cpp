/*
 * PKW.cpp
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#include "PKW.h"

void PKW::vAusgeben(std::ostream& os) const {
	Fahrzeug::vAusgeben(os);
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << p_dGesamtStrecke / 100.0 * p_dVerbrauch;
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << p_dTankinhalt;
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << dGeschwindigkeit();
}

void PKW::vSimulieren() {
	double dDeltaZeit = dGlobaleZeit - p_dZeit;
	double dGefahreneStrecke = p_dMaxGeschwindigkeit * dDeltaZeit;
	double dVerbrauch = dGefahreneStrecke * p_dVerbrauch / 100.0;

	// Wenn Delta < 0.5 wurde bei einem Simulationsschritt von 0.5 schon aktualisiert.
	if (dDeltaZeit >= 0.5) {
		p_dGesamtZeit += dDeltaZeit;
		p_dZeit = dGlobaleZeit;

		if (dVerbrauch <= p_dTankinhalt) {
			p_dGesamtStrecke += dGefahreneStrecke;
			p_dTankinhalt -= dVerbrauch;
		} else if (p_dTankinhalt == 0.0) {
			return;
		} else {
			p_dGesamtStrecke += dGefahreneStrecke * (dVerbrauch / p_dTankinhalt);
			p_dTankinhalt = 0.0;
		}
	}
}

double PKW::dTanken(double dMenge) {
	double dMaxMenge = p_dTankvolumen - p_dTankinhalt;
	double dEchteMenge = dMenge > dMaxMenge ? dMaxMenge : dMenge;
	p_dTankinhalt += dEchteMenge;
	return dEchteMenge;
}

PKW::PKW(const std::string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen) :
	Fahrzeug(sName, dMaxGeschwindigkeit),
	p_dVerbrauch(dVerbrauch < 0.0 ? 0.0 : dVerbrauch),
	p_dTankvolumen(dTankvolumen <= 0.0 ? 55 : dTankvolumen),
	p_dTankinhalt(p_dTankvolumen/2)
{

}
