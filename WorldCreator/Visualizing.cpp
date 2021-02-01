#include "Visualizing.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>



using namespace std;



Visualizing::Visualizing() {

}

void Visualizing::rotateWorld() {
	int a = 1;
	string planet1 = "        _____\n    ,-:` \\;',`'-, \n  .'-;_,;  ':-;_,'.\n /;   '/    ,  _`.-\\ \n| '`. (`     /` ` \\`|\n|:.  `\\`-.   \\_   / |\n|     (   `,  .`\\ ;'|\n \\     | .'     `-'/\n  `.   ;/        .'\n    `'-._____.\n";
	string planet2 = "        _____\n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'.\n / ;   '/    ,  _`.\\ \n|  '`. (`     /` ` \\|\n| :.  `\\`-.   \\_   /|\n|      (   `,  .`\\ ;|\n \\      | .'     `-/\n  `.    ;/       .'\n    `'-._____.\n";
	string planet3 = "        _____\n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'.\n /  ;   '/    ,  _`\\ \n|   '`. (`     /` ` |\n|  :.  `\\`-.   \\_   |\n|       (   `,  .`\\ |\n \\       | .'     `/\n  `.     ;/      .'\n    `'-._____.\n";
	string planet4 = "        _____ \n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'. \n /   ;   '/    ,  _\\ \n|    '`. (`     /` `| \n|   :.  `\\`-.   \\_  | \n|        (   `,  .`\\| \n \\        | .'     / \n  `.      ;/     .' \n    `'-._____. \n";
	string planet5 = "        _____ \n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'. \n  .' -;_,;  ':-;_'. \n|     '`. (`     /` | \n|    :.  `\\`-.   \\_ | \n|         (   `,  .`| \n \\         | .'    / \n  `.       ;/    .' \n    `'-._____. \n";


	system("clear");
	cout << planet1;
	sleep(1);
	system("clear");
	cout << planet2;
	sleep(1);
	system("clear");
	cout << planet3;
	sleep(1);
	system("clear");
	cout << planet4;
	sleep(1);
	system("clear");
	cout << planet5;
	sleep(1);
	system("clear");
}


