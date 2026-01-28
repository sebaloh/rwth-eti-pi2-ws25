/*
 * Fahrrad.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Weg.h"

class Fahrrad : public Fahrzeug {
public:
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;
	void vZeichnen(const Weg& weg) const override;

	// Getter (nicht gleich p_dMaxGeschwindigkeit)
	double getGeschwindigkeit() const override;

	Fahrrad(const std::string sName, const double dMaxGeschwindigkeit);
};

#endif /* FAHRRAD_H_ */
