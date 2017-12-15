/***************************************************************
CSCI 240         Program 10     Fall 2016

Programmer:	Chris Battisto

Section:	001 Musich

Date Due:	12/2/2016

Purpose: 	This program checks to see if the passed LoShu
			squares are "magic"
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

class LoShuMagicSquare {
	
public:
	LoShuMagicSquare();
	void fillSquare(const char[]);
	void printSquare();
	bool isMagic();
	
private:
	const int maxRows=3;
	const int maxColumns=3;	
	int loshuArray[maxRows][maxColumns];	
	
};

int main() {
	
	
	//Create a LoShuMagicSquare object that will be used to test the 4 puzzles
	LoShuMagicSquare puzzle;


	//Puzzle 1 using loshu_puzzle1.txt. The object will be filled, displayed,
	//and then tested to see if it is a valid solution

	cout << "Puzzle 1:" << endl << endl;
	puzzle.fillSquare( "loshu_puzzle1.txt");

	puzzle.printSquare();

	cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


	//Puzzle 2 using loshu_puzzle2.txt. The object will be filled, displayed,
	//and then tested to see if it is a valid solution
	cout << "Puzzle 2:" << endl << endl;

	puzzle.fillSquare( "loshu_puzzle2.txt");

	puzzle.printSquare();

	cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


	//Puzzle 3 using loshu_puzzle3.txt. The object will be filled, displayed,
	//and then tested to see if it is a valid solution
	cout << "Puzzle 3:" << endl << endl;

	puzzle.fillSquare( "loshu_puzzle3.txt");

	puzzle.printSquare();

	cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


	//Puzzle 4 using loshu_puzzle4.txt. The object will be filled, displayed,
	//and then tested to see if it is a valid solution
	cout << "Puzzle 4:" << endl << endl;

	puzzle.fillSquare( "loshu_puzzle4.txt");

	puzzle.printSquare();

	cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


	return 0;

}

/**********************************************************
Constructor: LoShuMagicSquare()

This is a default constructr that sets the array values
to 0.
**********************************************************/
LoShuMagicSquare::LoShuMagicSquare() {
	
	loshuArray[][]={{0,0,0}
					{0,0,0}
					{0,0,0}};
	
};

/**********************************************************
void fillSquare( const char [] )

This is a public method that will fill the two-dimensional 
array data member with information that is read from a file.
It takes 1 argument: an array of constant characters that 
represents the name of a file that holds the information to 
place into the array. It returns nothing.
**********************************************************/
LoShuMagicSquare::fillSquare(const char[]) {
	
	//open file
	ifstream infile
	infile.open(char[]);
	
	//check if file opened correctly
	if (infile.fail()) {
        cout<<"input file did not open"<<endl;
        exit(-1);
    }
	
	//build array col. 1
	for (int i=0; i<3; i++) {
		getline(infile, loshuArray[0][i]);
	}
	
	//build array col. 2
	for (int i=0; i<3; i++) {
		getline(infile, loshuArray[1][i]);
	}
	
	//build array col. 3
	for (int i=0; i<3; i++) {
		getline(infile, loshuArray[2][i]);
	}
	
};

/**********************************************************
void printSquare()

This is a public method that will display the two-
dimensional array to the screen as 3 rows or 3 columns (the
 same way the numbers appear in the input file). It takes 
 no arguments and returns nothing.
**********************************************************/
LoShuMagicSquare::printSquare() {
	
	cout<<infile.rdbuf();
	
};

/**********************************************************
bool isMagic()

This is a public method that will determine if the two-
dimensional array contains a valid Lo Shu Magic Square 
solution. It takes no arguments and returns a boolean: true 
if the solution is valid or false if the solution is not 
valid.
**********************************************************/
LoShuMagicSquare::isMagic() {
	
	//check for duplicate numbers
	for (int r=0; r<loshuArray.length; r++) {
        for (int c=0; c<loshuArray[r].length; c++) {
            int num=inArray[r][c];
            for (int otherCol=c+1; otherCol<loshuArray.length; otherCol++) {
                if (num==loshuArray[r][otherCol]) {
                    return false;
                }
            }
        }
    }
    
    //check if sums of rows are all same
    int r1=loshuArray[0][0]+loshuArray[0][1]+loshuArray[0][2];
    int r2=loshuArray[1][0]+loshuArray[1][1]+loshuArray[1][2];
    int r3=loshuArray[2][0]+loshuArray[2][1]+loshuArray[2][2];
    if (r1!=r2 && r2!=r3 && r1!=r3)
    	return false;
    
	//check if sums of columns are all same	
	int c1=loshuArray[0][0]+loshuArray[1][0]+loshuArray[2][0];
    int c2=loshuArray[0][1]+loshuArray[1][1]+loshuArray[2][1];
    int c3=loshuArray[0][2]+loshuArray[1][2]+loshuArray[2][2];
    if (c1!=c2 && c2!=c3 && c1!=c3)
    	return false;
    	
    return true;	
};






