#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "methodsMain.h"
#include "classTank.cpp"
using namespace std;

int main() {
	int choice;
	mark:
	cout << "What are you want to do?\n\n";
	cout << "1. Create file of database.\n";
	cout << "2. Print database.\n";
	cout << "3. Read record.\n";
	cout << "4. Search record for field.\n";
	cout << "5. Insert record.\n";
	cout << "6. Delete record.\n";
	cout << "7. Modification record.\n";
	cout << "0. Exit.\n";

	cin >> choice;

	switch (choice) {
	case 1: {
		createBase();
		goto mark;
	}
	case 2: {
		printBase();
		goto mark;
		}
	case 3: {

		break;
		}
	case 4: {

		break;
		}
	case 5: {

		break;
		}
	case 6: {

		break;
		}
	case 7: {

		break;
		}
	case 0: {

		break;
		}
	default: {

		}
	}

	return 0;
}
