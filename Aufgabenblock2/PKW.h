/*
 * PKW.h
 *
 *  Created on: 08.11.2025
 *      Author: sebastian
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Weg.h"

class PKW : public Fahrzeug {
private:
	double p_dVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
public:
	void vAusgeben(std::ostream& os) const override;

	void vSimulieren() override;
	void vZeichnen(const Weg& weg) const override;

	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

	double dTankinhalt() const;

	PKW(const std::string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen);
};

#endif /* PKW_H_ */
