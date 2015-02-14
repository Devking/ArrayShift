#include <iostream>
#include <deque>
using namespace std;

int main() {
	int shift = 0;
	cout << "Left rotate by how much?\n> ";
	cin >> shift;

	deque<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	cout << "Original Deque:\n";
	for (int k = 0; k < arr.size(); k++)
		cout << arr[k] << " ";

	shift %= arr.size();

	for (int i = 0; i < shift; i++) {
		arr.push_back( arr.front() );
		arr.pop_front();
	}

	cout << "\nShifted Deque:\n";
	for (int j = 0; j < arr.size(); j++)
		cout << arr[j] << " ";

	cout << endl;
}