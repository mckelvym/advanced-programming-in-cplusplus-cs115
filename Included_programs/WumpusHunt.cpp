// JoShUa FiElDs    **
// AdVaNcEd C++     ** 
// "Hunt the wampus"**
//********************
//********************

//***Compiler Directives***
#include <iostream.h>
#include <fstream.h>

#include "oostring.h"
#include "vector.h"


//*** GLOBAL STRUCTURES ***
struct room								// Stucture for room			
{

	oostring hazard;
	int north;
	int south;
	int east;
	int west;
};

struct hunt{							// Structure for the hunt
	int arrows;
	int info;
	int wampus;
	int room;
	int rooms;
	
};

struct toy{							// Structure to let me manipulate room/weapon
	int room;
};
vector <room> level(20);


				
//*** Funky GLOBAL Definitions ***
void use_arrows(hunt &shooting, char first_direction, char second_direction);
void room_change(hunt &move, char direction);
void play(hunt &user);
int  load_game();
void winner(hunt &done);
void player_info(hunt &user);
void set(hunt &set);


// GLOBAL Variable for player_info of users life
const int alive = 1;
const int dead = -1;


//*** MAIN ***
void main()
{	
	hunt man;
	
	cout << "WELCOME TO HUNT THE WAMPUS v1.0 !!! (test release)" << endl << endl;
	cout << "DIRECTIONS: W is the input for walking, fire is the input " 
		 << "for fire arrows, enter" << endl 
		 << "your two directions with no spaces after first input." << endl << endl; 	 
	
	    cout << "You find yourself in a very large castle" << endl
			 << "full of dangerous ...things, " << endl
		     << "that are...dangerous, very dangerous!" << endl;
	
			

	if(!load_game())	
		cout << "File error" << endl;

 set(man);
 play(man);



}
	
		
int load_game(){
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

void play(hunt &user){
		char input[10];
		while(user.info == alive && user.wampus == alive){
			player_info(user);
			cout << "Enter your command: ";
			cin >> input;

switch(input[0]){	

case 'M':
	room_change(user, input[1]);
	break;

case 'F':
	use_arrows(user, input[1], input[2]);
	break;
default: cout << "Invalid operation M or F only." << endl;
		}
	}
}
		


void use_arrows(hunt &shooting, char first_direction, char second_direction){
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
				else if(level[shot.room].hazard == "wampus"){
					winner(shooting);
					return;
				}
				else if(level[shot.room].hazard == "none"){
					if(shot.room == shooting.room){
						cout << "You just shot yourself you IDIOT" << endl;
						cout << "!!! YOU LOOSE !!!" << endl;
						shooting.info = dead;
						return;
					}
					else{
						cout << "Your arrow says all is clear in the first room." << endl;
				}
			}

				else{
						cout << "Something just went terribly wrong!" << endl;
						return;
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
						<< "new born baby";
				}
				else if(level[shot.room].hazard == "wampus"){
					winner(shooting);
					return;
				}
				else if(level[shot.room].hazard == "none"){
					if(shot.room == shooting.room){
						cout << "You just shot yourself you IDIOT" << endl;
						cout << "!!! YOU LOOSE !!!" << endl;
						shooting.info = dead;
						return;
					}
					else{
						cout << "Your arrow says all is clear in the second room." << endl;
				}
			}
					else{
						cout << "Something just went terribly wrong!" << endl;
						return;
					}
				}	
			}
						
			if (shooting.arrows == 0){
				cout << "No more arrows, no more hunting!" << endl;
			}
		}
			


void room_change(hunt &move, char direction){
			
		
		// Evaluate Movement Direction
switch(direction){

case 'N':
if(level[move.room].north != 0){

move.room = move.room;
move.room= level[move.room].north;
						}
						else{
							cout << "You ran into a wall, HAHA" <<endl;
							return;
						}
						break;
		
case 'S':
						if(level[move.room].south !=0){
							move.room = move.room;
							move.room = level[move.room].south;
						}
						else{
							cout << "You hit a wall, smart man" << endl;
							return;
						} 
						break;
case 'E': 
						if(level[move.room].east != 0){
						move.room = move.room;
						move.room = level[move.room].east;
							  }
						else{
							cout << "SMACK: You hit a wall" << endl;
							return;
						}
						break;

case 'W':
						if(level[move.room].west != 0){
							move.room = move.room;
							move.room = level[move.room].west;
						}
						else{
							cout << "You hit a wall, haha!" << endl;
							return;
						}
						break;
					
						default: cout << "Hey idiot, thats not a valid direction!" << endl;
						break;
				}
				
				
				if(level[move.room].hazard == "none")
					return;
				else
					move.info = dead;
				
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
					else if(level[move.room].hazard == "wampus"){
						cout << "The wampus got you!" << endl;
					}
					cout << "Game Over, THANKS FOR PLAYING" << endl;
					return;
			}
					
						
					

void player_info(hunt &user){
				int sense;
				sense = (level[level[user.room].north].hazard == "wampus") ||
  				(level[level[user.room].south].hazard == "wampus") ||
				(level[level[user.room].east].hazard == "wampus") ||
				(level[level[user.room].west].hazard == "wampus");
				if(sense)
				cout << "You smell a wampus in one of the adjacent rooms" << endl;

				sense = (level[level[user.room].north].hazard == "pit") ||
				(level[level[user.room].north].hazard == "pit") ||
				(level[level[user.room].north].hazard == "pit") ||
				(level[level[user.room].north].hazard == "pit"); 
		
					if(sense)
					cout << "You feel a spooky breeze." << endl;

					sense = (level[level[user.room].north].hazard == "bats") ||
					(level[level[user.room].south].hazard == "bats") ||
					(level[level[user.room].south].hazard == "bats") ||
					(level[level[user.room].south].hazard == "bats");
					
				if(sense){
					cout << "You hear the flapping of bat wings." << endl;
					
				cout << "You have: " << user.arrows << " arrows remaining." << endl;
						}
}
																
		
void set(hunt &set)
	{
		set.arrows = 7;
		set.info = alive;
		set.room = 1;
		set.rooms = 0;
		set.wampus = alive;
	}
						
void winner(hunt &done){
				done.wampus = dead;
				cout << "You killed the wampus, Good Job, Your still a loser though!" << endl;
					}
