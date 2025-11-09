/*
 * Fahrzeug.h
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

extern double dGlobaleZeit;

class Fahrzeug {
protected:
	static int p_iMaxID;

	const std::string p_sName;
	const int p_iID;

	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
public:
	static void vKopf();
	virtual void vAusgeben(std::ostream& os) const;

	virtual void vSimulieren();

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;

	bool operator<(const Fahrzeug& other) const;

	Fahrzeug(const Fahrzeug& other) = delete;
	Fahrzeug& operator=(const Fahrzeug& other);

	Fahrzeug();
	Fahrzeug(const std::string sName);
	Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
};

std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug);

#endif /* FAHRZEUG_H_ */
