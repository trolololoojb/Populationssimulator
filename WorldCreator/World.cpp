#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <stdlib.h>
#include <unistd.h>

#include "World.h"
#include "Visualizing.h"

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
		sleep(3);
		setYear(name);
		Visualizing Planet;
		Planet.rotateWorld();
		ofstream worldfile;
		worldfile.open(worldpath + "name");
		worldfile << name;
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

//get the area of the world
long long World::getArea(string name) {
	string worldpath = name + "/";
	ifstream worldfile;
	worldfile.open(worldpath + "area");
	string area_f;

	getline(worldfile, area_f);
	
	long long area;

	std::string::size_type sz = 0;   // alias of size_t

	while (!area_f.empty()) {
		area = std::stoll(area_f, &sz, 0);
		area_f = area_f.substr(sz);
	}

	return area;
}

//create the population for a world based on the land area
long long World::createPopulation(string name) {
	srand(time(NULL));
	long long area = getArea(name);
	long long population;

	long long pop_rand = area / 100;
	population = rand() % pop_rand;

	string worldpath = name + "/";
	ofstream worldfile;
	worldfile.open(worldpath + "population");
	worldfile << population;
	worldfile.close();
	return population;
}


//return the population as an int
long long World::getPopulation(string name) {
	ifstream worldfile(name + "/" + "population");
	string population_f;
	getline(worldfile, population_f);
	worldfile.close();
	long long population;

	std::string::size_type sz = 0;   // alias of size_t

	while (!population_f.empty()) {
		population = std::stoll(population_f, &sz, 0);
		population_f = population_f.substr(sz);
	}
	return population;
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

//add the population of one year based on the populationfactor
void World::plusPopulation(string name) {
	string worldpath = name + "/";
	long long population = getPopulation(name);
	float bornrate = 0.0045;
	
	long long pop_plus = population / 100 * bornrate;
	population = population + pop_plus;
	ofstream worldfile;
	worldfile.open(worldpath + "population");
	worldfile << population;
	worldfile.close();
}

//dedut the population of one year based on the populationfactor
void World::minusPopulation(string name) {
	string worldpath = name + "/";
	long long population = getPopulation(name);
	float deathrate = 0.002;;

	long long pop_plus = population / 100 * deathrate;
	population = population - pop_plus;
	ofstream worldfile;
	worldfile.open(worldpath + "population");
	worldfile << population;
	worldfile.close();
}

void World::setYear(string name) {
	srand(time(NULL));
	int year = rand() % 43000000 + 42000000;
	string worldpath = name + "/";
	ofstream worldfile;
	worldfile.open(worldpath + "year");
	worldfile << year;
	worldfile.close();
}

//simulate one year on this planet
void World::yearPlanet(string name) {
	plusPopulation(name);
	minusPopulation(name);
}
