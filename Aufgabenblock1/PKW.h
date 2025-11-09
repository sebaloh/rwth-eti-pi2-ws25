/*
 * PKW.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug {
private:
	double p_dVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
public:
	PKW(const std::string sName);
	PKW(const std::string sName, const double dMaxGeschwindigkeit);
	PKW(const std::string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen);

	void vAusgeben() const override;

	void vSimulieren() override;

	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
};

#endif /* PKW_H_ */
