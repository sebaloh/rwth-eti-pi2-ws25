/*
 * Fahrrad.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {
public:
	Fahrrad(const std::string sName);
	Fahrrad(const std::string sName, const double dMaxGeschwindigkeit);

	void vAusgeben() const override;

	void vSimulieren() override;

	double dGeschwindigkeit() const override;
};

#endif /* FAHRRAD_H_ */
