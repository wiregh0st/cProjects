/*

Mason Miller
HWK6_1_BabyNames.cpp

*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	string firstData;
	string inputName;
	string boy;
	string girl;


	int rank = 0;


	ifstream input;

	input.open("babyNames2012.txt"); //open input stream INPUT; file as listed.

	cout << "Please enter a name (CASE MUST MATCH) : ";
	cin >> inputName;
	cout << endl;

	while (input) {
		getline(input, firstData); //use getline to read through spaces. read from input and store in string readData.

		stringstream initialData(firstData);		//store readData from input file into stringstream streamData

		initialData >> rank;
		initialData >> boy;
		initialData >> girl;

		if ((inputName == boy) || (inputName == girl)) {
			if (inputName == boy) {
				cout << boy << " ranks " << rank << " in popularity among boys." << endl;
			}
			else if (inputName == girl) {
				cout << girl << " ranks " << rank << " in popularity among girls." << endl;
			}
			
		}

	}
		

	}
	





