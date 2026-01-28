/*
 * Kreuzung.cpp
 *
 *  Created on: 28.01.2026
 *      Author: sebastian
 */

#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "PKW.h"

void Kreuzung::vVerbinde(const std::string& sHinweg, const std::string& sRueckweg, double dLaenge, std::shared_ptr<Kreuzung> pStartKreuzung, std::shared_ptr<Kreuzung> pZielKreuzung, Tempolimit eTempolimit, bool bUeberholverbot) {
	std::shared_ptr<Weg> pHinweg = std::make_shared<Weg>(sHinweg, dLaenge, eTempolimit, bUeberholverbot, pZielKreuzung);

	std::shared_ptr<Weg> pRueckweg = nullptr;
	if (pZielKreuzung != nullptr)
	{
		pRueckweg = std::make_shared<Weg>(
		sRueckweg, dLaenge, eTempolimit, bUeberholverbot, pStartKreuzung);
	}

	if (pRueckweg)
	{
		pHinweg->setRueckweg(pRueckweg);
		pRueckweg->setRueckweg(pHinweg);
	}

	pStartKreuzung->vAddWeg(pHinweg);
	if (pZielKreuzung && pRueckweg)
	{
		pZielKreuzung->vAddWeg(pRueckweg);
	}
}

void Kreuzung::vTanken(Fahrzeug& fahrzeug)
{
	if (p_dTankstelle > 0.0)
	{
		double dGetankt = fahrzeug.dTanken(p_dTankstelle);
		p_dTankstelle -= dGetankt;
	}
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartzeit)
{
	vTanken(*pFahrzeug);

	if (!p_pWege.empty())
	{
		p_pWege.front()->vAnnahme(std::move(pFahrzeug), dStartzeit);
	}
}

void Kreuzung::vSimulieren()
{
    for (auto& pWeg : p_pWege)
    {
        pWeg->vSimulieren();
    }
}

void Kreuzung::vAddWeg(std::shared_ptr<Weg> pWeg)
{
    p_pWege.push_back(pWeg);
}

double Kreuzung::getTankstelle() {
	return p_dTankstelle;
}

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& weg) {
	std::vector<std::shared_ptr<Weg>> moeglicheWege;

	for (auto& w : p_pWege) {
		if (w.get() != weg.getRueckweg().get())
		{
			moeglicheWege.push_back(w);
		}
	}

	if (moeglicheWege.empty())
	{
		return weg.getRueckweg();
	}

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, moeglicheWege.size() - 1);

	return moeglicheWege[dis(gen)];
}

Kreuzung::Kreuzung(std::string sName, double dTankstelle) :
	Simulationsobjekt(sName),
	p_dTankstelle(dTankstelle)
{

}
