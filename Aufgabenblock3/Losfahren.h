/*
 * Losfahren.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {
public:
	void vBearbeiten() override;

	Losfahren(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Losfahren();
};

#endif /* LOSFAHREN_H_ */
