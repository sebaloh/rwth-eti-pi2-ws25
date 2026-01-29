/*
 * Parken.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"
#include "Losfahren.h"
#include "Streckenende.h"

class Parken : public Verhalten {
private:
    double p_dStartzeit;
public:
    double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;

	Parken(Weg& weg, double dStartzeit);
	virtual ~Parken();
};

#endif /* PARKEN_H_ */
