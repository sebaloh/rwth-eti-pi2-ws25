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
		return 0.0;
	}

	if (dMoeglicheStrecke < dRestStrecke) {
		return dMoeglicheStrecke;
	} else {
		std::cout << "Fahrzeug " << aFzg.sName() << " am Ende des Weges angekommen." << std::endl;
		return dRestStrecke;
	}
}

Fahren::Fahren(Weg& weg) :
	Verhalten(weg)
{

}

Fahren::~Fahren() {

}
