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
		throw Losfahren(aFzg, p_Weg);
    }
}

Parken::Parken(Weg& weg, double dStartzeit) :
	Verhalten(weg),
	p_dStartzeit(dStartzeit)
{

}

Parken::~Parken() {

}

