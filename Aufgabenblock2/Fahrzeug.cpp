 /*
 * Fahrzeug.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"

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
		if (p_pVerhalten) {
			dGefahreneStrecke = p_pVerhalten->dStrecke(*this, dDeltaZeit);
		} else {
            dGefahreneStrecke = p_dMaxGeschwindigkeit * dDeltaZeit;
        }

		p_dGesamtStrecke += dGefahreneStrecke;
		p_dAbschnittStrecke += dGefahreneStrecke;
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

void Fahrzeug::vNeueStrecke(Weg& weg) {
    p_pVerhalten = std::make_unique<Fahren>(weg);
    p_dAbschnittStrecke = 0.0;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double dStartzeit) {
	p_pVerhalten = std::make_unique<Parken>(weg, dStartzeit);
	p_dAbschnittStrecke = 0.0;
}

double Fahrzeug::dAbschnittStrecke() const {
    return p_dAbschnittStrecke;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const {
    return this->p_dGesamtStrecke < other.p_dGesamtStrecke;
}

Fahrzeug::Fahrzeug(const std::string sName) :
	Simulationsobjekt(sName),
	p_dMaxGeschwindigkeit(0.0),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dAbschnittStrecke(0.0)
{

}

Fahrzeug::Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit) :
	Simulationsobjekt(sName),
	p_dMaxGeschwindigkeit(dMaxGeschwindigkeit < 0.0 ? 0.0 : dMaxGeschwindigkeit),
	p_dGesamtStrecke(0.0),
	p_dGesamtZeit(0.0),
	p_dAbschnittStrecke(0.0)
{

}

Fahrzeug::~Fahrzeug() {

}
