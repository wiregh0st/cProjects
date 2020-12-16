/* Mason Miller
	lab_Libs
	Program will follow a simple story and answer questions
	
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string name;
	string noun;
    int number;
	string bodyPart;
	string verb;
	
	cout << "Welcome to Madlib" << endl;
		cout << endl;
	cout << "Answer the following questions to help create a new story" << endl;
	cout << "What is your name: ";
		cin >> name;
		cout << endl;
	cout << "Give me a noun: ";
		cin >> noun;
		cout << endl;
	cout << "Give me a number: ";
		cin >> number;
		cout << endl;
	cout << "Give me a body part: ";
		cin >> bodyPart;
		cout << endl;
	cout << "Give me a verb: ";
		cin >> verb;
		cout << endl;
		
		cout << "This is your story: ";
		cout << "The famous explorer " << name;
		cout << " had nearly given up a life long quest to find the nearly extinct " << noun;
		cout << " , when one day, the " << noun;
		cout << " found the explorer. " << endl;
	cout << endl;	
		cout << "Sorrounded by " << number << " " << noun << "s" << " ";
		cout << "a tear came to " << name << "'s" << " "<< bodyPart << ".";
	cout << endl;
	
		cout << "After all this time, the quest was finally over. ";
		cout << "Then the " << noun << " promptly devoured " << name << ".";
	cout << endl;
	
		cout << "The moral of the story: Be careful what you " << verb << " for.";
		
	return EXIT_SUCCESS;
	
}
