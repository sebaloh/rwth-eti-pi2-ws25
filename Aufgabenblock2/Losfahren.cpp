/*
 * Losfahren.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

void Losfahren::vBearbeiten() {
	std::cout << "Fahrzeug (#" << p_pFahrzeug.iID() << ") \"" << p_pFahrzeug.sName() << "\" ist auf dem Weg (#" << p_pWeg.iID() << ") \"" << p_pWeg.sName() << "\" gestartet." << std::endl;
}

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) :
	Fahrausnahme(fahrzeug, weg)
{

}

Losfahren::~Losfahren() {

}
