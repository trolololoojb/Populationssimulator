#include <iostream>
#include <string>

#include "World.h"

using namespace std;



int main() {
	string name;
	cout << "starting world engine... \n give your world a name:\n" << endl;
	cin >> name;
	World Earth(name);
	Earth.getPopulation(name);
	return 0;
}