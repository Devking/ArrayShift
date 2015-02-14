// Wells Lucas Santo
// 13 February 2014

// #define DEBUG

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main () {

	// This opens the file for both reading and writing
	// Note: If the file does not exist, then this will not work
	ifstream dummyData("data.txt");

	// Error check to see if the file exists or not
	if (!dummyData) {
		cerr << "Couldn't open! Was the 'filltextfile' script run?\n";
		exit(1);
	}

	int shift = 0;
	cout << "Left rotate by how much?\n> ";
	cin >> shift;

	// Note: No smart way to test if shift is larger than the amount of elements
	// within the text file. We could check the file's length and extrapolate a
	// value if we know the file format, but otherwise we assume "shift" is smaller
	// than the number of elements in the file.

	// If "shift" is an amount greater than the amount of elements in the text file
	// then we will not change the ordering.

	string value = "";
	vector<string> shiftedElements;
	for (int i = 0; i < shift; i++) {
		// first, get the elements to be put to the back
		// and store them in a vector
		if (getline(dummyData, value, ','))
			shiftedElements.push_back(value);
		else
			break;
	}

	// We do create a new textfile to work with

	ofstream dummyShift("dataShifted.txt");

	// Put the rest of the elements from the old text file to the new text file

	while (getline(dummyData, value, ',')) {
		#ifdef DEBUG
		cout << value << " ";
		#endif
		dummyShift << value << ',';
	}

	// Append the original items to the end of the text file

	for (int j = 0; j < shiftedElements.size()-1; j++) {
		#ifdef DEBUG
		cout << shiftedElements[j] << " ";
		#endif
		dummyShift << shiftedElements[j] << ',';
	}
	dummyShift << shiftedElements[shiftedElements.size()-1];

	#ifdef DEBUG
	cout << shiftedElements[shiftedElements.size()-1];
	cout << endl;
	#endif

	// Thus the algorithm is finished!
	// This algorithm takes Big-Theta(n) runtime
	// This algorithm does create a new text file with all the shifted elements
	// but within the running of the program, only O(shift) amount of space is
	// allocated. This is much less stack space needed than the first three.

	dummyData.close();
	dummyShift.close();

}