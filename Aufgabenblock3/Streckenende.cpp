/*
 * Streckenende.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

void Streckenende::vBearbeiten() {
	std::unique_ptr<Fahrzeug> pFahrzeug = p_Weg.pAbgabe(p_Fahrzeug);

	if (!pFahrzeug) {
		return;
	}

	std::shared_ptr<const Kreuzung> pZielkreuzung = p_Weg.getZielkreuzung();

	if (!pZielkreuzung) {
		std::cout << "Fahrzeug (#" << p_Fahrzeug.getID() << ") \"" << p_Fahrzeug.getName() << "\" hat Ende vom Weg (#" << p_Weg.getID() << ") \"" << p_Weg.getName() << "\" erreicht." << std::endl;
		return;
	}

	Kreuzung& kreuzung = const_cast<Kreuzung&>(*pZielkreuzung);
	std::shared_ptr<Weg> pNeuerWeg = kreuzung.pZufaelligerWeg(p_Weg);

	if (!pNeuerWeg) {
		return;
	}

	std::cout << "ZEIT        : [" << dGlobaleZeit << "]" << std::endl;
	std::cout << "KREUZUNG    : [" << kreuzung.getName() << "] [" << kreuzung.getTankstelle() << "]" << std::endl;
	std::cout << "WECHSEL     : [" << p_Weg.getName()<< "] -> [" << pNeuerWeg->getName() << "]" << std::endl;
	std::cout << "FAHRZEUG    : [" << *pFahrzeug << "]" << std::endl;

	pNeuerWeg->vAnnahme(std::move(pFahrzeug));
}

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) :
	Fahrausnahme(fahrzeug, weg)
{

}

Streckenende::~Streckenende() {

}
