/*
 * Streckenende.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme {
public:
	void vBearbeiten() override;

	Streckenende(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Streckenende();
};

#endif /* STRECKENENDE_H_ */
