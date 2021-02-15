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
		sleep(2);
		setYear(name);
		Visualizing Planet;
		Planet.rotateWorld();
		ofstream worldfile;
		worldfile.open(worldpath + name);
		worldfile << name;
		worldfile.close();
		createArea(name);
		cout << "Create people... \n";
		sleep(2);
		Planet.createPeople();
		createPopulation(name);


	}
	else {
		cout << "This world already exist. \nInstead of creating a world, your world will be started...\n \n";
		cout << "Starting " + name + "...\n";
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
	worldfile.close();
	return area;
}

//get the area of the world
long long World::getArea(string name) {
	string worldpath = name + "/";
	ifstream worldfile;
	worldfile.open(worldpath + "area");
	string area_f;

	getline(worldfile, area_f);
	worldfile.close();
	long long area;

	area = std::stoll(area_f, NULL, 0);

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
	

	population = std::stoll(population_f, NULL, 0);

	return population;
}

//calculate the population structure based on the population
string World::populationStructure(string name) {
	string tribe = "tribe";
	string country = "country";
	string continental = "continental";


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

	ifstream pandemicfile;
	string pan_f;
	getline(pandemicfile, pan_f);
	int pan = stoi(pan_f);
	long long pop_min = population / 100 * deathrate;
	pop_min *= pan;
	population = population - pop_min;
	ofstream worldfile;
	worldfile.open(worldpath + "population");
	worldfile << population;
	worldfile.close();
}

void World::setYear(string name) {
	srand(time(NULL));
	long long year = rand() % 43000000 + 42000000;
	string worldpath = name + "/";
	ofstream worldfile;
	worldfile.open(worldpath + "year");
	worldfile << year;
	worldfile.close();
}

void World::plusYear(string name) {
	long long akt_year = getYear(name);
	akt_year = akt_year + 1;
	string worldpath = name + "/";
	ofstream worldfile;
	worldfile.open(worldpath + "year");
	worldfile << akt_year;
	worldfile.close();
}

//simulate one year on this planet
void World::yearPlanet(string name) {
	setTechnology(name);
	pandemic(name);
	plusPopulation(name);
	minusPopulation(name);
	plusYear(name);
}

//return the age of the planet
long long World::getYear(string name) {
	ifstream worldfile(name + "/" + "year");
	string year_f;
	getline(worldfile, year_f);
	worldfile.close();

	long long year;


	year = std::stoll(year_f, NULL, 0);

	return year;
}

//create a random number and decide about a pandemic
void World::pandemic(string name) {
	srand(time(NULL));
	int pan_struc;
	if (populationStructure(name) == "tribe") {
		pan_struc = 4;
	}
	else{
		if (populationStructure(name) == "country") {
			pan_struc = 6;
		}
		else {
			pan_struc = 8;
		}
	}
	int pandemic = rand() % 11 + 2;
	if (pandemic < pan_struc) {
		string worldpath = name + "/";
		ofstream worldfile;
		worldfile.open(worldpath + "pandemic");
		worldfile << pandemic;
		worldfile.close();
	}
	else {
		string worldpath = name + "/";
		ofstream worldfile;
		worldfile.open(worldpath + "pandemic");
		worldfile << "0";
		worldfile.close();
	}

}

//set the technoogy factor
void World::setTechnology(string name) {
	srand(time(NULL));
	string pop_struc = populationStructure(name);
	int tech = getTechnology(name);
	if (pop_struc == "country" || pop_struc == "continental" || tech > 4) {
		long long tech = rand() % 5 + 1;
		string worldpath = name + "/";
		ofstream worldfile;
		worldfile.open(worldpath + "technology");
		worldfile << tech;
		worldfile.close();
	}
	else {
		long long tech = rand() % 2 + 1;
		string worldpath = name + "/";
		ofstream worldfile;
		worldfile.open(worldpath + "technology");
		worldfile << tech;
		worldfile.close();
	}
}

int World::getTechnology(string name) {
	ifstream worldfile(name + "/" + "technology");
	string tech_f;
	getline(worldfile, tech_f);
	worldfile.close();
	int tech;
	tech = std::stoll(tech_f, NULL, 0);
	return tech;
}

void World::setWar(string name){
	srand(time(NULL));
	float war;
	int a = rand() % 50 + 1;
	if (a > 40) {
		int r = rand() % 5 + 1;
		switch (getTechnology(name))
		{
		case 1:
			if (populationStructure(name) == "tribe") {
				war = r * 0.1;
			}
			else {
				if (populationStructure(name) == "country") {
					war = r * 1;
				}
				else {
					if (populationStructure(name) == "continental") {
						war = r * 2;
					}
				}
			}
			break;

		case 2:
			if (populationStructure(name) == "tribe") {
				war = r * 0.2;
			}
			else {
				if (populationStructure(name) == "country") {
					war = r * 2;
				}
				else {
					if (populationStructure(name) == "continental") {
						war = r * 4;
					}
				}
			}
			break;

		case 3:
			if (populationStructure(name) == "tribe") {
				war = r * 0.4;
			}
			else {
				if (populationStructure(name) == "country") {
					war = r * 4;
				}
				else {
					if (populationStructure(name) == "continental") {
						war = r * 8;
					}
				}
			}
			break;

		case 4:
			if (populationStructure(name) == "tribe") {
				war = r * 0.8;
			}
			else {
				if (populationStructure(name) == "country") {
					war = r * 8;
				}
				else {
					if (populationStructure(name) == "continental") {
						war = r * 16;
					}
				}
			}
			break;

		case 5:
			if (populationStructure(name) == "tribe") {
				war = r * 0.8;
			}
			else {
				if (populationStructure(name) == "country") {
					war = r * 8;
				}
				else {
					if (populationStructure(name) == "continental") {
						war = r * 16;
					}
				}
			}
			break;

		default:
			break;
		}
	}

}

void World::getWar(string name) {

}
