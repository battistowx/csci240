/***************************************************************
CSCI 240         Program 6     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	10/21/2016

Purpose: 	This program decodes Little Orphan Annie's secret code
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

int main() {
	
	//create stream var and connect, open file for reading
	ifstream infile;
	infile.open("encoded_quotes.txt");
	
	//check if file failed to open
	if (infile.fail()) {
		cout<<"input file did not open"<<endl;
		exit(-1);
	}
	
	//declare var for characters in the file
	char ch;
	infile>>ch;
	int i=0;
	
	//declare functions
	bool isspecial(char ch);
	char changeLower(char ch);
	char changeUpper(char ch);
	char changePunct(char ch);
	char changeDigit(char ch);
	char changeSpecial(char ch);
	
	//declare decoded message character var
	char decodedChar;

	//Processing loop begins (while chars in file)
	while (!infile.eof()) {
		
		//get each character
		infile.get(ch);
		
		//test/display if the character is alphabetical
		if (isalpha(ch)) {

			//check if lower/upper case
			if (islower(ch)) {
				decodedChar=changeUpper(ch);
				cout<<decodedChar;
			}
			else if (isupper(ch)){
				decodedChar=changeLower(ch);
				cout<<decodedChar;
			}

		}

		//test/display if character is special
		else if (isspecial(ch)) {
			decodedChar=changeSpecial(ch);
			cout<<decodedChar;
		}
		
		//test/display if character is a punctuation symbol
		else if (ispunct(ch)) {
			decodedChar=changePunct(ch);
			cout<<decodedChar;
		}
		
		//test/display if character is a digit
		else if (isdigit(ch)) {
			decodedChar=changeDigit(ch);
			cout<<decodedChar;
		}
		
	}
	
	cout<<"\n\n-'A Christmas Story' (1983)";
	
	//close file
	infile.close();
	return(0);
	
}

/***************************************************************
Function:  bool isspecial(char ch) 

Use: This function returns a boolean variable if the character
is a special value

Arguments: Character from file

Returns: True/false if character is special

Note: Tests the character's ASCII value
***************************************************************/
bool isspecial(char ch) {
	
	bool special;
	
	//cast ch to type int
	int ascii=ch;
	
	//test if it is ASCII 20 or 22
	if (ascii==20||ascii==22) {
		special=true;
		return special;
	}
	else {
		special=false;
		return special;
	}

 }
 
/***************************************************************
Function:  char changeLower(char ch) 

Use: This function takes a lower case character and returns
the decoded character

Arguments: Character from file

Returns: Decoded character

Note: Decodes based upon given table in website
***************************************************************/
char changeLower(char ch) {
	
	//convert character to lower case, get ASCII, subtract one, convert
	//back to char and return it
	char passedChar=tolower(ch);
	int asciiCh=passedChar;
	//if "a", set equal to "z"
	if (asciiCh==97)
		asciiCh=122;
	else
		asciiCh--;
	char returnChar=asciiCh;
	return returnChar;
	
}
 
/***************************************************************
Function:  char changeUpper(char ch) 

Use: This function takes an upper case character and returns
the decoded character

Arguments: Character from file

Returns: Decoded character

Note: Decodes based upon given table in website
***************************************************************/
char changeUpper(char ch) {
	
	//convert character to upper case, get ASCII, add one, convert
	//back to char and return it
	char passedChar=toupper(ch);
	int asciiCh=passedChar;
	//if "Z", set equal to "A"
	if (asciiCh==90)
		asciiCh=65;
	else
		asciiCh++;
	char returnChar=asciiCh;
	return returnChar;
	
}

/***************************************************************
Function:  char changePunct(char ch) 

Use: This function takes a punctuation symbol and decodes it

Arguments: Character from file

Returns: Decoded character

Note: Decodes based upon given table in website
***************************************************************/
char changePunct(char ch) {
	
	//Use switch statements below to convert the punctuation
	//into the decoded character
	switch (ch) {
		case ')':
			ch='0';
			break;
		case '!':
			ch='1';
			break;
		case '@':
			ch='2';
			break;
		case '#':
			ch='3';
			break;
		case '$':
			ch='4';
			break;
		case '%':
			ch='5';
			break;
		case '^':
			ch='6';
			break;
		case '&':
			ch='7';
			break;
		case '*':
			ch='8';
			break;
		case '(':
			ch='9';
			break;
	}
	
	return ch;
	
}

/***************************************************************
Function:  char changeDigit(char ch) 

Use: This function takes an integer digit and decodes it

Arguments: Character from file

Returns: Decoded character

Note: Decodes based upon given table in website
***************************************************************/
char changeDigit(char ch) {
	
	//Use switch statements below to convert the punctuation
	//into the decoded character
	switch (ch) {
		case '9':
			ch=',';
			break;
		case '8':
			ch='"';
			break;
		case '7':
			ch='!';
			break;
		case '6':
			ch=';';
			break;
		case '5':
			ch='?';
			break;
		case '4':
			ch='\'';
			break;
		case '3':
			ch='(';
			break;
		case '2':
			ch=')';
			break;
		case '1':
			ch='.';
			break;
		case '0':
			ch='-';
			break;
	}
	
	return ch;
	
}

/***************************************************************
Function:  char changeSpecial(char ch) 

Use: This function takes the special character and decodes it

Arguments: Character from file

Returns: Decoded character

Note: Decodes based upon given table in website
***************************************************************/
char changeSpecial(char ch) {
	
	//convert ch to ASCII
	int ascii=ch;
	
	//decode and return character.  If it does not need to be decoded
	//then return the passed char.
	if (ascii==22) {
		char returnChar=' ';
		return returnChar;
	}
	else if (ascii==20) {
		char returnChar='\n';
		return returnChar;
	}
	else
	return ch;
	
}

