/*


Mason Miller
LAB6_4_whilePractice.cpp

*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	int count = 1;			//
	int grade = 0;			//		VARIABLES FOR FIRST WHILE
	int gradeTotal = 0;		//
	double gradeAvg = 0;	//
	
	
	char myChar = 'z';		//
	int letters = 0;		//			VARIABLES FOR SECOND WHILE


	while (count <= 15) {						//read grades until count = 16. count starts at 1, will complete 15 times. 
		cout << "Please enter a grade: ";
		cin >> grade;
		
		gradeTotal = gradeTotal + grade;		//assign the gradeTotal. add grade to gradeTotal at the end of every loop.
		
		count++;								//increment count so no infinite loop.
		
	}


	gradeAvg = gradeTotal / (count - 1);		//gradeAvg algorithm.
	
	cout << "\nThe average grade is: " << gradeAvg;

	
	while (myChar != 'q') {					//loop until myChar == q
		cout << "\nPlease enter a character: ";
		cin >> myChar;

		if ((myChar >= 'a') || (myChar <= 'z')){  //if the myChar is a letter of the alphabet, increment the integer letters by 1.
			if (myChar == 'q') {				
				letters--;				//if myChar == q, decrement letters by 1.
			}
			letters++;

			
		}
	}
	
	cout << "\nThe number of letters read is: " << letters;
}


