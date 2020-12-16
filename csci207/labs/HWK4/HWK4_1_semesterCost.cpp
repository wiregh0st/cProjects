/*

Mason Miller
HWK4_1_semesterCost.cpp
Program will ask user if they are in-state or out-of-state, need a room, and if they need a meal plan. Based on this data,
the program will calculate the total cost for the user to attend Winthrop.
Pseudocode:
1. Prompt the user to enter if they are in-state or out-of-state.
a. Validate input
2. Assign in-state or out-of-state tuition.
3. Prompt the user to enter if they want a room.
a. Validate Input
4. Assign the room fee.
5. Prompt the user to enter if they want a meal plan.
a. Validate input
6. Assign the meal-plan charge.
7. Calculate the total fees.
8. Print the tuition, room fee, meal plan charge, registration fee, and the total fee.

*/


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{

	char stateStatus;
	char roomReq;
	char mealReq;

	double tuitionCost;
	double roomCost;
	double mealCost;
	double fees;
	double totalExpense;

	stateStatus = 'm';
	roomReq = 'm';
	tuitionCost = 00;
	roomCost = 00;
	mealCost = 00;
	fees = 25.00;

	cout << "***Before beginning, please ensure CAPS-LOCK is turned OFF.***\n\n";

	cout << "Will you be an in-state student or an out-of-state student? Type i for IN-STATE, Type o for OUT-OF-STATE: ";

	cin >> stateStatus;

	while (stateStatus != 'i' && stateStatus != 'o') //Check if stateStatus is a valid character.
	{
		cout << "\nYou have entered an invalid character for your tuition status. CAPS-LOCK MIGHT BE ON! Type i for IN-STATE, Type o for OUT-OF-STATE: ";
		cin >> stateStatus;
	}
	if (stateStatus == ('i'))
	{
		tuitionCost = 7615.00;
	}
	else if (stateStatus == ('o'))
	{
		tuitionCost = 14743.00;
	}
	

	cout << "\nWill you require a room? Type y for YES, Type n for NO: ";
	cin >> roomReq;
		
	while (roomReq != 'y' && roomReq != 'n') //Check if roomReq is a valid character.
	{
		cout << "\nYou have entered an invalid character for your room requirements. CAPS-LOCK MIGHT BE ON! Please Type y for YES, Type n for NO: ";
		cin >> roomReq;
	}
	if (roomReq == 'y')
	{
		roomCost = 2029.00;
	}
	else if (roomReq == 'n')
	{
		roomCost == 0;
	}
	

	cout << "\nWill you require a meal plan? Type y for YES, Type n for NO: ";
	cin >> mealReq;

	while (mealReq != 'y' && mealReq != 'n') //Check if mealReq is a valid character.
	{
		cout << "\nYou have entered an invalid character for your meal requirements. CAPS-LOCK MIGHT BE ON! Please Type y for YES, Type n for NO: ";
		cin >> mealReq;
	}
	if (mealReq == 'y')
	{
		mealCost = 1766.00;
	}
	else if (mealReq == 'n')
	{
		mealCost = 0;
	}

	totalExpense = tuitionCost + roomCost + mealCost + fees;
	cout << "\nThe total cost to attend Winthrop will be:\n\n" << "Tuition: " << tuitionCost << "\t" << "Room: " << roomCost << "\t" << "Meal plan: " << mealCost << "\t" << "Total cost: " << totalExpense << endl;


}





