// Code written by Wells Lucas Santo
// 13 February 2015

/* Earlier version hard-coded the number of elements to add to the text file:
#ifndef DUMMYGUARD
#define DUMMYGUARD
// set this to be the number of elements you want in the text file
// since we talked about 1 million elements today, that's the number i'm using
// i'm asking using a #define to avoid the bad coding practice of magic numbers
#define DUMMYELEMENTS 10000
#endif
*/

#include <iostream>
#include <fstream>
using namespace std;

int main () {

	// two things may happen with this line:
	// (1) if data.txt exists, it will open it, clear it, and allow us to write over it
	// (2) if data.txt does not exist, it will create it and write from beginning
	ofstream dummyData("data.txt");

	// this is just a safety check to see if any errors have occured at this point
	// with opening or creating the file
	if (!dummyData) {
		cerr << "Couldn't open!\n";
		exit(1);
	}

	int DUMMYELEMENTS;

	cout << "How many elements would you like in the text file?\n> ";
	cin >> DUMMYELEMENTS;

	// loop through and insert each number, comma delimited
	for (int i = 0; i < DUMMYELEMENTS; i++)
		dummyData << i << ',';

	// add the millionth element, with no final comma
	dummyData << DUMMYELEMENTS;

	// close the file, for good measure
	dummyData.close();
}