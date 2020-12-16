/*

Mason Miller
HWK6_2_nimGame

*/


#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

int main() {

	srand(time(NULL));			//seed random number

	string pName = " ";

	int pChoice = 0;
	int aiChoice = 0;
	int heap = 23;

	cout << "Please enter player name: ";		//request player name
	cin >> pName;
	cout << endl;


	while (heap > 0) {

		cout << pName << " remove items from the heap (between 1 and 3): ";		//have player choose how many to take from heap
		cin >> pChoice;
		cout << endl;

		while ((pChoice < 1) || (pChoice > 3)) {
			cout << "Please choose a value between 1 and 3: ";				//verify player choice between 1 and 3.
			cin >> pChoice;
			cout << endl;
		}

		while (pChoice > heap) {
			cout << "Your choice is greater than the objects in the heap! Please choose a new value: ";		//verify player choice not greater than heap
			cin >> pChoice;
			cout << endl;
		}

		if (heap - pChoice == 0) {
			cout << "Heap empty! Player wins!" << endl;			//check if player has won the game
		}
		heap = heap - pChoice;					//subtract player choice from heap

		aiChoice = rand() % 3 + 1;				//ai choice through random generated number (1-3).

		while (aiChoice > heap) {				//check ai choice to make sure it is not greater than heap. if greater than heap, choose new number.
			aiChoice = rand() % 3 + 1;
		}

		cout << "Computer chooses: " << aiChoice << endl;			//display computer choice

		if (heap - aiChoice == 0) {
			cout << "Heap empty! Computer wins!" << endl;			//check if computer has won the game.
		}

		heap = heap - aiChoice;
	}

	return EXIT_SUCCESS;
}