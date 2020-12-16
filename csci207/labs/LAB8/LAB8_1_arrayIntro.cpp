/*

Mason Miller

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    
	double gpaArray[15];
	
	double nums = 0;

	double total = 0;

	double average = 0;

	int sub = 0;

	int count = 0;

	ifstream inFile("inFile.txt");

	if(!inFile){
		cout << "File failed to open. Exiting program...";		//verify input file opened correctly.
		return EXIT_FAILURE;
	}

	cout << fixed << setprecision(1);	//all cout below this will be displayed with 1 decimal place.

	
	while (!inFile.eof()) {			//while not end of file, read data from file into nums. store data in variable nums into array gpaArray starting at sub (0).

		inFile >> nums;

		gpaArray[sub] = nums;
		
		sub++;

	}

	inFile.close();			//close input file.

	sub = sub - 1;		//decrement sub so sub = number of elements in array.
	
	cout << " " << setw(12) << "GPA" << endl << endl;				//header.

	for (count = 0; count <= sub; count++) {			//for loop to output GPA to screen.
		
		cout << " " << setw(12) << gpaArray[count] << endl;

		total = total + gpaArray[count];		//gather total.

	}
	
	average = total / count;		

	cout << "average:  " << average;		//ouput average.

	return EXIT_SUCCESS;
	
}

