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
	std::cout << "Fahrzeug (#" << p_Fahrzeug.getID() << ") \"" << p_Fahrzeug.getName() << "\" hat Ende vom Weg (#" << p_Weg.getID() << ") \"" << p_Weg.getName() << "\" erreicht." << std::endl;
	p_Weg.pAbgabe(p_Fahrzeug);
}

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) :
	Fahrausnahme(fahrzeug, weg)
{

}

Streckenende::~Streckenende() {

}
