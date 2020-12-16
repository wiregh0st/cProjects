/*

Mason Miller
LAB8_2_2dimArray.cpp

*/


#include <iostream>
#include <fstream>

using namespace std;

int fileCheck(ifstream &inFile);

void readArray(ifstream &inFile, int gradeArray[][3]);

void outputArray(ofstream &outFile, int gradeArray[][3]);


int main()
{
	ifstream inFile("8_2testData.txt");   //open input file.

	ofstream outFile("outData.txt");	//initialize output file.

	int gradeArray[6][3];				//array initilization.

	readArray(inFile, gradeArray);

	outputArray(outFile, gradeArray);

	return EXIT_SUCCESS;

}



int fileCheck(ifstream &inFile) {

	if (!inFile) {									//verify file opened successfully. If not, return failure and close program.
		cout << "File failed to open.";
		return EXIT_FAILURE;
	}

	return 101;
}

void readArray(ifstream &inFile, int gradeArray[][3]) {		//function reads values from file into array.

	fileCheck(inFile);

	const int MAX_R = 6;				//max rows.
	const int MAX_C = 3;				//max columns.


	int subR = 0;
	int subC = 0;

	inFile >> gradeArray[0][0];			//prime for input from file to array.

	subC++;								//increment columns by 1.

	while (!inFile.eof()) {		//store data from file into array until end of file bit reached.

		for (subR; subR < MAX_R; subR++) {

			for (subC; subC < MAX_C; subC++) {

				inFile >> gradeArray[subR][subC];

			}

			subC = 0;    //reset column count to 0.
		}

		break;		//break here because function will infinite loop if the file does not open successfully. The break prevents this from occuring.
	}

	inFile.close();			//close input file.

	return;
}

void outputArray(ofstream &outFile, int gradeArray[][3]) {		//function outputs data from array into a file.

	const int MAX_R = 6;				//max rows.
	const int MAX_C = 3;				//max columns.

	int subR = 0;
	int subC = 0;

	for (subR; subR < MAX_R; subR++) {			//for loops through rows then columns and outputs to a file.

		for (subC; subC < MAX_C; subC++) {

			outFile << gradeArray[subR][subC] << " ";

		}

		subC = 0;
		outFile << endl;
	}
}



