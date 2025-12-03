/*
 * Streckenende.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

void Streckenende::vBearbeiten() {
	std::cout << "Fahrzeug (#" << p_pFahrzeug.iID() << ") \"" << p_pFahrzeug.sName() << "\" hat Ende vom Weg (#" << p_pWeg.iID() << ") \"" << p_pWeg.sName() << "\" erreicht." << std::endl;
}

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) :
	Fahrausnahme(fahrzeug, weg)
{

}

Streckenende::~Streckenende() {

}
