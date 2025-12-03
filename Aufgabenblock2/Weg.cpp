/*
 * Weg.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Weg.h"
#include "Fahrzeug.h"

void Weg::vKopf() {
	std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(4) << "ID" << std::setw(16) << "Name" << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<  std::setw(12) << "Laenge" << std::setw(24) << "Fahrzeuge" << std::endl;
	std::cout << std::setfill('-') << std::setw(56) << "" << std::setfill(' ') << std::endl;
}

void Weg::vAusgeben(std::ostream& os) const {
	Simulationsobjekt::vAusgeben(os);
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(12) << p_dLaenge;

	os << std::setw(4) << "( ";
	for (auto& fahrzeug : p_pFahrzeuge) {
		os << fahrzeug->sName() << " ";
	}
	os << ")";
}

double Weg::dLaenge() const {
	return p_dLaenge;
}

void Weg::vSimulieren() {
	for (auto& fahrzeug : p_pFahrzeuge) {
		try {
			fahrzeug->vSimulieren();
			fahrzeug->vZeichnen(*this);
		}
		catch (Fahrausnahme& ausnahme) {
			ausnahme.vBearbeiten();
		}
	}
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug) {
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(std::move(pFahrzeug));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit) {
	pFahrzeug->vNeueStrecke(*this, dStartzeit);
	p_pFahrzeuge.push_back(std::move(pFahrzeug));
}

double Weg::getTempolimit() const {
	switch (p_eTempolimit) {
		case Tempolimit::Innerorts:
			return 50.0;
		case Tempolimit::Landstrasse:
			return 100.0;
		case Tempolimit::Autobahn:
			return static_cast<double>(std::numeric_limits<int>::max());
		default:
			return 0.0;
	}
}

Weg::Weg(std::string sName, double dLaenge, Tempolimit eTempolimit) :
	Simulationsobjekt(sName),
	p_dLaenge(dLaenge),
	p_eTempolimit(eTempolimit)
{

}
