#include <iostream>
#include <string>
#include <unistd.h>

#include "World.h"
#include "Visualizing.h"
#include "Interface.h"

Interface::Interface(string name) {
	World Planet(name);
	int active = 1;
	while (active == 1)
	{
		cout << "Menu:\n";
		cout << "1. Get your current population.\n";
		cout << "2. Get your current planet age.\n";
		cout << "3. Get your current population structure.\n";
		cout << "4. Go ""x"" years in the future.\n";
		cout << "5. Get your technology level.\n\n";
		cout << "Type a random letter for shutdown.\n\n";
		cout << "Input: ";
		int menu;
		cin >> menu;
		switch (menu) {

		case 1:
			cout << "The population of " + name + " is ";
			cout << Planet.getPopulation(name);
			cout << ".\n\n";
			break;

		case 2:
		{
			cout << "The age of " + name + " is ";
			cout << Planet.getYear(name);
			cout << ".\n\n";
			break;
		}
		case 3:
			populationStructure(Planet, name);
			break;
		case 4:
			cout << "How many years do you want to go in the future?\n\n";
			int years;
			cin >> years;
			for (int i = 0; i < years; i++) {
				Planet.yearPlanet(name);
			}
			break;
		default:
			cout << "shutdown.\n";
			sleep(1);
			cout << "shutdown..\n";
			sleep(1);
			cout << "shutdown...\n";
			sleep(1);
			active = 0;
			break;
		}
	}
}

void Interface::populationStructure(World Planet, string name) {
	cout << "The current poulation structure on " + name + " is " << Planet.populationStructure(name) + ".\n\n";
	cout << "Continental means, that this planet have enough life forms for a structure apart from countrys.\nThey have continents instead of countrys.\n\n";
	cout << "Country means, that this planett have enough life forms for a country culture.\n\n";
	cout << "Tribe means, that this planet doesn't have enough life forms for a country culture.\n\n";
}

void Interface::menuTechnologylevel(World Planet, string name) {
	int tech = Planet.getTechnology(name);
	cout << "Your technology level is """ + tech; +".""";
	cout << ".\n Do you want to know what's the point behind this level? \nIf yes type 1 and confirm. A random letter to go back in the menu.\n";
	cout << "Input: ";
	int yes;
	cin >> yes;
	if (yes == 1) {
		cout << "We have five technology level.\n\nLevel 1: Middle Age. \n(Knights, Castles, No fire weapons)\n\nLevel 2: Industrial Age. \n(Factorys, Fire Weapons, environmental pollution, better means of transport than horses)\n\n";
		cout << "Level 3: Atom Age. \n(More clean Energy, High envolved Weapons, Planes, first thoughts about the space)\n\n";
		cout << "Level 4: Space Age. \n (Your population made it into the space, a lot of research for the space technologys, new problems like climatechange, bigger weapons and pandemics)\n\n";
		cout << "Level 5: Space Travel Age. \n (Your population has reached the ability to travel to other planets and live there)";
	}
}