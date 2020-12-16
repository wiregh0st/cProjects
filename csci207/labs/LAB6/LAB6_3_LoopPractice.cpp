/*

Mason Miller
LAB6_3_LoopPractice.cpp

*/



#include <iostream>

using namespace std;

int main()
{
    
	int evenInt = 2;
	int evenInt2 = 2;
	int oddInt = 1;
	int oddInt2 = 1;
	int add = 2;
	int evenSum = 4;
	int oddSum = 2;

	cout << "Even sums 2-500: \n\n\n";
	while ((evenInt >= 0 && evenInt <= 500)) {			//will stay in loop between 0 and 500.
		cout << evenInt << " + " << evenInt2 << " = " << evenSum << "\n";		//output values to show what will be added and the sum.
		evenInt = evenInt + add;		//increment evenInt by add
		evenInt2 = evenInt2 + add;		//increment evenInt2 by add
		evenSum = evenInt + evenInt2;
	}

	cout << endl;

	int i;

	cout << "Odd sums 1-499: \n\n\n";
	for (i = 0; i < 250; i++) {		//increment i by 1 AFTER each loop. i starts at 0 and goes to 249 (oddInt1/2 will = 499)
		cout << oddInt << " + " << oddInt2 << " = " << oddSum << "\n";		//output values to show what will be added and the sum.
		oddInt = oddInt + add;		//increment oddInt by add
		oddInt2 = oddInt2 + add;	//increment oddInt2 by add
		oddSum = oddInt + oddInt2;
	}

	return EXIT_SUCCESS;
}

