// Phillip Alday
// Hunt The Wumpus
// Last Update: 16 Nov 02

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vector.h"
#include "oostring.h"

struct room{
	oostring hazard;
	int north;
	int south;
	int east;
	int west;
};

struct hunter{
	oostring name;
	int arrows;
	int status;
	int room;
	int lroom;
	int wumpus;
	int lev;
	int ext;
	int score;
};

struct weapon{
	int room;
};

const int dead = -1;
const int alive = 1;
const int base_score = 5000;

vector <room> map(6);

void exterminate(hunter &shooting, char direction);
void shootarrow(hunter &shooting, char d1, char d2);
void changeroom(hunter &moving, char direction);
void play(hunter &player);
int loadlevel();
void trophy(hunter &winning);
void help();
void situation(hunter &player);
void startup(hunter &initialize);
void treasure(hunter &lucky);
template <class mytype>
void swap(mytype &x, mytype &y);

int main(){
	hunter player;
	char again;

	do{
		startup(player);
		
		if(!loadlevel()){
			cerr << "File error.\n";
			return 0;
		}
		
		help();
		play(player);

		do{
			cout << "Again? ";
			cin >> again;
		}while(toupper(again) != 'Y' && toupper(again) != 'N');

	}while(toupper(again) == 'Y');
			
	return 0;
}

void play(hunter &player){
	char command[4];
	
	while(player.status == alive && player.wumpus == alive){
		situation(player);
		cout << "Command: ";
		cin >> command;
		_strupr(command);
		
		switch(command[0]){
			case 'H':
				help();
				break;
			case 'M':
				changeroom(player, command[1]);	
				break;
			case 'S':
				shootarrow(player, command[1], command[2]);
				break;
			case 'T':
				exterminate(player, command[1]);	
				break;
			default:
				cout << "Please enter a valid command." << endl;
		}

	}
}
int loadlevel(){
	int i  = 1;
	char x[2];
	oostring level;
	ifstream fin;
	
	level = "castle";
	
	do{
		cout << "Enter a level(A-Z):";
		cin >> x;
	}while (x[1] != '\0');

	level += x;
	level += ".dat";
	
	fin.open(level.c_str(), ios::in);
	
	if(!fin)
		return 0;

	fin.setf(ios::skipws);

	do{
		map.resize(i + 1);
		fin >> map[i].hazard;
		fin >> map[i].north;
		fin >> map[i].south;
		fin >> map[i].east;
		fin >> map[i].west;
		i++;
	}while(!fin.eof());
	
	fin.close();
	
	if(i != 2)
		return 1;
	else 
		return 0;
}

void help(){
	char hold[2];

	system("CLS");
	cout << "Hunt The Wumpus v1.0" << endl;
	cout << endl;
	cout << "History: " << endl;
	cout << "In a certain castle, there lives a wumpus." << endl;
	cout << "No one knows for sure what a wumpus is, but" << endl;
	cout << "that doesn't matter.  All that matters is that"<< endl;
	cout << "you, have been chosen to hunt and kill it.  You" << endl;
	cout << "will encounter many dangers along the way, but " << endl;
	cout << "using a little brains and a little luck you can" << endl;
	cout << "succeed.  To help you on this journey, you have 3" << endl;
	cout << "tools: Levitation Potion (LevPot) which will take" << endl;
	cout << "care of itself, Exterminator 2000 Liquid Combustible (c)" << endl;
	cout << "(ET2kLC) (c) which you can throw into an adjacent room" << endl;
	cout << "to kill bats, and finally your arrows which will execute" << endl;
	cout << "two consecutive directional orders. "<< endl;
	cout << endl;
	cout << "Press enter to continue." << endl;
	cin.ignore(80,'\n');
	cin.get(hold,1);
	cin.ignore(80,'\n');
	system("CLS");
	cout << "Tips:" << endl;
	cout << "You can generally hear the presence of bats or bottomless "<< endl;
	cout << "pits in nearby rooms.  You can also smell a wumpus. " << endl;
	cout << "(That's why they hired you.)"  << endl;
	cout << "Only an arrow will kill a wumpus." << endl;
	cout << endl;
	cout << "Commands:" << endl;
	cout << "MX  Move where X is the direction of movement." << endl;
	cout << "SXY Shoot arrow where X is the first direction," << endl;
	cout << "      and Y is the second direction." << endl;
	cout << "TX  Toss Exterminator 2000 Liquid Combustible in direction X" << endl;
	cout << "H   Call this screen" << endl;
	cout << endl;
	cout << "Valid directions:" << endl;
	cout << "N\nS\nE\nW" << endl;
	cout << "For M command only: " << endl;
	cout << "P moves to the previous room." << endl;
	cout << "Please note that directions are relative." << endl;
	cout << endl;
	cout << "Press enter to begin." << endl;
	cin.get(hold,1);
	cin.ignore(80,'\n');

}

void shootarrow(hunter &shooting, char d1, char d2){
	weapon fired;
	
	fired.room = 0;
	
	shooting.arrows--;
	
	switch(d1){
		case 'N':
			if(map[shooting.room].north != 0)
				fired.room = map[shooting.room].north;
			break;
		case 'S':
			if(map[shooting.room].south != 0)
				fired.room = map[shooting.room].south;
			break;
		case 'E':
			if(map[shooting.room].east != 0)
				fired.room = map[shooting.room].east;
			break;
		case 'W':
			if(map[shooting.room].west != 0)
				fired.room = map[shooting.room].west;
			break;
		default:
			cerr << "Invalid direction." << endl;
			shooting.arrows++;
			return;
	}

	if(fired.room == 0)
		cout << "The twang of your arrow was cut short by a wall."<< endl;
	else{
		if(map[fired.room].hazard == "pit"){
			cout << "A feather floats your way as the breeze of the" <<  endl
				<< "bottomless pit pulls the fletching off your arrow." << endl;
		}
		else if(map[fired.room].hazard == "bats"){
			cout << "You hear the screetch of bats as your arrow " << endl
				<< "narrowly misses them." << endl;
		}
		else if(map[fired.room].hazard == "wumpus"){
			trophy(shooting);
			return;
		}
		else if(map[fired.room].hazard == "none"){
			if(fired.room == shooting.room){
				cout << "You just shot yourself.  That takes some real talent." << endl;
				cout << "Game Over" << endl;
				shooting.status = dead;
				return;
			}
			else{
				cout << "Your arrows whistles silently through the first room." << endl;
			}
		}
		else{
			cerr << "An error has occurred." << endl;
			return;
		}
	

		switch(d2){
			case 'N':
				if(map[fired.room].north != 0)
					fired.room = map[fired.room].north;
				else
					fired.room = 0;
				break;
			case 'S':
				if(map[fired.room].south != 0)
					fired.room = map[fired.room].south;
				else
					fired.room = 0;
				break;
			case 'E':
				if(map[fired.room].east != 0)
					fired.room = map[fired.room].east;
				else
					fired.room = 0;
				break;
			case 'W':
				if(map[fired.room].west != 0)
					fired.room = map[fired.room].west;
				else
					fired.room = 0;
				break;
			default:
				cerr << "Invalid direction." << endl;
				return;
		}

		if(fired.room == 0)
			cout << "The twang of your arrow was cut short by a wall."<< endl;
		else{
			if(map[fired.room].hazard == "pit"){
				cout << "A feather floats your way as the breeze of the" <<  endl
					<< "bottomless pitpulls the fletching off your arrow." << endl;
			}
			else if(map[fired.room].hazard == "bats"){
				cout << "You hear the screetch of bats as your arrow " << endl
					<< "narrowly misses them." << endl;
			}
			else if(map[fired.room].hazard == "wumpus"){
				trophy(shooting);
				return;
			}
			else if(map[fired.room].hazard == "none"){
				if(fired.room == shooting.room){
					cout << "You just shot yourself.  That takes some real talent." << endl;
					cout << "Game Over" << endl;
					shooting.status = dead;
					return;
				}
				else{
					cout << "Your arrows whistles silently through the second room." << endl;
				}
			}
			else{
				cerr << "An error has occurred." << endl;
				return;
			}
		}
	}

	if (shooting.arrows == 0){
		cout << "Since you have used your last arrow, you are doomed" << endl;
		cout << "to wander the castle until you die a most horrible death." << endl;
	}
}

void changeroom(hunter &moving, char direction){
	
	switch(direction){
		case 'N':
			if(map[moving.room].north != 0){
				if(map[moving.room].north == moving.room){
					cout << "This room seems strangely familiar." << endl;
					return;
				}
				moving.lroom = moving.room;
				moving.room = map[moving.room].north;
			}
			else{
				cout << "Walls are hard: they leave bruises and the one ";
				cout << "you just got will last a while." << endl;
				return;
			}
			break;
		case 'S':
			if(map[moving.room].south != 0){
				if(map[moving.room].south == moving.room){
					cout << "This room seems strangely familiar." << endl;
					return;
				}
				moving.lroom = moving.room;
				moving.room = map[moving.room].south;
			}
			else{
				cout << "Walls are hard: they leave bruises and the one ";
				cout << "you just got will last a while." << endl;
				return;
			}
			break;
		case 'E':
			if(map[moving.room].east != 0){
				if(map[moving.room].east == moving.room){
					cout << "This room seems strangely familiar." << endl;
					return;
				}
				moving.lroom = moving.room;
				moving.room = map[moving.room].east;
			}
			else{
				cout << "Walls are hard: they leave bruises and the one ";
				cout << "you just got will last a while." << endl;
				return;
			}
			break;
		case 'W':
			if(map[moving.room].west != 0){
				if(map[moving.room].west == moving.room){
					cout << "This room seems strangely familiar." << endl;
					return;
				}
				moving.lroom = moving.room;
				moving.room = map[moving.room].west;
			}
			else{
				cout << "Walls are hard: they leave bruises and the one ";
				cout << "you just got will last a while." << endl;
				return;
			}
			break;
		case 'P':
			if(moving.lroom == 0){
				cout << "You can't remember how you got here." << endl;
				return;
			}
			else{
				swap(moving.lroom, moving.room);
				return;
			}
			break;
		default:
			cerr << "Invalid direction.";
			return;
	}
	
	treasure(moving);

	if(map[moving.room].hazard == "none")
		return;
	else
		moving.status = dead;

	if(map[moving.room].hazard == "pit"){
		if(moving.lev > 0){
			moving.lev--;
			cout << "With the aid of a vial of Levitation Potion, you find" << endl;
			cout << "yourself floating eerily above a bottomles pit." << endl;
			moving.status = alive;
			return;
		}
		else{
			cout << "You have a long time to say goodbye as you fall down" << endl;
			cout << "the bottomless pit." << endl;
		}
	}
	else if(map[moving.room].hazard == "bats"){
		cout << "You are looking a little pale without any blood." << endl;
	}
	else if(map[moving.room].hazard == "wumpus"){
		cout << "You found your prey.  Unfortunately, it found you first." << endl;
	}
	cout << "Game Over." << endl;
	return;
}

void trophy(hunter &winning){
	winning.wumpus = dead;
	system("CLS");
	cout << "Congratulations, " << winning.name << '!' << endl; 
	cout << "You have killed the wumpus.  Now you must console his weeping " << endl;
	cout << "mother whom you are surprised to find out is your sister." << endl;
	cout << "Final score: " << winning.score << endl;;
}

void situation(hunter &player){
	
	int nearby;

	nearby = (map[map[player.room].north].hazard == "wumpus") ||
				(map[map[player.room].south].hazard == "wumpus") ||
				(map[map[player.room].east].hazard == "wumpus") ||
				(map[map[player.room].west].hazard == "wumpus");
	
	if(nearby)	
		cout << "You smell a nearby wumpus." << endl;


	nearby = (map[map[player.room].north].hazard == "pit") || 
				(map[map[player.room].south].hazard == "pit") ||
				(map[map[player.room].east].hazard == "pit") ||
				(map[map[player.room].west].hazard == "pit");
			
	if(nearby)
		cout << "You feel a breeze." << endl;


	nearby = (map[map[player.room].north].hazard == "bats") || 
				(map[map[player.room].south].hazard == "bats") ||
				(map[map[player.room].east].hazard == "bats") ||
				(map[map[player.room].west].hazard == "bats");
	
	if(nearby)
		cout << "You hear wings flapping nearby." << endl;

	cout << "Arrows Remaining: " << player.arrows << endl;
	cout << "LevPot Remaining: " << player.lev << endl;
	cout << "ET2kLC Remaining: " << player.ext << endl << endl;
}

void startup(hunter &initialize){
	if (initialize.name == ""){
		cout << "Enter your name: ";
		cin >> initialize.name;
		cin.ignore(80, '\n');
	}
	
	cout << "Enter starting arrows: ";
	cin >> initialize.arrows;

	cout << "Enter starting Levitation Potion: ";
	cin >> initialize.lev;

	cout << "Enter starting Exterminator 2000 Liquid Combustible(c): ";
	cin >> initialize.ext;

	initialize.status = alive;
	initialize.room = 1;
	initialize.lroom = 0;
	initialize.wumpus = alive;
	initialize.score = base_score - 100 * (initialize.lev + initialize.ext + initialize.arrows - 7);
}

void exterminate(hunter &shooting, char direction){
	weapon fired;
	
	fired.room = 0;
	
	shooting.ext--;
	
	switch(direction){
		case 'N':
			if(map[shooting.room].north != 0)
				fired.room = map[shooting.room].north;
			break;
		case 'S':
			if(map[shooting.room].south != 0)
				fired.room = map[shooting.room].south;
			break;
		case 'E':
			if(map[shooting.room].east != 0)
				fired.room = map[shooting.room].east;
			break;
		case 'W':
			if(map[shooting.room].west != 0)
				fired.room = map[shooting.room].west;
			break;
		default:
			cerr << "Invalid direction." << endl;
			shooting.arrows++;
			return;
	}

	if(fired.room == 0){
		cout << "There's a reason you shouldn't drink and then handle expolsives."<< endl;
		cout << "You might just do something stupid like throwing them at a wall." << endl;
		shooting.score += -500;
	}
	else{
		if(map[fired.room].hazard == "pit"){
			cout << "Throwing ET2000LC down a bottomless pit is kind of " <<  endl
				<< "like playing with water dynamite when you were younger." << endl;
		}
		else if(map[fired.room].hazard == "bats"){
			cout << "Through the clearing smoke, you hear the flop, flop, flop" << endl
				<< "of hundreds of bats falling dead to the floor." << endl;
			map[fired.room].hazard = "none";
		}
		else if(map[fired.room].hazard == "wumpus"){
			cout << "You hear the moaning of a burnt wumpus. " << endl;
			return;
		}
		else if(map[fired.room].hazard == "none"){
			if(fired.room == shooting.room){
				cout << "As the vial of ET2000LC, you realize that you will feel" << endl;
				cout << "this one in the morning." << endl;
				shooting.score += -500;
				return;
			}
			else{
				cout << "The next room lights up briefly with an explosion." << endl;
			}
		}
		else{
			cerr << "An error has occurred." << endl;
			return;
		}
	}
}

void treasure(hunter &lucky){
	// about 5.6% chance of prizes
	int bonus;
	
	srand(clock());

	if((1 + rand() % 3) == 3){
		bonus = (1 + rand() % 500);
		
		switch((1 + rand() % 6)){
			case 1:
				lucky.arrows++;
				lucky.score += bonus;
				cout << "You found an arrow." << endl;
				break;
			case 2:
				lucky.lev++;
				lucky.score += bonus;
				cout << "You found a vial of levitation potion." << endl;
				break;
			case 3:
				lucky.ext++;
				lucky.score += bonus;
				cout << "You found some Exterminator 2000 Liquid Combustible(c)." << endl;
				break;
		}
	}
}

template <class mytype>
void swap(mytype &x, mytype &y){
	mytype temp;
	temp = x;
	x = y;
	y = temp;
}