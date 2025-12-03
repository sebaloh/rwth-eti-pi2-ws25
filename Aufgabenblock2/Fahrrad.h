/*
 * Fahrrad.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;

	double dGeschwindigkeit() const override;

	Fahrrad(const std::string sName, const double dMaxGeschwindigkeit);
};

#endif /* FAHRRAD_H_ */
