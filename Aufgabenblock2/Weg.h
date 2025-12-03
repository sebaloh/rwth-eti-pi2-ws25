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
#include <list>
#include <memory>
#include <limits>

class Fahrzeug;

class Weg : public Simulationsobjekt {
private:
	double p_dLaenge;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;
public:
	static void vKopf();
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;

	double dLaenge() const;

	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit);
	double getTempolimit() const;

	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
};

#endif /* WEG_H_ */
