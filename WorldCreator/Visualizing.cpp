#include "Visualizing.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>



using namespace std;



Visualizing::Visualizing() {

}

void Visualizing::rotateWorld() {
	string planet1 = "Create Planet.  \n        _____\n    ,-:` \\;',`'-, \n  .'-;_,;  ':-;_,'.\n /;   '/    ,  _`.-\\ \n| '`. (`     /` ` \\`|\n|:.  `\\`-.   \\_   / |\n|     (   `,  .`\\ ;'|\n \\     | .'     `-'/\n  `.   ;/        .'\n    `'-._____.\n";
	string planet2 = "Create Planet.. \n        _____\n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'.\n / ;   '/    ,  _`.\\ \n|  '`. (`     /` ` \\|\n| :.  `\\`-.   \\_   /|\n|      (   `,  .`\\ ;|\n \\      | .'     `-/\n  `.    ;/       .'\n    `'-._____.\n";
	string planet3 = "Create Planet...\n        _____\n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'.\n /  ;   '/    ,  _`\\ \n|   '`. (`     /` ` |\n|  :.  `\\`-.   \\_   |\n|       (   `,  .`\\ |\n \\       | .'     `/\n  `.     ;/      .'\n    `'-._____.\n";
	string planet4 = "Create Planet.  \n        _____ \n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'. \n /   ;   '/    ,  _\\ \n|    '`. (`     /` `| \n|   :.  `\\`-.   \\_  | \n|        (   `,  .`\\| \n \\        | .'     / \n  `.      ;/     .' \n    `'-._____. \n";
	string planet5 = "Create Planet.. \n        _____ \n    ,-:` \\;',`'-, \n  .' -;_,;  ':-;_'. \n  .' -;_,;  ':-;_'. \n|     '`. (`     /` | \n|    :.  `\\`-.   \\_ | \n|         (   `,  .`| \n \\         | .'    / \n  `.       ;/    .' \n    `'-._____. \n";

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

void Visualizing::createPeople() {
	string planet1 = "Create people.   \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_..        `        , '. \n   .'     \\      /        |    \\'. \n  /        :   ;'          `____> \\ \n :         `. (           /       : \n |           `>\\_         \\      ;| \n             /   \\         `._   \\ \n |          |      `          ;   | \n  :          \\     /          `   ; \n   \\          \\   '            ` / \n     `.        | /             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	string planet2 = "Create people..  \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_..     .  `        , '. \n   .'     \\ .    /        | .  \\'. \n  /        :   ;'          `____> \\ \n :         `. (           /       : \n |           `>\\_         \\      ;| \n             /   \\         `._   \\ \n |          |      `          ;   | \n  :          \\     /          `   ; \n   \\          \\   '            ` / \n     `.        | /             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	string planet3 = "Create people... \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_..     .  `        , '. \n   .'     \\ .    /        | .  \\'. \n  /        :   ;'          `____> \\ \n :         `. (           /       : \n |           `>\\_         \\   .  ;| \n             /   \\         `._   \\ \n |          |   .  `          ;   | \n  :          \\     /          `   ; \n   \\          \\   '            ` / \n     `.        | /             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	string planet4 = "Create people.   \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_.. .   .  `        , '. \n   .'     \\ .    /        | .  \\'. \n  /        :   ;'          `____> \\ \n :         `. (           /   .   : \n |           `>\\_         \\   .  ;| \n             /   \\         `._   \\ \n |          |   .  `          ;   | \n  :          \\  .  /          `   ; \n   \\          \\   '            ` / \n     `.        | /             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	string planet5 = "Create people..  \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_.. .   .  `        , '. \n   .'     \\ .    /        | . .\\'. \n  /        : . ;'          `____> \\ \n :         `. (           / . .   : \n |           `>\\_         \\   .  ;| \n             / . \\         `._   \\ \n |          | . .  `          ; . | \n  :          \\  .  /          `   ; \n   \\          \\   '            ` / \n     `.        | /             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	string planet6 = "Create people... \n             ___.....___ \n       ,..-.=--.-.       "". \n     .{_.. . . .  `        , '. \n   .'     \\ . .  /        | . .\\'. \n  /        : . ;'          `____> \\ \n :         `. (           / . .   : \n |           `>\\_         \\   .. ;| \n             / . \\         `._.  \\ \n |          | . . .`          ; . | \n  :          \\  . ./          ` . ; \n   \\          \\.  '            ` / \n     `.        |./             .' \n        `      `/          . ' \n           `---'.....---'' \n";
	
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
