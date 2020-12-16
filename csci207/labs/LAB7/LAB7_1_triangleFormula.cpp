/*

Mason Miller
LAB7_1_triangleFormula.cpp

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

double area(double height, double radius);
double volume(double height, double radius);


int main()
{
    
	ifstream data("testData.txt");
	ofstream dataOut("dataOut.txt");

	double height = 0;
	double radius = 0;
	double areaCalc = 0;
	double volumeCalc = 0;


	if (!data) {
		cout << "File failed to open. Aborting...";
		return 0;
	}
	
		dataOut << "Base " << setw(10) << "Height " << setw(10) << "Area " << setw(10) << "Volume " << endl; //output headers to output file.
		cout << "Base " << setw(10) << "Height " << setw(10) << "Area " << setw(10) << "Volume " << endl; //output headers to display.
		
	while (!data.eof()) {		//read until end of file.
		data >> height >> radius;		//read in height and radius from testData input file.
		dataOut << fixed << setprecision(2); //output with 2 decimal places.
		dataOut << height << " " << setw(10) << radius << " " << setw(10) << area(height, radius) << " " << setw(10) << volume(height, radius) << endl; //ouput information from functions to file.

		//do same as dataOut but with cout.
		
		cout << fixed << setprecision(2); 
		cout << height << " " << setw(10) << radius << " " << setw(10) << area(height, radius) << " " << setw(10) << volume(height, radius) << endl;
		
	}

	return EXIT_SUCCESS;
}

double area(double height, double radius) {		//calculate area of right triangle.
	double areaCalc = 0.0;
	areaCalc = (.5 * (height * radius));
	return areaCalc;
}

double volume(double height, double radius) {		//calculate volume of cone.
	double volumeCalc = 0.0;
	volumeCalc = (((3.14 * (radius * radius) * height)) / 3);
	return volumeCalc;


}