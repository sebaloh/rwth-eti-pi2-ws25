/*
 * Fahrzeug.h
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include "Simulationsobjekt.h"
#include <limits>

class Fahrzeug : public Simulationsobjekt {
protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
public:
	virtual void vAusgeben(std::ostream& os) const override;

	virtual void vSimulieren() override;

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;

	std::string sName() const;

	bool operator<(const Fahrzeug& other) const;

	Fahrzeug(const std::string sName);
	Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit);
};

#endif /* FAHRZEUG_H_ */
