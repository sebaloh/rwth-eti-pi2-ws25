/*
 * Fahrausnahme.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception>
#include <iostream>

class Fahrzeug;
class Weg;

class Fahrausnahme : public std::exception {
protected:
	Fahrzeug& p_Fahrzeug;
	Weg& p_Weg;
public:
	virtual void vBearbeiten() = 0;

	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Fahrausnahme();
};

#endif /* FAHRAUSNAHME_H_ */
