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
	double dGeschwindigkeit = std::min(aFzg.dGeschwindigkeit(), p_Weg.getTempolimit());
	double dMoeglicheStrecke = dGeschwindigkeit * dZeitIntervall;
	double dRestStrecke = p_Weg.dLaenge() - aFzg.dAbschnittStrecke();

	if (dRestStrecke <= 0.0) {
		throw Streckenende(aFzg, p_Weg);
	}

	if (dMoeglicheStrecke < dRestStrecke) {
		return dMoeglicheStrecke;
	} else {
		throw Streckenende(aFzg, p_Weg);
	}
}

Fahren::Fahren(Weg& weg) :
	Verhalten(weg)
{

}

Fahren::~Fahren() {

}
