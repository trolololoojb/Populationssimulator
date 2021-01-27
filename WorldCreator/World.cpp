#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <filesystem>

#include "World.h"

namespace fs = std::filesystem;
using namespace std;

//creates a world folder or load a existing world
World::World(string name) {
	ifstream worldfile;
	string worldpath = name + "/" + name;
	worldfile.open(worldpath);
	if (worldfile.fail()) {
		worldfile.close();
		cout << "Create your world " << name << "..." << endl;
		fs::create_directories("./" + name);
		ofstream worldfile;
		worldfile.open(worldpath);
		worldfile << "Name:" << name << "\n";
		cout << "Create people... \n";
		int population = createPopulation();
		worldfile << population << "\n";
		worldfile.close();
	}
	else {
		cout << "This world already exist. \n Instead of creating a world, your world will be started...\n \n";
		cout << "Starting" + name;
	}
}

//create the population for a world 
int World::createPopulation() {
	srand(time(NULL));
	int random = rand() % 1000;
	cout << random << "\n";
	int population;
	srand(time(NULL));
	random = random * rand() % 100000000;
	cout << random << "\n";
	int random_mod = random % 2;

	population = random;

	cout << "population: " << population << "\n";
	return population;
}


//return the population as an int
int World::getPopulation(string name) {
	ifstream worldfile(name + "/" + name);
	string dummy;
	string population_f;

	getline(worldfile, dummy);
	getline(worldfile, population_f);
	worldfile.close();
	int population = stoi(population_f);
	return population;
}

//timer for the seconds. One second means one year.
void World::worldtime(int a, int year) {


	for (int i; i < year; i++) {
		time_t akttime = time(NULL);
		while (akttime == time(NULL)) {
			;
		}
		a = a + 1;
		akttime += 1;
		year += 1;
		cout << a << "Jahr(e) \n";
		//worldtime(a);
	}
	cout << "Es ist das Jahr " << year << "und es sind " << a << "Jahre vergangen \n";
}
