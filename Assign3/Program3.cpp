/***************************************************************
CSCI 240         Program 3     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	9/16/2016

Purpose: This program assigns a random salary and amount of work
days to calculate and display running salary and total earned at 
the end of the working period.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	//declare vars
	int i, randWorkDays, bonuses;
	double randSalary, startSalary, totalPay, totalEarned, bonusPay, salary;
	i=1;
	totalEarned=0;
	bonuses=0;
	bonusPay=0;
	salary=0;
	
	//call srand function
	srand(1);
	
	//generate starting salary
	randSalary=rand() % 6 + 1;
	startSalary=randSalary / 100;
	salary=startSalary;
	
	//generate work days
	randWorkDays=rand() % 31 + 1;
	
	//display salary/days to work and bonuses
	cout<<"Starting Salary: $"<<setprecision(2)<<startSalary<<endl;
	cout<<"Number of days to work: "<<randWorkDays<<endl<<endl;
	bonuses=randWorkDays/5;
	bonusPay=startSalary*bonuses;
	
	//loop that calculates/displays salary per day/total pay
	while (i!=randWorkDays) {
		
		//set values and display day/pay
		totalEarned=totalEarned+salary;
		cout<<"Day "<<setw(2)<<i<<":"<<setw(10)<<setprecision(8)<<salary<<endl;
		salary=salary*2;
		i+=1;
		
	}
	
	//display total earned and bonus info
	cout<<"\nYou made $"<<setprecision(8)<<totalEarned<<" and earned "<<bonuses<<" bonuses of $"<<setprecision(2)<<bonusPay;
	return 0;
	
}
	
