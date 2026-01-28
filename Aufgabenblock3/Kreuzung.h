/*
 * Kreuzung.h
 *
 *  Created on: 28.01.2026
 *      Author: sebastian
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_

#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include <list>
#include <memory>
#include <string>
#include <random>

class Weg;
class Fahrzeug;

class Kreuzung : public Simulationsobjekt {
private:
	std::list<std::shared_ptr<Weg>> p_pWege;
	double p_dTankstelle;
public:
	static void vVerbinde(const std::string& sHinweg, const std::string& sRueckweg, double dLaenge, std::shared_ptr<Kreuzung> pStartKreuzung, std::shared_ptr<Kreuzung> pZielKreuzung, Tempolimit eTempolimit = Tempolimit::Autobahn, bool bUeberholverbot = true);

	void vTanken(Fahrzeug& fahrzeug);

	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit);

	void vSimulieren();

	double getTankstelle();

	void vAddWeg(std::shared_ptr<Weg> pWeg);

	std::shared_ptr<Weg> pZufaelligerWeg(Weg& weg);

	Kreuzung(std::string sName, double dTankstelle = 0.0);
};

#endif /* KREUZUNG_H_ */
