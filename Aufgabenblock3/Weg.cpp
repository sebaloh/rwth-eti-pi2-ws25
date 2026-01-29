/*
 * Weg.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"

void Weg::vKopf() {
	std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(4) << "ID" << std::setw(16) << "Name" << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<  std::setw(12) << "Laenge" << std::setw(24) << "Fahrzeuge" << std::endl;
	std::cout << std::setfill('-') << std::setw(56) << "" << std::setfill(' ') << std::endl;
}

void Weg::vAusgeben(std::ostream& os) const {
	Simulationsobjekt::vAusgeben(os);
	os << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << std::setprecision(2) << std::setiosflags(std::ios::fixed) << std::setw(12) << p_dLaenge;

	os << std::setw(4) << "( ";
	for (const auto& fahrzeug : p_pFahrzeuge) {
		if (fahrzeug) {
			os << fahrzeug->getName() << " ";
		}
	}
	os << ")";
}

double Weg::getLaenge() const {
	return p_dLaenge;
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

double Weg::getVirtuelleSchranke() const {
	if (!p_bUeberholverbot) {
		return p_dLaenge;
	}
	return p_dVirtuelleSchranke;
}

std::shared_ptr<const Kreuzung> Weg::getZielkreuzung() const {
	return p_pZielkreuzung.lock();
}

std::shared_ptr<Weg> Weg::getRueckweg() const {
	return p_pRueckweg.lock();
}

void Weg::setRueckweg(std::shared_ptr<Weg> pRueckweg){
	p_pRueckweg = pRueckweg;
}

void Weg::vSimulieren() {
	p_pFahrzeuge.vAktualisieren();
	// Schranke zurücksetzten, da sie noch auf dem hintersten Fahrzeug steht und so alles blockiert
	p_dVirtuelleSchranke = p_dLaenge;

	for (auto& fahrzeug : p_pFahrzeuge) {
		if (!fahrzeug) {
			continue;
		}

		try {
			fahrzeug->vSimulieren();
			fahrzeug->vZeichnen(*this);

			if (p_bUeberholverbot) {
				PKW* pkw = dynamic_cast<PKW*>(fahrzeug.get());

				// Nur für !PKWs und PKWs mit Tank neue Schranke
				// PKWs ohne Tank werden übersprungen
				if (pkw == nullptr || pkw->getTankinhalt() > 0) {
					// Schranke für folgende Fahrzeuge ist nun der Ort des Autos
					p_dVirtuelleSchranke = fahrzeug->getAbschnittStrecke();
				}
			}
		}
		catch (Fahrausnahme& ausnahme) {
			ausnahme.vBearbeiten();
		}
	}
	p_pFahrzeuge.vAktualisieren();
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug) {
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(std::move(pFahrzeug));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit) {
	pFahrzeug->vNeueStrecke(*this, dStartzeit);
	p_pFahrzeuge.push_front(std::move(pFahrzeug));
}

std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fahrzeug) {
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it) {
		if (it->get() && **it == fahrzeug) {
			std::unique_ptr<Fahrzeug> pTemp = std::move(*it);
			p_pFahrzeuge.erase(it);
			return pTemp;
		}
	}
	return nullptr;
}

Weg::Weg(std::string sName, double dLaenge, Tempolimit eTempolimit, bool bUeberholverbot, std::shared_ptr<const Kreuzung> pZielkreuzung) :
	Simulationsobjekt(sName),
	p_dLaenge(dLaenge),
	p_eTempolimit(eTempolimit),
	p_bUeberholverbot(bUeberholverbot),
	p_dVirtuelleSchranke(dLaenge),
	p_pZielkreuzung(pZielkreuzung)
{

}
