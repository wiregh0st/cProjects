
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

	ifstream babyNames("babynames2012.txt");

	string userInput = "a";


	int place_Holder_Rank = 0;
	int boyRank = 0;
	int girlRank = 0;

	
	string boy = "random";
	string girl = "random";

	string boyFound;
	string girlFound;


	if (!babyNames) {
		cout << "File failed to open";			//print statement and exit if file failed to open. WILL NOT CATCH CASE MISTYPES (i.e. a instead of A).
		return EXIT_FAILURE;			
	}


	cout << "Please enter a user: ";
	cin >> userInput;

	while (babyNames >> place_Holder_Rank >> boy >> girl) {		//while babyNames is open, store first int in place_Holder_Rank, boy name in boy, girl name in girl.

	
		if (userInput == boy)  {	

			boyFound = boy;
			boyRank = place_Holder_Rank;
			cout << boyFound << " ranks " << boyRank << " in popularity among boys." << endl;		//output boy name with rank.
			
		}														//if statements to output boy and girl names correctly with proper rank.

		else if (userInput == girl) {

			girlFound = girl;
			girlRank = place_Holder_Rank;
			cout << girlFound << " ranks " << girlRank << " in popularity among girls." << endl;	//output girl name with rank.
			
		}

		
	}
	
	if (userInput != girlFound)
	{
		cout << boyFound << " does not rank in the top 1000 girls." << endl;
	}
																					//check if userInput == girlFound OR boyFound. depending on conditions, output correct information. check with userInput against
																					//boyFound/girlFound as they will have the correct value if one is found. Otherwise, they will have string "random", and no output is assigned.
																					//has to be done outside while loop, othwerise will be output every time.
	if (userInput != boyFound) {
		cout << girlFound << " does not rank in the top 1000 boys." << endl;
	}


	babyNames.close();
	
}



