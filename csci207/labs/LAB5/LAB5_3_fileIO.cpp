/*

Mason Miller
LAB5_3_FileIO.cpp

Instructions
// Practice with I/O Your Name & Date
// This program shall read an account number, previous balance, payment, and total purchases from a file.
// The program shall calculate the finance charge by:
// finance charge = 0.015 (Previous balance - payment)
// Then calculate the new balance by:
// new Balance = previous balance - payment + finance charge + purchases
// Output shall be identified with headings. See below for example.
// include all necessary header files
// don’t forget: using namespace std;
int main()
{
 // Declare the variables
 // Include format statements where they are needed
 PSEUDOCODE:
 * ***** The following statements are pseudocode for the program.
1. Open the file for output.
2. Open the file for input.
3. Write the headings to the output file.
4. Read the account number, previous balance, payment, and total purchased.
5. You can assume the data read from the file has been ‘scrubbed’. That is, assume it is correct.
6. Calculate finance charge by: finance charge = 0.015 (Previous balance - payment)
7. Calculate the new Balance by the formula:
 new Balance = previous balance - payment + finance charge + purchases
8. Print account number, previous balance, payment, total purchased, finance charge, and new
balance to the output file.
9. Close both files.
 ************* *

*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	double charge = 35.53;
	double account = 0.00;
	double oldBal = 0.00;
	double payment = 0.00;
	double purchase = 0.00;

	ifstream LAB5_3_data("LAB5_3_data.dat");
	ofstream LAB5_3_dataUpdated("LAB5_3_dataUpdated.dat");

	LAB5_3_dataUpdated << "Account #" << string(4, ' ') << "Old Balance" << string(4, ' ') << "Payment" << string(4, ' ') << "Total Purchased" << string(4, ' ') << "Charge" << string(4, ' ') << "New Bal" << endl;

	LAB5_3_data >> account >> oldBal >> payment >> purchase;
	
	double financeCharge = (0.015 * (oldBal - payment));
	double newBal = (oldBal - payment + financeCharge + purchase);

	LAB5_3_dataUpdated << account << string(8, ' ') << oldBal << string(8, ' ') << payment << string(8, ' ') << purchase << string(13, ' ') << charge << string(5, ' ') << newBal << endl;



	return EXIT_SUCCESS;

}
