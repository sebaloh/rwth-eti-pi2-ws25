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
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << getGeschwindigkeit();
}

void PKW::vEinlesen(std::istream& is) {
    Fahrzeug::vEinlesen(is);
    is >> p_dVerbrauch >> p_dTankvolumen;
    p_dTankinhalt = p_dTankvolumen / 2.0;
}

void PKW::vSimulieren() {
	double dDeltaZeit = dGlobaleZeit - p_dZeit;
	double dMoeglicheStrecke = p_dMaxGeschwindigkeit * dDeltaZeit;

	// Wenn Delta < 0.5 wurde bei einem Simulationsschritt von 0.5 schon aktualisiert.
	if (dDeltaZeit >= 0.5) {
		// Falls Simulation mit Parken/Fahren hier neu berechnen
		if (p_pVerhalten) {
			dMoeglicheStrecke = p_pVerhalten->dStrecke(*this, dDeltaZeit);
		}

		double dVerbrauch = dMoeglicheStrecke * p_dVerbrauch / 100.0;

		if (dVerbrauch <= p_dTankinhalt) {
			p_dGesamtStrecke += dMoeglicheStrecke;
			p_dAbschnittStrecke += dMoeglicheStrecke;
			p_dTankinhalt -= dVerbrauch;
		} else if (p_dTankinhalt == 0.0) {
			return;
		} else {
			// Falls nicht genug Tank nicht mehr gesamte Strecke möglich
			double dWirklicheStrecke = dMoeglicheStrecke * (dVerbrauch / p_dTankinhalt);

			p_dGesamtStrecke += dWirklicheStrecke;
			p_dAbschnittStrecke += dWirklicheStrecke;
			p_dTankinhalt = 0.0;
		}

		p_dGesamtZeit += dDeltaZeit;
		p_dZeit = dGlobaleZeit;
	}
}

void PKW::vZeichnen(const Weg& weg) const {
	double dRelPosition =  getAbschnittStrecke() / weg.getLaenge();
	dRelPosition = std::max(0.0, std::min(1.0, dRelPosition));
	bZeichnePKW(getName(), weg.getName(), dRelPosition, getGeschwindigkeit(), getTankinhalt());
}

double PKW::getTankinhalt() const {
	return p_dTankinhalt;
}

double PKW::dTanken(double dMenge) {
	double dMaxMenge = p_dTankvolumen - p_dTankinhalt;
	double dEchteMenge = dMenge > dMaxMenge ? dMaxMenge : dMenge;
	p_dTankinhalt += dEchteMenge;
	return dEchteMenge;
}

PKW::PKW() :
	Fahrzeug("", 0.0),
	p_dVerbrauch(0.0),
	p_dTankvolumen(55.0),
	p_dTankinhalt(27.5)
{

}

PKW::PKW(const std::string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit),
	p_dVerbrauch(0.0),
	p_dTankvolumen(55.0),
	p_dTankinhalt(27.5)
{

}

PKW::PKW(const std::string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen) :
	Fahrzeug(sName, dMaxGeschwindigkeit),
	p_dVerbrauch(dVerbrauch < 0.0 ? 0.0 : dVerbrauch),
	p_dTankvolumen(dTankvolumen <= 0.0 ? 55.0 : dTankvolumen),
	p_dTankinhalt(p_dTankvolumen/2)
{

}
