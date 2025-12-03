/*
 * Parken.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"

extern double dGlobaleZeit;

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
    if (dGlobaleZeit < p_dStartzeit) {
        return 0.0;
    } else {
		if (!p_bGestartet) {
            std::cout << "Fahrzeug " << aFzg.sName() << " startet zur Zeit " << dGlobaleZeit << " auf Weg " << p_Weg.sName() << std::endl;
            p_bGestartet = true;
        }

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
}

Parken::Parken(Weg& weg, double dStartzeit) :
	Verhalten(weg),
	p_dStartzeit(dStartzeit)
{

}

Parken::~Parken() {

}

