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
	string worldpath = name + "/";
	worldfile.open(worldpath + name);
	if (worldfile.fail()) {
		worldfile.close();
		cout << "Create your world " << name << "..." << endl;
		fs::create_directories("./" + name);
		ofstream worldfile;
		worldfile.open(worldpath + name);
		worldfile.close();
		createArea(name);


		cout << "Create people... \n";
		createPopulation(name);
	}
	else {
		cout << "This world already exist. \n Instead of creating a world, your world will be started...\n \n";
		cout << "Starting" + name + "...";
	}
}

//create the landarea
long long World::createArea(string name) {
	long long minPlan = 45364597917837;
	long long maxPlan = 64242428173257680;
	string worldpath = name + "/";

	srand(time(NULL));
	long long area = rand() % maxPlan + minPlan;
	ofstream worldfile;
	worldfile.open(worldpath + "area");
	worldfile << area;
	return area;
}

long long World::getArea(string name) {
	string worldpath = name + "/";
	ifstream worldfile;
	worldfile.open(worldpath + "area");
	string area_f;
	getline(worldfile, area_f);
	long long area = stoi(area_f);
	return area;
}

//create the population for a world based on the land area
long long World::createPopulation(string name) {
	srand(time(NULL));
	long long area = getArea(name);
	long long population;

	long long pop_rand = area / 100;
	population = rand() % area;

	string worldpath = name + "/";
	ofstream worldfile;
	worldfile.open(worldpath + "population");
	worldfile << population;
	worldfile.close();
	return population;
}


//return the population as an int
long long World::getPopulation(string name) {
	ifstream worldfile(name + "/" + name);
	string population_f;

	getline(worldfile, population_f);
	worldfile.close();
	long long population = stoi(population_f);
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


//calculate the population structure based on the population
string World::populationStructure(string name) {
	string tribe = tribe;
	string country = country;
	string continental = continental;


	long long area = getArea(name);
	long long population = getPopulation(name);
	int qm_index = area / population;
	if (qm_index < 200) {
		return continental;
	}
	else {
		if (qm_index < 200000) {
			return country;
		}
		else
		{
			return tribe;
		}
	}
}