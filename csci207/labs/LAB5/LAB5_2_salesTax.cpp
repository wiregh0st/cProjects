/*

Mason Miller
LAB5_2_salesTax
Program will ask user to input month, year, and total amount collected at register. Program will then calculate various tax amounts. Program will then display to screen
Monthly : "month here" "date here"

---------------------------------
Total Collected:			$ total collected
Sales:						$ total sales
County Sales Tax:			$ total county sale tax
State Sales Tax:			$ total state sale tax
Total Sales Tax:			$ total sale tax for purchase

*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string month = "null";

	int year = 0;

	double totalCollected = 0;

	double salesTax = 0.06;
	double stateTax = 0.04;
	double countyTax = 0.02;

	double totalSales = 0; //S
	double totalCalcSalesTax = 0;
	double totalCalcCountyTax = 0;
	double totalCalcTax = 0;

	cout << "Please type the month: ";
	cin >> month;
	
	cout << "Please type the year: ";
	cin >> year;
	
	cout << "Please type how much money was collected at the register: ";
	cin >> totalCollected;
	totalSales = (totalCollected / 1.06);
	cout << "\n\n";

		 totalSales = (totalCollected / 1.06); //S
		 totalCalcSalesTax = (totalSales * stateTax);
		 totalCalcCountyTax = (totalSales * countyTax);
		 totalCalcTax = (totalSales * salesTax);

	cout << "Monthly: " << month << " " << year << "\n\n";
	cout << "-------------------------------------\n";
	cout << fixed << setprecision(2);																				//ALL NUMBERS AFTER THIS WILL BE IN FIXED FORMAT. 2 decimal places.
	cout << "Total Collected:" << setw(15) << "$ " << totalCollected << endl;
	cout << "Sales:" << setw(25) << "$ " << totalSales << endl;
	cout << "County Sales Tax:" << setw(14) << "$ " << totalCalcCountyTax << endl;
	cout << "State Sales Tax:" << setw(15) << "$ " << totalCalcSalesTax << endl;
	cout << "Total Sales Tax:" << setw(15) << "$ " << totalCalcTax << endl;

	return EXIT_SUCCESS;

}

