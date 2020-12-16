/*

Mason Miller
LAB7_4_Statistics.cpp

*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>


using namespace std;

double mean(double score1, double score2, double score3, double score4, double meanValue);

int verifyUserInput(int &userIn);

double standDevFunct(double score1, double score2, double score3, double score4, double meanValue);

double statFunct(double score1, double score2, double score3, double score4, double &meanValue, double &standDev);

int main()
{

	double score = 0;
	double meanValue = 0;
	int userIn = 0;
	double score1 = 0;
	double score2 = 0;
	double score3 = 0;
	double score4 = 0;
	double standDev = 0;

	ifstream inFile("testFile.txt");
	
	if (!inFile) {
		cout << "File failed to open. Exiting Program...";
		return EXIT_FAILURE;
	}

	inFile >> score1 >> score2 >> score3 >> score4;			//store data from input file into scores 1-4.

	inFile.close();		//close input file.

	statFunct(score1, score2,  score3, score4, meanValue, standDev);		//call stat function.

	cout << "mean: " << meanValue << endl;
	cout << "standard deviation: " << standDev << endl;

	

	while (userIn != 1) {

		cout << "Type 0 to continue running. Type 1 to exit: ";			//driver program. will continue until userIn = 1.
		cin >> userIn;
		
		verifyUserInput(userIn);
		
		statFunct(score1, score2, score3, score4, meanValue, standDev);

		cout << "mean: " << meanValue << endl;
		cout << "standard deviation: " << standDev << endl;
	}

}


double mean(double score1, double score2, double score3, double score4, double meanValue) {	

	int totalScores = 4;
	double scoreSum = 0;

	scoreSum = score1 + score2 + score3 + score4;			//add all scores for score sum.

	 meanValue = scoreSum / totalScores;			//mean is same as average. divide scoresum by totalscores. totalscores is always 4.
	 return meanValue;
}


double standDevFunct(double score1, double score2, double score3, double score4, double meanValue) {

	double calcScore1 = 0;
	double calcScore2 = 0;
	double calcScore3 = 0;
	double calcScore4 = 0;
	double sumMeanSquared = 0;
	double standDev = 0;

	calcScore1 = pow(fabs(score1 - meanValue), 2);
	calcScore2 = pow(fabs(score2 - meanValue), 2);					//stores numerator of standard deviation function for each value.
	calcScore3 = pow(fabs(score3 - meanValue), 2);
	calcScore4 = pow(fabs(score4 - meanValue), 2);

	sumMeanSquared = calcScore1 + calcScore2 + calcScore3 + calcScore4;			//sums all of the calculated numerator values for standard deviation function.

	standDev = sqrt(sumMeanSquared / 4);			//takes the square root of sum of numerators divided by total numbers (4).
	
	return standDev;

}


int verifyUserInput(int &userIn) {

	if (cin.fail()) {

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You entered an incorrect value. Please enter a number: ";		//input validation.
			cin >> userIn;
			cout << endl;

		}
	}

	return userIn;
}



double statFunct(double score1, double score2, double score3, double score4, double &meanValue, double &standDev) {

	
	meanValue = mean(score1,  score2,  score3, score4, meanValue);		//set meanValue = mean function.

	standDev = standDevFunct(score1, score2, score3, score4, meanValue); //set standDev = standDevFunct.

	return 0;
}

