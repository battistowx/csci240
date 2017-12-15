/***************************************************************
CSCI 240         Program 2     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	9/9/2016

Purpose: This program expands upon program 1 and calculates
slugging percentage.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	int hits, doubles, triples, hr, totSingles;
	float totBases, atBats, slugPer;
	
	//get number of hits
	cout << "Enter number of hits: ";
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
	
	//get number of at bats
	cout << "Enter the number of at bats: ";
	cin >> atBats;
	
	//calculate singles
	totSingles=hits-doubles-triples-hr;
	
	//calculate bases
	totBases=totSingles+(doubles*2)+(triples*3)+(hr*4);
	
	//calculate slugging percentage
	slugPer=totBases/atBats;
	
	//display calculations
	cout << endl << endl;
	cout << "Singles: " << totSingles;
	cout << "	Doubles: " << doubles; 
	cout << "	Triples: " << triples;
	cout << "	Home Runs: " << hr << endl << endl;
	cout << "Total Bases: " << totBases << endl << endl;
	cout << "Slugging Percentage: " << setprecision(3) << slugPer;	
	return 0;
	
}
