#include <iostream>
#include <string>
#include <unistd.h>

#include "World.h"
#include "Visualizing.h"
#include "Interface.h"


using namespace std;



int main() {
	string name;
	cout << "Starting world engine... \n Give your world a name!\nInput: " << endl;
	cin >> name;
	Interface Interface(name);
	
	
}