/*
 * Fahrausnahme.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Fahrausnahme.h"

Fahrausnahme::Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg) :
	p_pFahrzeug(fahrzeug),
	p_pWeg(weg)
{

}

Fahrausnahme::~Fahrausnahme() {

}
