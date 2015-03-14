#ifndef methodMain
#define methodMain

using namespace std;

void createBase() {
	char choice = '0';
	char choice2 = '0';
	mark:
	cout << string( 10, '\n' );
	cout << "---Create menu.\n\n";
	if (ifstream("/home/cossack/DatabaseSource/Base.txt")) {
		cout << "The database is already created.\n";
		cout << "What are you want to do?\n\n";
		cout << "1. Create new file of database.\n";
		cout << "0. Exit.\n";
		cin >> choice;
		switch (choice) {
			case '1': {
				mark2:
				cout << string( 100, '\n' );
				cout << "WARNING! Old database will be removed.\n";
				cout << "You want to continue? (Y/N)\n";
				cin >> choice2;
				switch (choice2) {
					case 'Y': {
						remove("/home/cossack/DatabaseSource/Base.txt");
						ofstream base("/home/cossack/DatabaseSource/Base.txt");
						base.close();
						cout << "The database was successfully created.\n";
						cout << "Press ENTER\n";
						cin.get();
						cin.get();
					}
					case 'N':
						break;
					default: {
						cout << "Press ENTER and try again.\n";
						cin.get();
						cin.get();
						goto mark2;
					}
				}
				break;
			}
			case '0':
				break;
			default: {
				cout << "Press ENTER and try again.\n";
				cin.get();
				cin.get();
				goto mark;
			}
		}
	} else {
		ofstream base("/home/cossack/DatabaseSource/Base.txt");
		base.close();
		if (ifstream("/home/cossack/DatabaseSource/Base.txt")) {
			cout << "The database was successfully created.\n";
			cout << "Press ENTER\n";
			cin.get();
			cin.get();
		} else {
			cout << "Unknown error, try again.\n";
			cout << "Press ENTER\n";
			cin.get();
			cin.get();
		}
	}
}

void printBase() {
	cout << string( 10, '\n' );
	if (!ifstream("/home/cossack/DatabaseSource/Base.txt"))
		cout << "Error, database is not create./n";
	else {
		string str;
		ifstream base("/home/cossack/DatabaseSource/Base.txt");
		while(!base.eof()){
			getline(base, str);
			cout << str << endl;
		}
		base.close();
	}
	cin.get();
	cin.get();
}

#endif
