/*

Mason Miller
PGM7.1missileLauncher.cpp

*/


#include <iostream>
#include <cmath>

using namespace std;

double getTargetDistance(double targetDistance);

double getLauncherAngle(double angle);

double getMissileVelocity(double velocity);				//declaration of functions

double calcWinningRange(double targetDistance, double projectileDistance, double &win);

double calcMissileDistance(double velocity, double angle, const double pi, double projectileDistance);	//calculate user projectile distance.

void printSummary(double projectileDistance, double targetDistance);		//display to user how far from target their projectile was.



int main()
{
	const double pi = 3.14159265358979323846;
	double targetDistance = 0;
	double angle = 0;					//initilization of variables
	double velocity = 0;
	double range = 0;
	double projectileDistance = 0;
	double win = 0;

	int i = 5;	//counter

	targetDistance = getTargetDistance(targetDistance);


	while (i > 0) {

		angle = getLauncherAngle(angle);			//get user angle.
		velocity = getMissileVelocity(velocity);		//get user velocity.
		projectileDistance = calcMissileDistance(velocity, angle, pi, projectileDistance); //calculate projectile distance

		calcWinningRange(targetDistance, projectileDistance, win);		//calculate winning range and set win to 1 if user wins.

		if (win == 0)
		{
			printSummary(projectileDistance, targetDistance);			//if no win, display range from target and allow user to try again.
		}

		else if (win == 1) {

			return EXIT_SUCCESS;			//if win, exit program.
		}
		i--;		//decrement i.

	}

	cout << "Try again next time!";			//if user has tried 5 times and does not get close enough, program closes with a message for the user to try again.
	
	return EXIT_SUCCESS;
}














		double getTargetDistance(double targetDistance) {		//gets user input distance to target.

			cout << "Please enter a target distance: ";
			cin >> targetDistance;
			cout << endl;
			return targetDistance;
		}



		double getLauncherAngle(double angle) {		//gets user input projectile angle.	

			cout << "Please enter a projectile angle (between 0 and 90): ";

			cin >> angle;

			

			while ((angle < 0) || (angle > 90)) {

				cout << "Angle value outside defined parameters. Please enter a new angle value (between 0 and 90): ";
				cin >> angle;
			}

			cout << endl;

			return angle;
		}



		double getMissileVelocity(double velocity) {		 //gets user input projectile velocity.

			cout << "Please enter a projectile velocity (in feet/second): ";

			cin >> velocity;

			

			while (velocity < 0) {

				cout << "Velocity must be between 0 and infinity. Please enter a new value for velocity: ";
				cin >> velocity;
			}

			cout << endl;

			return velocity;
		}



		double calcWinningRange(double targetDistance, double projectileDistance, double &win) {


			double guessRange = targetDistance / 1000;				//guessRange within 0.1% of projectileDistance.
			double upperRange = targetDistance + guessRange;
			double lowerRange = targetDistance - guessRange;

			if ((projectileDistance > lowerRange) && (projectileDistance < upperRange)) {		//if projectile distance within range, tell user you win. will exit program via main return exit_success.
				cout << "You win!";
				win = 1;

				
			}

			return win;

		}



		double calcMissileDistance(double velocity, double angle, const double pi, double projectileDistance) {



			velocity = velocity * velocity;					//redefining angle and velocity to make projectileDistance calculation easier.

			angle = (2 * angle);

			projectileDistance = (velocity * ((sin(angle * pi / 180))) / 32.2); //formula for calculating projectile distance. sin returns radian value so degree angle must be converted by pi/180. final value is in feet.

			return projectileDistance;
		}



		void printSummary(double projectileDistance, double targetDistance) {

			double range = 0;

			if (projectileDistance > targetDistance) {			
				range = projectileDistance - targetDistance;
																		//math to subtract correct value to display correct range from target to user.
			}
			else if (projectileDistance < targetDistance) {
				range = targetDistance - projectileDistance;
			}



			cout << "You were " << range << " from the target." << endl;



			return;
		}
