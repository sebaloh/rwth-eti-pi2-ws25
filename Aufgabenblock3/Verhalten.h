/*
 * Verhalten.h
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

class Weg;
class Fahrzeug;

class Verhalten {
protected:
	Weg& p_Weg;
public:
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;

	Verhalten(Weg& weg);
	virtual ~Verhalten();
};

#endif /* VERHALTEN_H_ */
