/*
 * Fahrrad.cpp
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#include "Fahrrad.h"

void Fahrrad::vAusgeben(std::ostream& os) const {
	Fahrzeug::vAusgeben(os);
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << "";
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << "";
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(16) << getGeschwindigkeit();
}

void Fahrrad::vEinlesen(std::istream& is) {
    Fahrzeug::vEinlesen(is);
}

void Fahrrad::vSimulieren() {
	double dDeltaZeit = dGlobaleZeit - p_dZeit;
	double dGefahreneStrecke = getGeschwindigkeit() * dDeltaZeit;

	// Wenn Delta < 0.5 wurde bei einem Simulationsschritt von 0.5 schon aktualisiert.
	if (dDeltaZeit >= 0.5) {
		// Falls Simulation mit Parken/Fahren hier neu berechnen
		if (p_pVerhalten) {
			dGefahreneStrecke = p_pVerhalten->dStrecke(*this, dDeltaZeit);
		}

		p_dGesamtStrecke += dGefahreneStrecke;
		p_dAbschnittStrecke += dGefahreneStrecke;
		p_dGesamtZeit += dDeltaZeit;
		p_dZeit = dGlobaleZeit;
	}
}

void Fahrrad::vZeichnen(const Weg& weg) const {
	double dRelPosition =  getAbschnittStrecke() / weg.getLaenge();
	dRelPosition = std::max(0.0, std::min(1.0, dRelPosition));
	bZeichneFahrrad(getName(), weg.getName(), dRelPosition, getGeschwindigkeit());
}

double Fahrrad::getGeschwindigkeit() const {
	double dTatsaechlicheGeschwindigkeit = p_dMaxGeschwindigkeit * (1.0 - (p_dGesamtStrecke / 200.0));
	return dTatsaechlicheGeschwindigkeit < 12.0 ? 12.0 : dTatsaechlicheGeschwindigkeit;
}

Fahrrad::Fahrrad() :
	Fahrzeug("", 0.0)
{

}

Fahrrad::Fahrrad(const std::string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit)
{

}
