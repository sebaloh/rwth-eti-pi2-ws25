/*
 * Simulation.h
 *
 *  Created on: 28.01.2026
 *      Author: sebastian
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <istream>
#include <iostream>
#include <stdexcept>
#include <map>
#include "Kreuzung.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"

class Simulation {
private:
	std::map<std::string, std::shared_ptr<Kreuzung>> p_kreuzungen;
public:
	void vEinlesen(std::istream& is, bool bMitGrafik = false);
	void vSimulieren(double dDauer, double dTakt);

	Simulation() = default;
	~Simulation() = default;
};

#endif /* SIMULATION_H_ */
