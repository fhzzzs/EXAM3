/*
	Ivan Ao

	11/9/2020

	CS A250

	PE3
*/
#include "TArray.h"
#include "TArray.cpp"
#include <iostream>


using namespace std;

int main()
{
	TArray<int> nda;

	nda.insert(5);
	nda.insert(2);
	nda.insert(5);					// wont insert duplicate 5
	nda.insert(1);
	nda.insert(7);
	nda.insert(15);

	//TArray<int> ndaCopy(nda);		// test copy constructor
	TArray<int> ndaCopy = nda;
	
	cout << nda[4] << "\n";			// prints 15
	//cout << nda[5] << "\n";			// Error out of range

	nda.printArray();				// prints the array
	cout << nda << "\n";			// prints of array using insertion op
	cout << ndaCopy << "\n";		// prints copy of array

	system("pause");
	return 0;
}