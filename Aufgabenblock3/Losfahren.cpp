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
	std::cout << "Fahrzeug (#" << p_Fahrzeug.getID() << ") \"" << p_Fahrzeug.getName() << "\" ist auf dem Weg (#" << p_Weg.getID() << ") \"" << p_Weg.getName() << "\" gestartet." << std::endl;
	std::unique_ptr<Fahrzeug> pFahrzeug = p_Weg.pAbgabe(p_Fahrzeug);
	if (pFahrzeug) {
		p_Weg.vAnnahme(std::move(pFahrzeug));
	}
}

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) :
	Fahrausnahme(fahrzeug, weg)
{

}

Losfahren::~Losfahren() {

}
