#include <iostream>
#include <string>
#include <unistd.h>

#include "World.h"
#include "Visualizing.h"


using namespace std;



int main() {
	string name;
	cout << "Starting world engine... \n Give your world a name:\n" << endl;
	cin >> name;
	World World(name);
	cout << World.getPopulation(name);
	int active = 1;
	while (active == 1)
	{
		cout << "Menu:\n";
		cout << "1. Get your current population.\n";
		cout << "2. Get your current planet age.\n";
		cout << "3. Get your current population structure.\n";
		cout << "4. Go ""x"" years in the future.\n\n";
		cout << "Type a random letter for shutdown.\n\n";
		cout << "Input: ";
		int menu;
		cin >> menu;
		switch (menu) {

			case 1:
				cout << "The population of " + name + " is ";
				cout << World.getPopulation(name);
				cout << ".\n\n";
				break;

			case 2:
			{
				cout << "The age of " + name + " is ";
				cout << World.getYear(name);
				cout << ".\n\n";
				break;
			}
			case 3:
				cout << "The current poulation structure on " + name + " is " << World.populationStructure(name) + ".\n\n";
				cout << "Continental means, that this planet have enough life forms for a structure apart from countrys.\nThey have continents instead of countrys.\n\n";
				cout << "Country means, that this planett have enough life forms for a country culture.\n\n";
				cout << "Tribe means, that this planet doesn't have enough life forms for a country culture.\n\n";
				break;
			case 4:
				cout << "How many years do you want to go in the future?\n\n";
				int years;
				cin >> years;
				for (int i = 0; i < years; i++) {
					World.yearPlanet(name);
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