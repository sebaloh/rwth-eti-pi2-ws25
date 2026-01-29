/*
 * Fahren.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
	double dGeschwindigkeit = std::min(aFzg.getGeschwindigkeit(), p_Weg.getTempolimit());
	double dMoeglicheStrecke = dGeschwindigkeit * dZeitIntervall;
	double dRestStrecke = p_Weg.getLaenge() - aFzg.getAbschnittStrecke();
	double dEntfernungZurSchranke = p_Weg.getVirtuelleSchranke() - aFzg.getAbschnittStrecke();

	// Falls schon am Ende der Strecke
	if (dRestStrecke <= 0.0) {
		throw Streckenende(aFzg, p_Weg);
	}

	// Falls Schranke im Weg
	if (dMoeglicheStrecke > dEntfernungZurSchranke) {
		return dEntfernungZurSchranke;
	}

	// Falls am Ende angekommen
	if (dMoeglicheStrecke >= dRestStrecke) {
		throw Streckenende(aFzg, p_Weg);
	}

	// Sonst fahre gesamte Strecke
	return dMoeglicheStrecke;
}

Fahren::Fahren(Weg& weg) :
	Verhalten(weg)
{

}

Fahren::~Fahren() {

}
