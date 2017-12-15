/***************************************************************
CSCI 240         Program 4     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	9/23/2016

Purpose: This program plays a game of Craps with the user.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	//define vars
	int roll1, roll2, startingRoll, point, currentRoll;
	
	//define symbolic constants
	const int TWO=2;
	const int THREE=3;
	const int SEVEN=7;
	const int ELEVEN=11;
	const int TWELVE=12;
	
	//initiate srand function
	srand(time(0));
	
	//generate random rolls and sum them
	roll1=rand() % 7 + 1;
	roll2=rand() % 7 + 1;
	startingRoll=roll1+roll2;
	
	//function that calculates and displays the first roll for the "point" and checks
	//if it matches any of the symbolic constants.
	if (startingRoll==TWO||startingRoll==THREE||startingRoll==TWELVE) {
		cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<startingRoll<<endl;
		cout<<endl<<"You lost!";
		return(0);
	}
	else if (startingRoll==SEVEN||startingRoll==ELEVEN){
		cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<startingRoll<<endl;
		cout<<endl<<"You won!";
		return(0);
	}
	else {
		cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<startingRoll<<endl;
		cout<<"\nThe point is "<<startingRoll<<"\n"<<endl;
		point=startingRoll;
	}
			

	//loop that rolls dice and displays the roll until sum is seven, and checks
	//if the user rolls their point.
	while (currentRoll!=SEVEN)  {
		roll1=rand() % 7 + 1;
		roll2=rand() % 7 + 1;
		currentRoll=roll1+roll2;
		if (currentRoll==point) {
			cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<currentRoll<<endl;
			cout<<endl<<"You rolled your point! You won!";
			return(0);
		}
		else
		cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<currentRoll<<endl;	
	}
	
	//display game over message if lost
	cout<<endl<<"You seven'd out and lost!";
	return(0);
		
}
