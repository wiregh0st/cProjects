/*

Mason Miller
LAB6_1_fToC.cpp

PSEUDOCODE:
1. declare and initialize double fTemp.
2. declare and initialize double cTemp.
3. declare output file stream variable fToCdata and use file fToCdata.dat as output file.
4. declare input file stream variable fToCdataUpdated and use file fToCdataUpdated.dat as output file.
5. output Fahrenheit and Centigrade with proper spacing to heading of output file.
6. while not end of input file:
	6a. set all output in output file to fixed numbers (default 5 decimal places). set decimal places to 1.
	6b. take data from input file and write data to variable fTemp.
	6c. spacing before fahrenheit temp output. output fTemp variable to output file.
	6d. fahrenheit to celsius conversion formula.
	6e. spacing before celsius temp output. output cTemp variable to output file.
		6f. if end of input file:
		6g. close input file.
        6h. close output file.
7. validate i/o files successfully closed.

	
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double fTemp = 0.0;			//declare and initialize double fTemp.
	double cTemp = 0.0;			//declare and initialize double cTemp.

	ifstream fToCdata("fToCdata.dat");						//declare output file stream variable fToCdata and use file fToCdata.dat as output file.
	ofstream fToCdataUpdated("fToCdataUpdated.dat");		//declare input file stream variable fToCdataUpdated and use file fToCdataUpdated.dat as output file.

	fToCdataUpdated << "Fahrenheit" << string(8, ' ') << "Centigrade\n\n";		//output Fahrenheit and Centigrade with proper spacing to heading of output file.

	while (!fToCdata.eof())											//while not end of input file:
	{

		fToCdataUpdated << fixed << setprecision(1);				//set all output in output file to fixed numbers (default 5 decimal places). set decimal places to 1.
		fToCdata >> fTemp;											//take data from input file and write data to variable fTemp.
		fToCdataUpdated << string(6, ' ') << fTemp;					//spacing before fahrenheit temp output. output fTemp variable to output file.

		cTemp = ((5.0 / 9.0) * (fTemp - 32.0));						//fahrenheit to celsius conversion formula.

		fToCdataUpdated << string(15, ' ') << cTemp << endl;			//spacing before celsius temp output. output cTemp variable to output file.
		
			if (fToCdata.eof())				//if end of input file:
			{
				fToCdata.close();			//close input file.
				fToCdataUpdated.close();	//close output file.
			}
		
	}
	
	if ((fToCdata.is_open()) || (fToCdataUpdated.is_open()))			//validating i/o files successfully closed.
	{
		return EXIT_FAILURE;
	}
	else if(!fToCdata.is_open() || (fToCdataUpdated.is_open()))
	{
		return EXIT_SUCCESS;
	}
}

