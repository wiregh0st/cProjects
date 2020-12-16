/*

Mason Miller
LAB4_2_daysOfChristmas.cpp
Program will ask user to input a day of the Twelve Days of Christmas. Based on that input, the program will output the appropriate gift.
PSEUDOCODE:
Program will ask user to input a day of the Twelve Days of Christmas (stored in int-dayChoice). Program will
validate user input by not permitting a value <= 0 or >= 13 (range 1-12). Program will then output a value based on a switch statement.
Cases are as follows:
case 1 : A partridge in a pear tree
case 2 : Two turtle doves
case 3 : Three French hens
case 4 : Four calling birds
case 5 : Five gold rings
case 6 : Six geese a-laying
case 7 : Seven swans a-swimming
case 8 : Eight maids a-milking
case 9 : Nine ladies dancing
case 10 : Ten lords a-leaping'
case 11 : Eleven pipers piping
case 12 : Twelve drummers drumming

*/

#include <cmath>
#include <cstdlib>
#include <iostream>


using namespace std;

int main()
{
	int dayChoice;

	dayChoice = 0;

	cout << "Please enter one of the days of The Twelve Days of Christmas to see the appropriate gift! (Valid values are between 1 and 12): ";
	cin >> dayChoice;
	cout << endl;

	while ((dayChoice <= 0) || (dayChoice >= 13))
	{
		cout << "You have entered an invalid value for one of the Twelve Days of Christmas. Please enter a value between 1 and 12: ";
		cin >> dayChoice;
	}

	if ((dayChoice > 0) || (dayChoice < 13))
	{
		switch (dayChoice)
		{
		case 12:
			cout << "Twelve drummers drumming.\n";
			break;
		case 11:
			cout << "Eleven pipers piping.\n";
			break;
		case 10:
			cout << "Ten lords a-leaping'.\n";
			break;
		case 9:
			cout << "Nine ladies dancing.\n";
			break;
		case 8:
			cout << "Eight maids a-milking.\n";

		case 7:
			cout << "Seven swans a-swimming.\n";
			break;
		case 6:
			cout << "Six geese a-laying.\n";
			break;
		case 5:
			cout << "Five gold rings.\n";
			break;
		case 4:
			cout << "Four calling birds.\n";
			break;
		case 3:
			cout << "Three French hens.\n";
			break;
		case 2:
			cout << "Two turtle doves.\n";
			break;
		case 1:
			cout << "A partridge in a pear tree.\n";
			break;
		}

	}

	return EXIT_SUCCESS;
}


