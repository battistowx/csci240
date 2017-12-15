/***************************************************************
 CSCI 240         Program 7     Fall 2016
 
 Programmer:	Chris Battisto
 
 Section:	001 Musich
 
 Date Due:	10/28/2016
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

int main() {
	
	//declare const
	const int ARSIZE=120;
    
    //declare vars
    string searchTerm;
    string teamArray[ARSIZE];
    int numTeams;
    int timesWon;
    
    //declare functions
    int buildArray(string team_array[]);
    int numWins(string team_array[], int numTeams, string search_team);
    
	//call buildArray function
	numTeams=buildArray(teamArray);
    
    //get user input and call functions, display final output
    cout<<"Enter a team: ";
    cin>>searchTerm;
    timesWon=numWins(teamArray, numTeams, searchTerm);
    cout<<"The "<<searchTerm<<" have won the World Series "<<timesWon<<" time(s).";
    return(0);
        
}

/***************************************************************
Function:  int buildArray(string team_array[]) 

Use: This function places the values from the input file into the
	passed array of strings

Arguments: Array of strings filled with names of the teams

Returns:  Number of teams that were placed into the array

Note: none
***************************************************************/
int buildArray(string team_array[]) {
	
	//declare vars
	int numTeams;
	int size;
	
	//create stream var and connect, open file for reading
    ifstream infile;
    infile.open("WorldSeriesWinners.txt");
    
    //check if file failed to open
    if (infile.fail()) {
        cout<<"input file did not open"<<endl;
        exit(-1);
    }
	
	//build array
	int j=0;
    for (int i=0; i<120; i++) {
    	getline(infile, team_array[i]);
	}
	
	//count teams in array and return size
	size=sizeof team_array[0] / sizeof team_array[0];
	return size;
	
}

/***************************************************************
Function:  int numWins(string team_array[], int numTeams, string
			search_team) 

Use: This function searches the array of world series winning teams
	and determine how many times that team won the world series.

Arguments: Array to be searched, number of teams in array, and
			string of specific team to search for in the array.

Returns:  Number of times that team was found in the array

Note: none
***************************************************************/
int numWins(string team_array[], int numTeams, string search_team) {
	
	int timesWon=0;
	
	//loop for counting world series victories
	for (int i=0; i<=numTeams; i++) {
		if (team_array[i]==search_team)
			timesWon++;
	}
	
	return timesWon;
	
}














