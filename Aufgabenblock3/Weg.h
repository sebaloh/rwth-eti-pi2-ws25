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
class Kreuzung;

class Weg : public Simulationsobjekt {
private:
	double p_dLaenge;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit;
	bool p_bUeberholverbot;
	double p_dVirtuelleSchranke;
	std::weak_ptr<const Kreuzung> p_pZielkreuzung;
	std::weak_ptr<Weg> p_pRueckweg;
public:
	static void vKopf();
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;

	// Getter
	double getLaenge() const;
	double getTempolimit() const;
	double getVirtuelleSchranke() const;

	std::shared_ptr<const Kreuzung> getZielkreuzung() const;
	std::shared_ptr<Weg> getRueckweg() const;
	void setRueckweg(std::shared_ptr<Weg> pRueckweg);

	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit);
	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);

	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn, bool bUeberholen = true, std::shared_ptr<const Kreuzung> pZielkreuzung = nullptr);
};

#endif /* WEG_H_ */
