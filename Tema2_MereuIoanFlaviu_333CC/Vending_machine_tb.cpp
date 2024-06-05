//Mereu Ioan Flaviu 333CC
#include <iostream>
#include "Vending_machine_tb.h"

using namespace std;

int main() {

	int status = 0;

	cout << "Test 1: " << endl;
	money_in(0, 1, 0); 	// 10
	money_in(0, 1, 0); 	// 10
	money_in(0, 1, 0); 	// 10
	money_in(0, 0, 0);	// Dispense drink and change.
	press_thanks();			// Press thank you button.

	cout << endl << "Test 2: " << endl;
	money_in(0, 1, 0); 	// 10
	money_in(0, 0, 1); 	// 25
	money_in(0, 0, 0);	// Dispense drink and change.
	press_thanks();			// Press thank you button.

	return status;
}