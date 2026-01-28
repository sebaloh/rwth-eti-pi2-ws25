/*
 * Fahren.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"
#include "Streckenende.h"

class Weg;
class Fahrzeug;

class Fahren : public Verhalten {
public:
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;

	Fahren(Weg& weg);
	virtual ~Fahren();
};

#endif /* FAHREN_H_ */
