/*
	Mason Miller
	HWK4_2_updatedCalc.cpp
	Program will be able to perform simple mathematical operations.
	Pseudocode: Display to screen input numOne and numTwo. Accept input
	for numOne and numTwo. Ask user to enter a character (+,-,*,/) (stored in char userChoice). Switch statement performed on userChoice performs the appropriate user selected
	operation. Input validation is performed within the switch statement. This is redundant, however, as input validation is performed with a while statement prior to the
	use of the switch statement.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctype.h>

using namespace std;

int main()
{
	int numOne = 0;
	int numTwo = 0;
	char userChoice = 'm';

	cout << "You will enter two numbers and then input what operation you would like to be performed on the numbers.\n\n";
	cout << "Please input your first number: ";
	cin >> numOne;
	cout << endl;
	cout << "Please input your second number: ";
	cin >> numTwo;
	cout << "\n\n";

			cout << "|--------------------------------|\n";
			cout << "|  Type + for addition           |\n";
			cout << "|                                |\n";
			cout << "|  Type - for subtraction        |\n";
			cout << "|                                |\n";
			cout << "|  Type * for multiplication     |\n";
			cout << "|                                |\n";
			cout << "|  Type / for division           |\n";
			cout << "|________________________________|\n\n";
			
			cin >> userChoice;

			while ((userChoice != '+') && (userChoice != '-') && (userChoice != '*') && (userChoice != '/')) {			//input validation for userChoice.
				cout << "You have entered an invalid operation character. Please enter a new operation selection: ";
				cin >> userChoice;
				
			}

		switch (userChoice) {					//input validation performed at end of switch statement via default, however, this is redundant due to WHILE.
		case '+':
			cout << "\nAddition: " << numOne << " + " << numTwo << " = " << numOne + numTwo << endl;
			break;
		case '-':
			cout << "\nSubtraction: " << numOne << " - " << numTwo << " = " << numOne - numTwo << endl;
			break;
		case '/':
			cout << "\nDivision: " << numOne << " / " << numTwo << " = " << numOne / numTwo << endl;
			break;
		case '*':
			cout << "\nMultiplication: " << numOne << " * " << numTwo << " = " << numOne * numTwo << endl;
			break;
		default:
			cout << "\nYou have entered an invalid operation selection. Please try again.";
}

	return EXIT_SUCCESS;
}
