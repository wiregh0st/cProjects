/*

Mason Miller
LAB7_2_overloadMax.cpp

*/


#include <iostream>

using namespace std;

double max(double a);

double max(double b, double c);

double verify(double num1, double num2);



int main()
{
	double a = 0;
	double b = 0;
	double c = 0;

	double num1 = 0;
	double num2 = 0;


	num1 = max(a);
	num2 = max(b, c);

	verify(num1, num2);

}




double max(double a)		
{
	cout << "Please enter a number for a: ";
	cin >> a;
	cout << endl;
	return a;
	
}

double max(double b, double c) {
	cout << "Please enter a number for b: ";
	cin >> b;
	cout << endl;
	cout << "Please enter a number for c: ";
	cin >> c;
	cout << endl;
	if (b > c) {
		return b;
	}
	else if (c > b) {
		return c;
	}
}


double verify(double num1, double num2) {
	if (num1 > num2) {
		cout << "Max value is: " << num1;
		cout << endl;
		return num1;
	}
	else if (num2 > num1) {
		cout << "Max value is: " << num2;
		cout << endl;
		return num2;
	}
}







