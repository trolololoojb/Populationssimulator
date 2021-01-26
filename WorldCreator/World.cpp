#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


#include "World.h"


using namespace std;


World::World(string name) {
	ifstream worldfile;
	string worldpath = name + "/" + name;
	worldfile.open(worldpath);
	if (worldfile.fail()) {
		worldfile.close();
		cout << "create your world " << name << "..." << endl;
		ofstream worldfile;
		worldfile.open(worldpath);
		worldfile << "Name:" << name << "\n";
		cout << "create people... \n";
		int population = 100;
		worldfile << "Start-Population:" << population << "\n";
		worldfile.close();
	}
	else {
		cout << "this world already exist \n";
	}
}

/*int World::createPopulation() {
	srand(time(NULL));
	int random = rand() % 1000;
	cout << random << "\n";
	int population;
	srand(time(NULL));
	random = random * rand() % 100000000;
	cout << random << "\n";

	population = random;

	cout << "population: " << population << "\n";
	return population;
}
*/
int World::getPopulation(string name) {
	ifstream worldfile(name + "/" + name);
	string dummy;
	string population;
	int i = 1;

	getline(worldfile, dummy);
	getline(worldfile, population);
	cout << population << endl;
	worldfile.close();


	return i;
}