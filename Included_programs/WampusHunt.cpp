// JoShUa FiElDs    **
// AdVaNcEd C++     ** 
// "Hunt the Wumpus"**
//********************
//********************


//***Compiler Directives***
#include <iostream.h>
#include <fstream.h>
#include "oostring.h"
#include "vector.h"
//*** GLOBAL STRUCTURES ***
struct room								// Stucture for room information			
{

	oostring hazard;
	int north;
	int south;
	int east;
	int west;
};

struct toy{							// Structure to let me manipulate room/weapon
	int room;
};
struct me{						// Structure for the player/game info
	int arrows;
	int info;
	int wumpus;
	int room;
	int rooms;
};

vector <room> level(20);			// Vector of structs
		
//*** Funky GLOBAL Definitions ***
void use_arrows(me &shooting, char first_direction, char second_direction);
void room_change(me &move, char direction);
void play(me &user);
int  open_file();
void winner(me &done);
void player_info(me &user);
void set(me &set);


// GLOBAL Variable for setting of users life
const int life1 = 1;
const int life0 = -1;

void set(me &set)				// Function to intialize variables of struct
	{								
		set.arrows = 7;
		set.info = life1;			// Note: to increase arrows, mod set.arrows
		set.room = 1;
		set.rooms = 0;
		set.wumpus = life1;
	}
//!**************!
//!***! MAIN !***!
//!**************!
void main()
{	
	me man;
	cout << "WELCOME TO HUNT THE WUMPUS v1.0 !!! (test release)" << endl << endl;
	cout << "DIRECTIONS: W is the input for walking, F is the input " 
		 << "for fire arrows, enter" << endl 
		 << "your two directions with no spaces after first input." << endl << endl; 	 
	
	    cout << "You find yourself in a very large castle" << endl
			 << "full of dangerous ...things, " << endl
		     << "that are...dangerous, very dangerous!" << endl << endl;
	
	if(!open_file())						// If file problem, stop
		cout << "File error" << endl;
 set(man);
 play(man);

}
			
int open_file(){							// Function to load file
			ifstream game;
			game.open("level.txt", ios::in);
			int l =1 ;

			if(!game) 
				return 0;

			game.setf(ios::skipws);
			do{
				level.resize(l + 1);
				game >> level[l].hazard >> level[l].north >>level[l].south >> level[l].east >> level[l].west;
				l++;
			}while(!game.eof());
		
			game.close();
			
			if(l !=2)
				return 1;
			else
				return 0;
		}

void play(me &user){						// Function to start game-play
		char input[10];
		while(user.info == life1 && user.wumpus == life1){
			player_info(user);
			cout << "Enter your command: ";
			cin >> input;

switch(input[0]){	

case 'W':
	room_change(user, input[1]);
	break;

case 'F':
	use_arrows(user, input[1], input[2]);
	break;
default: cout << "Invalid operation M or F only." << endl;
		}
	}
}

// Function to handle changing rooms
	void room_change(me &move, char direction){			
				
		// Evaluate Movement Direction
switch(direction){

case 'N':
		if(level[move.room].north != 0){
		move.rooms = move.room;
		move.room = level[move.room].north;
						}
						else{
							cout << "You ran into a wall, HAHA" <<endl;
												}
						break;
		
case 'S':
						if(level[move.room].south !=0){
							move.rooms = move.room;
							move.room = level[move.room].south;
						}
						else{
							cout << "You hit a wall, smart man" << endl;
												} 
						break;
case 'E': 
						if(level[move.room].east !=0){
						move.rooms = move.room;
						move.room = level[move.room].east;
							  }
						else{
							cout << "SMACK: You hit a wall" << endl;
								}
						break;

case 'W':
						if(level[move.room].west != 0){
							move.rooms = move.room;
							move.room = level[move.room].west;
						}
						else{
							cout << "You hit a wall, haha!" << endl;
												}
						break;
					
						default: cout << "Hey idiot, thats not a valid direction!" << endl;
						break;
				}
				
				if(level[move.room].hazard == "none")
					return;
				else
					move.info = life0;
				
				int j = 0;
				if(level[move.room].hazard == "pit"){
					if(1 == j){
					// My jump function soon to come
					return;
					}
					else{
					cout << " You fall, and fall, and fall, down the pit"<< endl;
					cout << "haha" << endl;
					}
				}
					else if(level[move.room].hazard == "bats"){
						cout << "The bats got you!" << endl;
					}
					else if(level[move.room].hazard == "wumpus"){
						cout << "The wumpus got you!" << endl;
					}
					cout << "Game Over, THANKS FOR PLAYING" << endl;
					return;

			}

// Function to handle arrows
void use_arrows(me &shooting, char first_direction, char second_direction){
			toy shot;

			shot.room = 0;
			shooting.arrows--;
			
switch(first_direction)				// Evaluates first direction
			{
case 'N':
	if(level[shooting.room].north !=0)
		shot.room = level[shooting.room].north;
	break;
case 'S':
	if(level[shooting.room].south !=0)
		shot.room = level[shooting.room].south;
		break;
case 'E':
	if(level[shooting.room].east !=0)
		shot.room = level[shooting.room].east;
	break;
case 'W':
	if(level[shooting.room].west !=0)
		shot.room = level[shooting.room].west;
	break;
default: cout << "What the hell buddy! Thats not "
			  << "a valid direction!"<< endl;
		break;		
			}

			if(shot.room == 0)
				cout << "Your arrow had a close encounter with A WALL!" << endl;
			else{
				if(level[shot.room].hazard == "pit"){
					cout << "Your arrow forever flies, DOWN to the center of THE EARTH!" << endl;
				}
				else if(level[shot.room].hazard == "bats"){
					cout << "You pissed off a family of bats as your arrow empails their " 
						<< "new born baby";
				}
				else if(level[shot.room].hazard == "wumpus"){
					winner(shooting);
								}
				else if(level[shot.room].hazard == "none"){
					if(shot.room == shooting.room){
						cout << "You just shot yourself you IDIOT" << endl;
						cout << "!!! YOU LOOSE !!!" << endl;
						shooting.info = life0;
								}
					else{
						cout << "Your arrow says all is clear in the first room." << endl;
				}
			}

				
switch(second_direction)						// Evaluates second direction
{

case 'N':	if(level[shooting.room].north !=0)
		shot.room = level[shooting.room].north;
	break;
case 'S':
	if(level[shooting.room].south !=0)
		shot.room = level[shooting.room].south;
		break;
case 'E':
	if(level[shooting.room].east !=0)
		shot.room = level[shooting.room].east;
	break;
case 'W':
	if(level[shooting.room].west !=0)
		shot.room = level[shooting.room].west;
	break;
default: cout << "What the hell buddy! Thats not "
			  << "a valid direction!"<< endl;
			break;
			}

			if(shot.room == 0)
				cout << "Your arrow had a close encounter with A WALL!" << endl;
			else{
				if(level[shot.room].hazard == "pit"){
					cout << "Your arrow forever flies, DOWN to the center of THE EARTH!" << endl;
				}
				else if(level[shot.room].hazard == "bats"){
					cout << "You pissed off a family of bats as your arrow empails their " 
						<< "new born baby" << endl;
				}
				else if(level[shot.room].hazard == "wumpus"){
					winner(shooting);
								}
				else if(level[shot.room].hazard == "none"){
					if(shot.room == shooting.room){
						cout << "You just shot yourself you IDIOT" << endl;
						cout << "!!! YOU LOOSE !!!" << endl;
						shooting.info = life0;
										}
					else{
						cout << "Your arrow says all is clear in the second room." << endl;
				}
			}
					
				}	
			}
						
			if (shooting.arrows == 0){
				cout << "No more arrows, no more shooting!" << endl;
								
			}
		}

	// Function to handle enviroment information
void player_info(me &user){
int sense;
sense = (level[level[user.room].north].hazard == "wumpus") ||
		(level[level[user.room].south].hazard == "wumpus") ||
     	(level[level[user.room].east].hazard == "wumpus") ||
	    (level[level[user.room].west].hazard == "wumpus");
	            if(sense)
				cout << "You smell a wumpus in one of the adjacent rooms" << endl;
sense = (level[level[user.room].north].hazard == "pit") ||
(level[level[user.room].south].hazard == "pit") ||
(level[level[user.room].east].hazard == "pit") ||
(level[level[user.room].west].hazard == "pit"); 
				if(sense)
				cout << "You feel a spooky breeze." << endl;
sense = (level[level[user.room].north].hazard == "bats") ||
(level[level[user.room].south].hazard == "bats") ||
(level[level[user.room].east].hazard == "bats") ||
(level[level[user.room].west].hazard == "bats");
				if(sense){
				cout << "You hear the flapping of bat wings." << endl;
				cout << "You have: " << user.arrows << " arrows remaining." << endl;
						}
}

// Function to handle killing the wampus
void winner(me &done){
				done.wumpus = life0;
				cout << "You killed the wumpus, Good Job, Your still a loser though!" << endl;
					}








// **********END OF PROGRAM 11/22/02 5:21am*************