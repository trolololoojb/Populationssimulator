#pragma once
#include <string>


using namespace std;

class World {

private:
	long long createPopulation(string name);
	long long createArea(string name);
	void plusPopulation(string name);
	void minusPopulation(string name);
	void setYear(string name);
	void pandemic(string name);

public:
	World(string name);
	long long getArea(string name);
	long long getPopulation(string name);
	string populationStructure(string name);
	void yearPlanet(string name);
	long long getYear(string name);
};