/***************************************************************
CSCI 240         Program 5     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	10/14/2016	

Purpose: This program is an extension of Program 4 with added
functions to roll the dice and take the user's wager.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//declare functions
int rollDice();
double getWager(double);

int main() {
	
	//init srand function
	srand(4);
	
	//declare vars
	double currentBalance;
	int roll1, roll2, point, currentRoll, currentWager;
	string choice;
	
	choice="y";
	currentBalance=100;
	
	//get first wager
	currentWager=getWager(currentBalance);
	
	//roll dice for first sum
	currentRoll=rollDice();
	
	//If-else function that checks if the first roll is the point or if the game is lost
	if (currentRoll==2||currentRoll==3||currentRoll==12) {
		cout<<endl<<"You lost!";
		return(0);
	}
	else if (currentRoll==7||currentRoll==11){
		cout<<endl<<"You won!";
		return(0);
	}
	else {
		cout<<"\nThe point is "<<currentRoll<<"\n"<<endl;
		point=currentRoll;
	}
	
	//rolls the dice until the game is won or lost
		currentRoll=rollDice();
		while (currentRoll!=7 && currentBalance>=0) {
			if (currentRoll==point) {
				cout<<endl<<"You rolled your point! You won!\n";
				currentBalance+=currentWager;
			}
			else {
			cout<<"You lost!\n";
			currentBalance-=currentWager;
			}
		cout<<"Your balance is $";
		cout<<fixed<<setprecision(2)<<currentBalance<<endl;
		cout<<"Would you like to keep playing (y for yes)? ";
		cin>>choice;
		if (choice!="y"||choice!="Y") {
			cout<<"Your final balance is $";
	        cout<<fixed<<setprecision(2)<<currentBalance;
	        return(0);
		}
		else {
			currentWager=getWager(currentWager);
			currentRoll=rollDice();	
		}
		
		}
	
}

/***************************************************************
Function:  int rollDice() 

Use: This function rolls the dice for the game of craps

Arguments: None

Returns: the sum of the dice

Note: the function will display the two die and their sum as well
***************************************************************/

int rollDice() {
	
	//declare vars
	int roll1, roll2, sum;
	//generate random rolls and sum them
	roll1=rand() % 7 + 1;
	roll2=rand() % 7 + 1;
	sum=roll1+roll2;
	cout<<"Player Rolled: "<<roll1<<" + "<<roll2<<" = "<<sum<<endl;
	return sum;
	
}

/***************************************************************
Function:  double getWager(double) 

Use: This function takes and returns a desired wager from the user

Arguments: Double value of the player's current balance

Returns: Double that represents the user's wager

Note: Will return the wager if it is valid (not over user's balance)
***************************************************************/

double getWager(double balance) {
	
	//declare wager to return
	int wager;
	
	if (balance<5) {
		cout<<"You have $";
		cout<<fixed<<setprecision(2)<<balance<<" available."<<endl;
		cout<<"I'm sorry but you do not have enough money to continue playing.\n"<<endl;
		cout<<"Your final balance is $";
		return(0);
	}
	
	else {
		cout<<"You have $";
		cout<<fixed<<setprecision(2)<<balance<<" available."<<endl;
		cout<<"How much would you like to wager (Minimum wager: $5.00)? ";
		cin>>wager;		
		if (wager>balance) {
			while (wager>balance) {
			cout<<"You cannot wager $";
			cout<<fixed<<setprecision(2)<<wager<<".  Try again: ";
			cin>>wager;	
			}
		}
	}
	
	return wager;

}

