/*

Mason Miller
LAB7_3_ReferenceIntro

*/


#include <iostream>
#include <limits>

using namespace std;

double maxNum(double &num1, double &num2);

double maxNum(double &num1, double &num2, double &num3);				//declaration of PASS BY REFERENCE functions

double verInput(double &failTrue);




int main()
{
	double num1 = 0;
	double num2 = 0;
	double num3 = 0;
	double userIn = 0;					//declaration and assignment of variables.
	double failTrue = 0;
	


	num1 = verInput(failTrue);
	if (failTrue == 1) {
		cout << "error... exiting program";
		return EXIT_FAILURE;
	}	
	num2 = verInput(failTrue);
	if (failTrue == 1) {
		cout << "error... exiting program";				//verInput runs 3 times to accept 3 values: num1, num2, num3. input validation occurs within function.
		return EXIT_FAILURE;
	}	
	num3 = verInput(failTrue);
	if (failTrue == 1) {
		cout << "error... exiting program";
		return EXIT_FAILURE;
	}

	maxNum(num1, num2);
	maxNum(num1, num2, num3);

	return EXIT_SUCCESS;
	

}





double maxNum(double &num1, double &num2)
{
	if (num1 > num2) {
		cout << "num1 is max of function 1." << endl;
		return num1;
	}
	else if (num1 == num2) {
		cout << "num1 and num2 are equal in function 1." << endl;				//overloaded max function with 2 parameters to determine if num1 or num2 is greater.
		return num1;
	}
	else if(num2 > num1){
		cout << "num2 is max in function 1." << endl;
		return num2;
	}
	else {
		cout << "error";
	}

}

double maxNum(double &num1, double &num2, double &num3)
{
	if ((num1 > num2) && (num1 > num3)) {
		cout << "num 1 is max of function 2." << endl;
		return num1;
	}
	else if ((num2 > num1) && (num2 > num3)) {
		cout << "num 2 is max of function 2." << endl;					//overloaded max function with 3 parameters to determine if num1, num2, or num3 is greater.
		return num2;
	}
	else if ((num3 > num1) && (num3 > num2)) {
		cout << "num 3 is max of function 2." << endl;
		return num3;
	}
	else if ((num1 == num2) && (num2 == num3)) {
		cout << "all numbers in second function equal." << endl;
		return 0;
	}
	else {
		cout << "error";
	}

}

double verInput(double &failTrue) {

	failTrue = 0;
	double userIn = 0;
	int i = 0;				//counter for while.


	cout << "Enter a value: ";
	cin >> userIn;

	if (cin.fail()) {

		while (i < 2) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You entered an incorrect value. Please enter a number: ";		//input validation for parameters passed to max functions.
			cin >> userIn;
			cout << endl;
			i++;
		}
	}

	if (cin.fail()) {			//if cin.fail() still present after validation, set failTrue to 1 and return failTrue. else, return user input.
		failTrue = 1;
		return failTrue;

	}
	else {
		return userIn;
	}
}
		

	







