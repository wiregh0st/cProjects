/*

1. Print (cout) the heading: Investment of $24.00 in beads
2. Set the principal invested to 24.00.
3. For rates from 1 to 7 do
1. Convert rate by r = rate/100
2. Calculate the amount in 2018 by:
A = P(1+r)^n
where:
A is the amount at the end of n years,
n is the number of years,
P is the principal invested
r is the yearly interest rate as a decimal
4. Print the rate and amount to the output file.
Run the program using yearly interest rate values of 1, 2, 3, … 7 percent.

*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	double p = 24.00;  //initial (principal) investment
	double i;
	double r = 0.00;  //interest rate
	double n = 392;  //variable for number of years
	double endAmount = 0.00; //final amount after x years.

	ofstream outputFile;

	outputFile.open("LAB6_2output.dat");
	
	cout << fixed << setprecision(2);		//all cout statements after this will be with 2 decimal places.
	outputFile << fixed << setprecision(2); //all decimal outputs to outputFile will be with 2 dceimal places.


	cout << "Investment of $" << p << " in beads" << endl;		//header

	for (i = 1; i < 8; i++){

		r = (i / 100);		//assigning r to correct interest rate: i divided by 100.

		endAmount = (p * pow((1 + r), n));  //set endAmount = principal times 1+r raised to n(392) power.

		cout << "Rate of " << r << "% " << setw(20) << "Current Value $" << endAmount << "\n\n";		//output interest rate and current value based on endAmount function.
		
		outputFile << "Rate of " << r << "% " << setw(20) << "Current Value $" << endAmount << "\n\n";

		if (endAmount > 169000000000) {		//if endAmount is larger than 169B, output information.
			cout << "Good investment and rate!\n\n" << endl;
			
			outputFile << "Good investment and rate!\n\n" << endl;
		}
	}

	outputFile.close();

	return EXIT_SUCCESS;


}
