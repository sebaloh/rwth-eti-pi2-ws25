/*
 * main.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"
#include <memory>
#include <vector>
#include <limits>

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
		fahrzeug->vAusgeben(); std::cout << '\n';
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
			fahrzeug->vAusgeben(); std::cout << '\n';
		}
	}

	std::cout << "---- Simulationsende ----" << std::endl;
}

int main() {
	vAufgabe_1a();
	return 0;
}
