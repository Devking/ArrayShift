// Code written by Wells Lucas Santo
// 13 February 2015

// include the below line to debug the program
#define DEBUG
#include <stdio.h>

int main() {
	int shift = 0;
	printf("Left-rotate the array by how much?\n> ");
	scanf("%d", &shift);
	
	// just for an example, i will initialize the array directly
	// in practice, we can build this array from user data

	//// you can freely change this following array and the rest
	//// of the program will still compile and run correctly
	//// ...as long as the array is valid, of course
	int arr[5] = {0,1,2,3,4};

	// since arrays are merely contiguous blocks of memory in C,
	// there is no "size()" method to be used. instead, sizeof()
	// must be used to see how many bytes the array allocates.
	// i divide by sizeof(int) (since each int is 4 bytes) to
	// get the number of elements in the array
	int size = sizeof(arr) / sizeof(int);

	// note: this algorithm does require a space complexity of 'n'
	int arr2[size];

	for (int i = 0; i < size; i++) {
		// this syntax gets a bit messy, since C/C++ allows modulo
		// to be evaluated as negative (whereas python would always return
		// the positive value that we mathematically expect).

		// this is just a way to deal with negative values, as
		// well as be robust for any value of 'shift'!
		int newindex = ((i - shift) % size + size) % size;
		arr2[newindex] = arr[i];
	}

	// the algorithm is finished!
	// while it takes a space complexity of 'n', it takes
	// a runtime of Big-Theta(n) (since it needs to loop through
	// the entire collection once)
	
	// if we wish to debug the program, we will also
	// print the new array out (otherwise, we use defguards
	// to save compile time and skip this all together)
	#ifdef DEBUG
	printf("Original Array:\n");
	for (int j = 0; j < size; j++)
		printf("%d ", arr[j]);
	
	printf("\nShifted Array:\n");
	for (int k = 0; k < size; k++)
		printf("%d ", arr2[k]);
	#endif

	printf("\n");

}