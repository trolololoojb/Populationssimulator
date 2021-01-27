#pragma once
#include <string>

using namespace std;

class World {

private:
	int createPopulation();

public:
	World(string name);
	int getPopulation(string name);
	void worldtime(int a, int y);
};