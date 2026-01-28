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

	if (dRestStrecke <= 0.0) {
		throw Streckenende(aFzg, p_Weg);
	}

	double dEntfernungSchranke = p_Weg.getVirtuelleSchranke() - aFzg.getAbschnittStrecke();
	double dMaxStrecke = std::min(dRestStrecke, dEntfernungSchranke);

	if (dMoeglicheStrecke < dMaxStrecke) {
		if (dMoeglicheStrecke < dRestStrecke) {
			return dMoeglicheStrecke;
		}
		return dRestStrecke;
	} else if (dMaxStrecke >= dRestStrecke) {
		throw Streckenende(aFzg, p_Weg);
	} else {
		return dEntfernungSchranke > 0 ? dEntfernungSchranke : 0;
	}
}

Fahren::Fahren(Weg& weg) :
	Verhalten(weg)
{

}

Fahren::~Fahren() {

}
