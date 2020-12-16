/*

Mason Miller
Lab5_1_fAndH
This program will input 3 values.
Then it will find A according to the following equation: a = ((5x + 3y)/4z)
When X = 3.156, Y = 4, and Z = 2.544 , the answer will be A = 2.73.

*/

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ios>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{

	int yzaSpace = 11;
	int xSpace = 5;

	double x = 0;
	double y = 0;
	double z = 0;
	double a = 0;

	double xHold = 0;
	double yHold = 0;
	double zHold = 0;
	
	cout << "Please enter a value for x: " << endl;
	cin >> x;

	xHold = 5 * x; //placeholder variable xHold stores value of x times 5.

	cout << "Please enter a value for y: " << endl;
	cin >> y;

	yHold = 3 * y; //placeholder variable yHold stores value of y times 3.

	cout << "Please enter a value for z: " << endl;
	cin >> z;

	zHold = 4 * z; //placeholder variable zHold stores value of z times 4.

		a = ((xHold + yHold) / zHold); //formula for variable a.


	cout << right << setw(20) << "Mason" << " Miller" << endl;
	cout << right << setw(27) << "2/7/2019" << endl;
	cout << "\n";

	cout << fixed;						//will display all variables listed below in FIXED DECIMAL FORMAT. default is 6 decimal places*********

	cout << right << setw(xSpace) << "x";
	cout << right << setw(yzaSpace) << "y";
	cout << right << setw(yzaSpace) << "z";	//outputs x y z a.
	cout << right << setw(yzaSpace) << "a";
	cout << "\n\n";
	
	cout << right << setw(xSpace) << setprecision(1) << x;
	cout << right << setprecision(1) << setw(yzaSpace) << y;
	cout << right << setprecision(1) << setw(yzaSpace) << z;		//outputs x y z a variables to 1 decimal place.
	cout << right << setprecision(1) << setw(yzaSpace) << a;
	cout << "\n\n";

	cout << right << setw(xSpace) << setprecision(2) << x;
	cout << right << setprecision(2) << setw(yzaSpace) << y;
	cout << right << setprecision(2) << setw(yzaSpace) << z;		//outputs x y z a variables to 2 decimal places.
	cout << right << setprecision(2) << setw(yzaSpace) << a;
	cout << "\n\n";

	cout << right << setw(xSpace) << setprecision(3) << x;
	cout << right << setprecision(3) << setw(yzaSpace) << y;
	cout << right << setprecision(3) << setw(yzaSpace) << z;		//outputs x y z a variables to 3 decimal places.
	cout << right << setprecision(3) << setw(yzaSpace) << a;
	cout << "\n\n";
}

