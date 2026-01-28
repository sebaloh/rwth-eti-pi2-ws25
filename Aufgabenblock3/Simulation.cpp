/*
 * Simulation.cpp
 *
 *  Created on: 28.01.2026
 *      Author: sebastian
 */

#include "Simulation.h"

extern double dGlobaleZeit;

void Simulation::vEinlesen(std::istream& is, bool bMitGrafik) {
	std::string sZeile;
	int iZeile = 0;

	try {
		while (std::getline(is, sZeile)) {
			iZeile++;

			if(sZeile.empty()) {
				continue;
			}

			std::istringstream iss(sZeile);
			std::string sTyp;
			iss >> sTyp;

			if (sTyp == "KREUZUNG") {
				std::string sName;
				double dTankstelle;

				iss >> sName >> dTankstelle;

				std::shared_ptr<Kreuzung> pKreuzung = std::make_shared<Kreuzung>(sName, dTankstelle);
				p_kreuzungen[sName] = pKreuzung;

				if (bMitGrafik) {
					int iPosX, iPosY;
					iss >> iPosX >> iPosY;
					bZeichneKreuzung(iPosX, iPosY);
				}
			}
			else if (sTyp == "STRASSE") {
				std::string sNameQ, sNameZ, sNameW1, sNameW2;
				double dLaenge;
				int iTempolimit;
				bool bUeberholverbot;

				iss >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> dLaenge >> iTempolimit >> bUeberholverbot;

				std::map<std::string, std::shared_ptr<Kreuzung>>::iterator itQ = p_kreuzungen.find(sNameQ);
				std::map<std::string, std::shared_ptr<Kreuzung>>::iterator itZ = p_kreuzungen.find(sNameZ);

				if (itQ == p_kreuzungen.end()) {
					throw std::runtime_error("Quellkreuzung '" + sNameQ + "' nicht gefunden");
				}

				if (itZ == p_kreuzungen.end()) {
					throw std::runtime_error("Zielkreuzung '" + sNameZ + "' nicht gefunden");
				}

				Tempolimit eTempolimit;
				switch (iTempolimit) {
				case 1:
					eTempolimit = Tempolimit::Innerorts;
					break;
				case 2:
					eTempolimit = Tempolimit::Landstrasse;
					break;
				case 3:
					eTempolimit = Tempolimit::Autobahn;
					break;
				default:
					throw std::runtime_error("Ungültiges Tempolimit: " + std::to_string(iTempolimit));
				}

				Kreuzung::vVerbinde(sNameW1, sNameW2, dLaenge, itQ->second, itZ->second, eTempolimit, bUeberholverbot);

				if (bMitGrafik) {
					int iAnzahlKoordinaten;
					iss >> iAnzahlKoordinaten;

					int iAnzahlWerte = iAnzahlKoordinaten * 2;
					int* pKoordinaten = new int[iAnzahlWerte];
					for (int i = 0; i < iAnzahlKoordinaten * 2; ++i) {
						iss >> pKoordinaten[i];
					}

					bZeichneStrasse(sNameW1, sNameW2, static_cast<int>(dLaenge), iAnzahlKoordinaten, pKoordinaten);
					delete[] pKoordinaten;
				}
			}
			else if (sTyp == "PKW") {
				std::string sName, sNameS;
				double dMaxGeschwindigkeit, dVerbrauch, dTankvolumen, dStartzeit;

				iss >> sName >> dMaxGeschwindigkeit >> dVerbrauch >> dTankvolumen >> sNameS >> dStartzeit;

				std::unique_ptr<PKW> pPKW = std::make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen);

				std::map<std::string, std::shared_ptr<Kreuzung>>::iterator it = p_kreuzungen.find(sNameS);
				if (it == p_kreuzungen.end()) {
					throw std::runtime_error("Startkreuzung '" + sNameS + "' nicht gefunden");
				}

				it->second->vAnnahme(std::move(pPKW), dStartzeit);
			}
			else if (sTyp == "FAHRRAD") {
				std::string sName, sNameS;
				double dMaxGeschwindigkeit, dStartzeit;

				iss >> sName >> dMaxGeschwindigkeit >> sNameS >> dStartzeit;

				std::unique_ptr<Fahrrad> pFahrrad = std::make_unique<Fahrrad>(sName, dMaxGeschwindigkeit);

				std::map<std::string, std::shared_ptr<Kreuzung>>::iterator it = p_kreuzungen.find(sNameS);
				if (it == p_kreuzungen.end()) {
					throw std::runtime_error("Startkreuzung '" + sNameS + "' nicht gefunden");
				}

				it->second->vAnnahme(std::move(pFahrrad), dStartzeit);
			}
			else {
				throw std::runtime_error("Unbekannter Objekttyp '" + sTyp + "'");
			}
		}
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Fehler in Zeile " + std::to_string(iZeile) + ": " + e.what());
	}
}

void Simulation::vSimulieren(double dDauer, double dTakt) {
	for (dGlobaleZeit = 0; dGlobaleZeit < dDauer; dGlobaleZeit += dTakt) {
		for (auto& [sName, pKreuzung] : p_kreuzungen) {
			pKreuzung->vSimulieren();
		}

		vSleep(100);
	}
}
