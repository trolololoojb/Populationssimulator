#pragma once
#include <string>


using namespace std;

class World {

private:
	long long createPopulation(string name);
	long long createArea(string name);
	string populationStructure(string name);

public:
	World(string name);
	long long getArea(string name);
	long long getPopulation(string name);
	void worldtime(int a, int y);
};