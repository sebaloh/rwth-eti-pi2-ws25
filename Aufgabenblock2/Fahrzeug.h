/*
 * Fahrzeug.h
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include "Simulationsobjekt.h"
#include "SimuClient.h"
#include <limits>
#include <memory>

class Weg;
class Verhalten;

class Fahrzeug : public Simulationsobjekt {
protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;
	std::unique_ptr<Verhalten> p_pVerhalten;
public:
	virtual void vAusgeben(std::ostream& os) const override;

	virtual void vSimulieren() override;
	virtual void vZeichnen(const Weg& weg) const;

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;

	void vNeueStrecke(Weg& weg);
	void vNeueStrecke(Weg& weg, double dStartzeit);
	double dAbschnittStrecke() const;

	bool operator<(const Fahrzeug& other) const;

	Fahrzeug(const std::string sName);
	Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit);
	~Fahrzeug();
};

#endif /* FAHRZEUG_H_ */
