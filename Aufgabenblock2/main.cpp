/*
 * main.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include <memory>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
extern double dGlobaleZeit;
double dEpsilon = 0.001;

void vAufgabe_1() {
	Fahrzeug sFahrzeug("statisches_Fahrzeug");
	Fahrzeug* dFahrzeug = new Fahrzeug("dynamisches_Fahrzeug");

	std::unique_ptr<Fahrzeug> upFahrzeug1 = std::make_unique<Fahrzeug>("unique_Fahrzeug_1");
	std::unique_ptr<Fahrzeug> upFahrzeug2 = std::make_unique<Fahrzeug>("unique_Fahrzeug_2");

	std::shared_ptr<Fahrzeug> spFahrzeug1 = std::make_shared<Fahrzeug>("shared_Fahrzeug_1");
	std::shared_ptr<Fahrzeug> spFahrzeug2 = std::make_shared<Fahrzeug>("shared_Fahrzeug_2");

	std::shared_ptr<Fahrzeug> spFahrzeugKopie = spFahrzeug1;
	std::cout << "Anzahl der Referenzen für shared_Fahrzeug_1: " << spFahrzeug1.use_count() << std::endl;

	std::unique_ptr<Fahrzeug> upFahrzeugKopie = std::move(upFahrzeug1);
	std::cout << "Zeiger für unique_Fahrzeug_1 = nullptr? " << (upFahrzeug1== nullptr ? "Ja" : "Nein") << std::endl;

	std::vector<std::unique_ptr<Fahrzeug>> v_upFahrzeug;
	v_upFahrzeug.push_back(std::move(upFahrzeug1));
	v_upFahrzeug.push_back(std::move(upFahrzeug2));
	std::cout << "v_upFahrzeug Groesse: " << v_upFahrzeug.size() << std::endl;
	v_upFahrzeug.clear(); // upFahrzeug2 wird gelöscht; upFahrzeug1 lebt in Kopie

	std::vector<std::shared_ptr<Fahrzeug>> v_spFahrzeug;
	v_spFahrzeug.push_back(std::move(spFahrzeug1));
	v_spFahrzeug.push_back(spFahrzeug2);
	std::cout << "Anzahl der Referenzen für shared_Fahrzeug_1: " << spFahrzeug1.use_count() << std::endl;
	std::cout << "Anzahl der Referenzen für shared_Fahrzeug_2: " << spFahrzeug2.use_count() << std::endl;

	v_spFahrzeug.clear(); // spFahrzeug2 nur Reverenz lebt noch; spFahrzeug1 lebt noch in Kopie

	delete dFahrzeug;
	dFahrzeug = nullptr;
}

void vAufgabe_1a() {
	std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;

	std::string sName = "";
	double dMaxGeschwindigkeit = 0.0;

	for (int i = 0; i < 3; ++i) {
		std::cout << "--- Eingabe Fahrzeug #" << i + 1 << " ---" << std::endl;

		std::cout << "Name des Fahrzeugs: ";
		std::getline(std::cin, sName);

		std::cout << "Geschwindigkeit des Fahrzeugs: ";
		while(!(std::cin >> dMaxGeschwindigkeit)) {
			std::cout << "Gebe eine gueltige Geschwindigkeit ein: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		vFahrzeuge.push_back(std::make_unique<Fahrzeug>(sName, dMaxGeschwindigkeit));
	}

	Fahrzeug::vKopf();
	for (const auto& fahrzeug : vFahrzeuge) {
		std::cout << *fahrzeug << '\n';
	}

	std::cout << "---- Simulationsstart ----" << std::endl;

	const double dSimulationsdauer= 5.0;
	const double dSimulationsschritt = 0.5;

	Fahrzeug::vKopf();

	for (double t = 0.0; t <= dSimulationsdauer; t += dSimulationsschritt) {
		dGlobaleZeit = t;

		std::cout << "--------------------------- " << t << " ---------------------------" << std::endl;

		for (const auto& fahrzeug : vFahrzeuge) {
			fahrzeug->vSimulieren();
			std::cout << *fahrzeug << '\n';
		}
	}

	std::cout << "---- Simulationsende ----" << std::endl;
}

void vAufgabe_2() {
	std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;

	int iAnzahl = 0;
	int iTanken = 0;
	int iTyp = 0; //1 = PKW, 2 = Fahrrad
	std::string sName = "";
	double dMaxGeschwindigkeit = 0.0;
	double dVerbrauch = 0.0;
	double dTankvolumen = 0.0;

	std::cout << "Anzahl der Fahrzeuge: ";
	while(!(std::cin >> iAnzahl)) {
		std::cout << "Gebe eine gueltige Zahl ein: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Tanken nach Stunden: ";
	while(!(std::cin >> iTanken)) {
		std::cout << "Gebe eine gueltige Zahl ein: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < iAnzahl; ++i) {
		std::cout << "--- Eingabe Fahrzeug #" << i + 1 << " ---" << std::endl;

		std::cout << "Fahrzeugtyp (1 = PKW, 2 = Fahrrad): ";
		while(!(std::cin >> iTyp) || !((iTyp == 1) || (iTyp == 2))) {
			std::cout << "Gebe einen gueltigen Typ ein: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Name des Fahrzeugs: ";
		std::getline(std::cin, sName);

		std::cout << "Geschwindigkeit des Fahrzeugs: ";
		while(!(std::cin >> dMaxGeschwindigkeit)) {
			std::cout << "Gebe eine gueltige Geschwindigkeit ein: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (iTyp == 1) {
			std::cout << "Verbrauch des Fahrzeugs: ";
			while(!(std::cin >> dVerbrauch)) {
				std::cout << "Gebe einen gueltigen Verbrauch ein: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Tankvolumen des Fahrzeugs: ";
			while(!(std::cin >> dTankvolumen)) {
				std::cout << "Gebe ein gueltiges Tankvolumen ein: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (iTyp == 1){
			vFahrzeuge.push_back(std::make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen));
		} else {

			vFahrzeuge.push_back(std::make_unique<Fahrrad>(sName, dMaxGeschwindigkeit));
		}
	}

	Fahrzeug::vKopf();
	for (const auto& fahrzeug : vFahrzeuge) {
		std::cout << *fahrzeug << '\n';
	}

	std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-                                             Simulationsstart                                             -" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;

	const double dSimulationsdauer= 10.0;
	const double dSimulationsschritt = 0.5;

	Fahrzeug::vKopf();

	for (double t = 0.0; t <= dSimulationsdauer; t += dSimulationsschritt) {
		dGlobaleZeit = t;

		std::cout << "--------------------------------------------------- " << t << " ---------------------------------------------------" << std::endl;

		for (const auto& fahrzeug : vFahrzeuge) {
			if (std::fabs(t - iTanken) < 0.2 && std::fabs(t - iTanken) > -0.2) {
				fahrzeug->dTanken();
			} else {
				fahrzeug->vSimulieren();
			}
			std::cout << *fahrzeug << '\n';
		}
	}

	std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-                                             Simulationsende                                              -" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
}

void vAufgabe_3() {
	Fahrzeug::vKopf();

	PKW pOriginal("Original", 160.0, 20.0, 60.0);
	pOriginal.vSimulieren();
	dGlobaleZeit = 1;
	pOriginal.vSimulieren();
	/*PKW pKopie("Kopie", 100.0, 10.0, 80.0);
	pKopie = pOriginal;
	std::cout << pKopie << std::endl;*/

	PKW pAuto("Auto", 160.0, 20.0, 60.0);
	Fahrrad fRennrad("Rennrad", 60.0);
	pAuto.vSimulieren();
	fRennrad.vSimulieren();
	if (fRennrad < pAuto) {
		std::cout << pAuto << std::endl << fRennrad << std::endl;
		std::cout << "True" << std::endl;
	}
}

void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{13};
    double dTakt = 0.4;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 217.0, 10.7, 55));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 21.4));
    for (dGlobaleZeit = 0; dGlobaleZeit < 6; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}

void vAufgabe_4() {
	Weg bundesstrasse ("B70", 100.0, Tempolimit::Landstrasse);

	std::unique_ptr<Fahrzeug> rennrad = std::make_unique<Fahrrad>("Rennrad", 40.0);
	std::unique_ptr<Fahrzeug> pkw = std::make_unique<PKW>("PKW", 160.0, 10.0, 60.0);
	std::unique_ptr<Fahrzeug> lkw = std::make_unique<PKW>("LKW", 80.0, 20.0, 100.0);

	bundesstrasse.vAnnahme(std::move(rennrad));
	bundesstrasse.vAnnahme(std::move(pkw));
	bundesstrasse.vAnnahme(std::move(lkw));

	Weg::vKopf();

	double dTakt = 0.5;
	double dDauer = 5.0;

	for (dGlobaleZeit = 0.0; dGlobaleZeit < dDauer; dGlobaleZeit += dTakt) {
		bundesstrasse.vSimulieren();
		std::cout << bundesstrasse << std::endl;
	}
}

void vAufgabe_5() {
	Weg bundesstrasse ("B70", 100.0, Tempolimit::Landstrasse);

	std::unique_ptr<Fahrzeug> rennrad = std::make_unique<Fahrrad>("Rennrad", 40.0);
	std::unique_ptr<Fahrzeug> pkw = std::make_unique<PKW>("PKW", 160.0, 10.0, 60.0);
	std::unique_ptr<Fahrzeug> lkw = std::make_unique<PKW>("LKW", 80.0, 20.0, 100.0);
	std::unique_ptr<Fahrzeug> parkenderPKW = std::make_unique<PKW>("parkenderPKW", 80.0, 20.0, 100.0);

	Weg::vKopf();

	bundesstrasse.vAnnahme(std::move(rennrad));
	bundesstrasse.vAnnahme(std::move(pkw));
	bundesstrasse.vAnnahme(std::move(lkw));
	bundesstrasse.vAnnahme(std::move(parkenderPKW), 2.0);

	std::cout << bundesstrasse << std::endl;

	double dTakt = 0.5;
	double dDauer = 5.0;

	for (dGlobaleZeit = 0.0; dGlobaleZeit < dDauer; dGlobaleZeit += dTakt) {
		bundesstrasse.vSimulieren();
		std::cout << bundesstrasse << std::endl;
	}
}


int main() {
	vAufgabe_5();
	return 0;
}
