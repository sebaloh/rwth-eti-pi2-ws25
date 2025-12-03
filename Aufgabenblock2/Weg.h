/*
 * Weg.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef WEG_H_
#define WEG_H_

#include "Simulationsobjekt.h"
#include "Fahrausnahme.h"
#include "Tempolimit.h"
#include "vertagt_liste.h"
#include <list>
#include <memory>
#include <limits>

class Fahrzeug;

class Weg : public Simulationsobjekt {
private:
	double p_dLaenge;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;
public:
	static void vKopf();
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;

	// Getter
	double getLaenge() const;
	double getTempolimit() const;

	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit);
	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);

	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
};

#endif /* WEG_H_ */
