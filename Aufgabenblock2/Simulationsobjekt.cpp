/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 03.12.2025
 *      Author: sebastian
 */

#include "Simulationsobjekt.h"

double dGlobaleZeit = 0.0;
int Simulationsobjekt::p_iMaxID = 0;

void Simulationsobjekt::vKopf() {
	std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(4) << "ID" << std::setw(16) << "Name" << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) <<  std::setw(24) << "MaxGeschwindigkeit" << std::setw(16) << "Gesamtstrecke" << std::setw(16) << "Gesamtverbrauch" << std::setw(16) << "Tankinhalt" << std::setw(16) << "Geschwindigkeit" << std::endl;
	std::cout << std::setfill('-') << std::setw(108) << "" << std::setfill(' ') << std::endl;
}

void Simulationsobjekt::vAusgeben(std::ostream& os) const {
	os << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(4) << p_iID;
	os << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setw(16) << p_sName;
}

Simulationsobjekt& Simulationsobjekt::operator=(const Simulationsobjekt& other) {
	if (this == &other) {
		return *this;
	}

	this->p_dZeit = other.p_dZeit;

	return *this;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& other) const {
	return this->p_iID == other.p_iID;
}

Simulationsobjekt::Simulationsobjekt() :
	p_sName(""),
	p_iID(++p_iMaxID),
	p_dZeit(0.0)
{
	std::cout << "Simulationsobjekt (#" << p_iID << ") \"" << p_sName << "\" erstellt." << std::endl;
}


Simulationsobjekt::Simulationsobjekt(std::string sName) :
	p_sName(sName),
	p_iID(++p_iMaxID),
	p_dZeit(0.0)
{
	std::cout << "Simulationsobjekt (#" << p_iID << ") \"" << p_sName << "\" erstellt." << std::endl;
}

Simulationsobjekt::~Simulationsobjekt() {
	std::cout << "Simulationsobjekt (#" << p_iID << ") \"" << p_sName << "\" gelöscht." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Simulationsobjekt& simulationsobjekt) {
	simulationsobjekt.vAusgeben(os);
    return os;
}
