/*

Mason Miller
LAB4_3_switchRPS.cpp
Program will ask user to input name and then input which of the three moves they want. the program compares user input to computer random # and outputs win/loss based on this.
PSEUDOCODE:
generate random number using srand(time(NULL)). ask for user name (stored in string user1). ask user for an integer that will determine which move they want (stored in user1Choice).
random number will be held between 1 and 3 using modulus (stored in compChoice). using user1Choice and compChoice, program will output what the user selected, what the computer selected,
and the result (win/loss).

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	string user1;

	int user1Choice = 0;
	int compChoice = 0;
	
	srand(time(NULL)); //initialize random number

	cout << "Please enter player 1 name: ";
	cin >> user1;
	
	cout << "\nPlayer 1, please choose 1 for ROCK, 2 for SCISSORS, or 3 for PAPER : ";
	cin >> user1Choice;

	while ((user1Choice != 1) && (user1Choice != 2) && (user1Choice != 3)) {
		cout << "\n\nYou have entered an incorrect number for your choice. Please choose 1 for ROCK, 2 for SCISSORS, or 3 for PAPER :";
		cin >> user1Choice;
	}

	switch (user1Choice) {
		case 1:
			cout << "\n\nYou chose ROCK.";
			break;
		case 2:
			cout << "\n\nYou chose SCISSORS.";
			break;
		case 3:
			cout << "\n\nYou chose PAPER.";
			break;
		default:
			cout << "\n\nYou have selected an incorrect character. Please try again.";
	}

	compChoice = rand() % 3 + 1; //set compChoice equal to random number. take modulus of random number by 3 then add 1 to that number. never allows for 0 and top value is 3.

	switch (compChoice) {
		case 1:
			cout << "\n\nComputer chose ROCK.";
			break;
		case 2:
			cout << "\n\nComputer chose SCISSORS.";
			break;
		case 3:
			cout << "\n\nComputer chose PAPER.";
			break;
		default:
			cout << "\n\nComputer has selected an incorrect character. We are not sure how that was possible, but, please try again.";
	}
	
	if (user1Choice == compChoice) {
		cout << "\n\nIt's a tie!";
	}
	else if ((user1Choice == 1) && (compChoice == 2)){
		cout << "\n\nUser wins!";
	}
	else if ((user1Choice == 2) && (compChoice == 3)) {
		cout << "\n\nUser wins!";
	}
	else if ((user1Choice == 3) && (compChoice == 1)) {
		cout << "\n\nUser wins!";
	}
	else {
		cout << "\n\nComputer wins!";
	}

	return EXIT_SUCCESS;
}

