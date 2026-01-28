/*
 * Simulationsobjekt.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_

#include <string>
#include <iostream>
#include <iomanip>

extern double dGlobaleZeit;

class Simulationsobjekt {
protected:
	static int p_iMaxID;

	const std::string p_sName;
	const int p_iID;
	double p_dZeit;
public:
	static void vKopf();
	virtual void vAusgeben(std::ostream& os) const;

	// Reine virtuelle Simulationsmethode
	virtual void vSimulieren() = 0;

	// Getter
	std::string getName() const;
	int getID() const;

	// Kopier-Konstruktor
	Simulationsobjekt(const Simulationsobjekt& other) = delete;

	// Zuweisungsoperator
	Simulationsobjekt& operator=(const Simulationsobjekt& other);

	// Vergleichsoperator (nach ID)
	bool operator==(const Simulationsobjekt& other) const;

	Simulationsobjekt();
	Simulationsobjekt(std::string sName);
	virtual ~Simulationsobjekt();
};

// Ausgabeoperator
std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& simulationsobjekt);

#endif /* SIMULATIONSOBJEKT_H_ */
