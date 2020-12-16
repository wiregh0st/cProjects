/*

Mason Miller
LAB4_1_payCalc
Program will calculate gross pay for given employees.
Pseudocode: Program will ask user for pay rate and hours worked (stored in payRate and hoursWorked). If the hours worked is between 1 and 99, the value is accepted and program continues. Otherwise,
user is told that the value was not a good value and that they should enter a new value. Program then uses an if statement to check if hours worked is less than 40 or greater than/equal to 40. Program
performs calculation on payRate using hoursWorked. This new value is stored in grossPay. Program then outputs to screen hours worked, pay rate, and gross pay.

*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main()
{
	int hoursWorked;
	double payRate;
	double grossPay;

	cout << "Input pay rate: ";
	cin >> payRate;
	cout << endl;
	cout << "Input hours worked: ";
	cin >> hoursWorked;
	cout << endl;

	while ((hoursWorked < 1) || (hoursWorked > 99))
	{
		cout << "Please input a valid range for hours worked. Valid ranges are 1-99: ";
		cin >> hoursWorked;
		cout << endl;
	}

	if (hoursWorked < 40)
	{
		grossPay = payRate * hoursWorked;
	}
	else if (hoursWorked >= 40)
	{
		grossPay = (payRate * hoursWorked) + ((.5 * (hoursWorked - 40)) * payRate);
	}
	else 
	{
		grossPay = 0;
	}

	cout << "Hours worked: " << hoursWorked << "\n" << "Pay rate: " << payRate << "\n" << "Gross pay: " << grossPay << endl;

}


