#include <iostream>
#include <string>

#include "World.h"
#include "Visualizing.h"


using namespace std;



int main() {
	string name;
	cout << "Starting world engine... \n Give your world a name:\n" << endl;
	cin >> name;
	World Planet(name);
	int active = 1;
	int menu;
	while (active == 1)
	{
		cout << "You have following options:\n";
		cout << "1. Get your current population.\n";
		cout << "2. Get your current planet age.\n";
		cout << "3. Get your current population structure.\n";
		cout << "4. Go ""x"" years in the future.\n";
		cout << "random letter for shutdown\n";

		cin >> menu;
		switch (menu) {

		case 1:
			cout << "The population of " + name + " is " << Planet.getPopulation(name) + "\n";
			break;

		case 2:
			cout << "The age of " + name + " is ";
		}

	}
}