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
    if (dGlobaleZeit < p_dStartzeit - 0.001) {
        return 0.0;
    } else {
		if (!p_bGestartet) {
            p_bGestartet = true;
            std::cout << dGlobaleZeit << std::endl;
            throw Losfahren(aFzg, p_Weg);
        }

        double dGeschwindigkeit = std::min(aFzg.getGeschwindigkeit(), p_Weg.getTempolimit());
        double dMoeglicheStrecke = dGeschwindigkeit * dZeitIntervall;
        double dRestStrecke = p_Weg.getLaenge() - aFzg.getAbschnittStrecke();

		if (dRestStrecke <= 0.0) {
			throw Streckenende(aFzg, p_Weg);
		}

        if (dMoeglicheStrecke < dRestStrecke) {
            return dMoeglicheStrecke;
        } else {
			throw Streckenende(aFzg, p_Weg);
        }
    }
}

Parken::Parken(Weg& weg, double dStartzeit) :
	Verhalten(weg),
	p_dStartzeit(dStartzeit),
    p_bGestartet(false)
{

}

Parken::~Parken() {

}

