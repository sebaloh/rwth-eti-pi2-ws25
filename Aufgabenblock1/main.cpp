/*
 * main.cpp
 *
 *  Created on: 06.11.2025
 *      Author: sebastian
 */

#include "Fahrzeug.h"
#include <memory>
#include <vector>

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

int main() {
	vAufgabe_1();
	return 0;
}
