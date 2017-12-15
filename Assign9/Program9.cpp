/***************************************************************
CSCI 240         Program 9     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	11/18/2016

Purpose: This program implements and uses the methods for a 
		 class called myInt
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class myInt {
	
public:
	myInt();
	myInt(int);
	void setInt(int);
	void getInt();
	void print();
	int sumDigits();
	int reverse();
	int oddDigitCount();
	int evenDigitCount();
	int zeroCount();
		
private:
	int value;	
	
};

int main() {
	
	//call srand
	srand(815);
	
	//declare vars
	int i, randNum;
	
	//generate random number and create class
	randNum=rand();
	myInt int1=myInt(randNum);
	
	//loop that changes the random number using setInt
	//and processes/displays the methods used
	for (i=0; i<11; i++) {
		cout<<"The number is ";
		int1.print();
		cout<<"\n----------------------------------------------------\n";
		cout<<"Adding the digits result 	"<<int1.sumDigits()<<endl;
		cout<<"Reversing the digits result     "<<int1.reverse()<<"\n\n";
		cout<<"Odd digits          "<<int1.oddDigitCount()<<endl;
		cout<<"Even digits         "<<int1.evenDigitCount()<<endl;
		cout<<"Zeroes              "<<int1.zeroCount()<<"\n\n\n";
		randNum=rand();
		int1.setInt(randNum);
	}
	
	return(0);
	
}

/**********************************************************
Constructor: myInt()

This is a default constructr that sets the int value
variable to 0.
**********************************************************/
myInt::myInt() {
	
	value=0;
	
}

/**********************************************************
Constructor: myInt(int integerValue)

This constructor takes an integer and sets it using
setInt()
**********************************************************/
myInt::myInt(int integerValue) {
	
	setInt(integerValue);
	
}

/**********************************************************
void setInt(int value)

This accessor method is used to change the value of the 
integer data member. It takes one argument: an integer that
will potentially be used to update the value of the integer 
data member. It returns nothing.
**********************************************************/
void myInt::setInt(int integerValue) {
	
	if (integerValue>0)
		value=integerValue;
	else
		value=abs(integerValue);	
	
}

/**********************************************************
int sumDigits()

This method will calculate and return the sum of adding the 
individual digits of the integer data member.  It takes no
arguments and returns an integer: the sum of the digits.
**********************************************************/
int myInt::sumDigits() {
	
	int sum=0;
	int num=value;
	
	while (num!=0) {
		sum=sum+value%10;
		num=num/10;
	}
	
	return sum;
	
}

/**********************************************************
int reverse()

This method will reverse the digits in the integer data 
member.  It takes no arguments and will return an integer
with a value equal to the reversed number.
**********************************************************/
int myInt::reverse() {
	
	int reverseNum=0;
	int digit;
	int num=value;
	
	while (num!=0) {
		reverseNum=reverseNum*10;
		digit=num%10;
		reverseNum=reverseNum+digit;
		num=num/10;
	}
	
	return reverseNum;
	
}

/**********************************************************
int oddDigitCount()

This method will count the number of odd digits that are 
part of the value in the integer data member. It takes no 
argument and returns an integer: the count of the odd 
digits.
**********************************************************/
int myInt::oddDigitCount() {
	
	int num=value;
	int odds=0;
	int digit;
	
	while (num!=0) {
		digit=num%10;
		if ((digit % 2) != 0)
			odds++;
		num=num/10;	 
	}
	
	return odds;
	
}

/**********************************************************
int evenDigitCount()

This method will count the number of even digits that are 
part of the value in the integer data member. It takes no 
argument and returns an integer: the count of the even
digits.
**********************************************************/
int myInt::evenDigitCount() {
	
	int num=value;
	int evens=0;
	int digit;
	
	while (num!=0) {
		digit=num%10;
		if ((digit % 2) == 0)
			evens++;
		num=num/10;	 
	}
	
	return evens;
	
}

/**********************************************************
int zeroCount()

This method will count the number of zeroes that are part 
of the value in the integer data member. It takes no 
argument and returns an integer: the count of the zeroes.
**********************************************************/
int myInt::zeroCount() {
	
	int num=value;
	int zeroes=0;
	int digit;
	
	while (num!=0) {
		digit=num%10;
		if (digit==0)
			zeroes++;
		num=num/10;	 
	}
	
	return zeroes;
	
}

/**********************************************************
void print()

This method displays the integer data member.  It takes no
arguments and returns nothing.
**********************************************************/
void myInt::print() {
	
	cout<<value;
	
}

