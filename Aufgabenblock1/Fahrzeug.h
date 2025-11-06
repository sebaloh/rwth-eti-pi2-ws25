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

class Fahrzeug {
private:
	static int p_iMaxID;

	const std::string p_sName;
	const int p_iID;

	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
public:
	Fahrzeug();
	Fahrzeug(const std::string sName);
	Fahrzeug(const std::string sName, const double dMaxGeschwindigkeit);
	virtual ~Fahrzeug();
};

#endif /* FAHRZEUG_H_ */
