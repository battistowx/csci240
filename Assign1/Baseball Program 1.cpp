/***************************************************************
CSCI 240         Baseball Program 1     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	9/2/2016

Purpose: This program calculates the number of singles and total
         number of bases for a baseball player.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	int hits, doubles, triples, hr, totSingles, totBases;
	
	//get number of hits
	cout << "Enter number of hits: "
	cin >> hits;
	
	//get number of doubles
	cout << "Enter number of doubles: ";
	cin >> doubles;
	
	//get number of triples
	cout << "Enter number of triples: ";
	cin >> triples;
	
	//get number of home runs
	cout << "Enter number of home runs: ";
	cin >> hr;
	
	//calculate singles
	totSingles=hits-doubles-triples-hr;
	
	//calculate bases
	totBases=totSingles+(doubles*2)+(triples*3)+(hr*4);
	
	//display calculations
	cout << endl << endl;
	cout << "Singles: " << totSingles;
	cout << "	Doubles: " << doubles; 
	cout << "	Triples: " << triples;
	cout << "	Home Runs: " << hr << endl << endl;
	cout << "Total Bases: " << totBases;
	return 0;
	
}
