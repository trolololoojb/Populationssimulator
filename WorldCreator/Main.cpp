#include <iostream>
#include <string>

#include "World.h"

using namespace std;



int main() {
	string name;
	cout << "Starting world engine... \n Give your world a name:\n" << endl;
	cin >> name;
	World Earth(name);
	cout << Earth.getPopulation(name);
	
	cout << "Press a button for shut down...:";
	int shutdown;
	cin >> shutdown;
	return 0;
}