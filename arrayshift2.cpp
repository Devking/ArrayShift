// Code written by Wells Lucas Santo
// 13 February 2015

// include the below line to debug the program
#define DEBUG
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int shift = 0;
	cout << "Left rotate by how much?\n> ";
	cin >> shift;

	// fill the vector manually
	// of course, this can be done during runtime
	// by taking user input
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	// make robust for any number 'shift' based on
	// the size of the vector
	shift %= arr.size();

	// this algorithm does still require 'n' space complexity
	vector<int> arr2;

	// using vectors is merely nicer since "size()" is
	// easily accessible. we can also use push_back to
	// easily build the second vector, instead of having
	// to use complicated arithmetic.
	for (int i = 0; i < arr.size()-shift; i++)
		arr2.push_back(arr[i+shift]);

	for (int j = 0; j < shift; j++)
		arr2.push_back(arr[j]);

	// the algorithm is now finished, and took
	// Big-Theta(n) of runtime as well

	#ifdef DEBUG

	cout << "Original Vector:\n";
	for (int k = 0; k < arr.size(); k++)
		cout << arr[k] << " ";
	cout << "\nShifted Vector:\n";
	for (int m = 0; m < arr2.size(); m++)
		cout << arr2[m] << " ";

	#endif

	cout << endl;
}