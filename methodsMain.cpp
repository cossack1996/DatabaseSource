#include "methodsMain.h"
#include "classTank.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/////////////////////////////////

void pressEnt () {
	cout << "Press ENTER\n";
	cin.get();
	cin.get();
}

///////////////////////////
//Створення нового файлу //
///////////////////////////

int createNewFile(string name){
	string way = "/home/cossack/DatabaseSource/" + name + ".txt";
	const char *charWay = way.c_str();
	ofstream base(charWay);
	base.close();
	if (ifstream(charWay)) {
		return 1;
	} return 0;
}

//////////////////////////////
//Створення нової бази даних//
//////////////////////////////

int createBase() {
	char choice = '0';
	char choice2 = '0';
	cout << string( 10, '\n' );
	cout << "---Меню створення.\n\n";
	if (ifstream("/home/cossack/DatabaseSource/Base.txt")) {
		cout << "База даних вже створена.\n";
		cout << "Що робити?\n\n";
		cout << "1. Створити нову базу даних.\n";
		cout << "0. Вийти.\n";
		cin >> choice;
		cin.clear();
		switch (choice) {
			case '1': {
				cout << string( 100, '\n' );
				cout << "УВАГА! Стара база даних буде видалена.\n";
				cout << "Ви бажаєте продовжити? (Y/N)\n";
				cin >> choice2;
				cin.clear();
				switch (choice2) {
					case 'Y': {
						remove("/home/cossack/DatabaseSource/Base.txt");
						break;
					}
					case 'N':
						return 0;
					default: {
						cout << "Ви ввели щось не те, спробуйте ще раз." << endl;
						pressEnt ();
						return 0;
					}
				}
				break;
			}
			case '0':
				return 0;
			default: {
				cout << "Ви ввели щось не те, спробуйте ще раз." << endl;
				pressEnt ();
				return 0;
			}
		}
	}
	if (createNewFile("Base")) {
		cout << "Сталася невідома помилка, спробуйте ще раз." << endl;
		pressEnt ();
		return 0;
	} else cout << "База успішно створена." << endl;
	pressEnt ();
	return 1;
}

////////////////////////////
//Перевірка існування бази//
////////////////////////////

int searchBase() {
	if (!ifstream("/home/cossack/DatabaseSource/Base.txt")) {
			cout << "Помилка, база даних ще не створена./n";
			return 0;
	} return 1;
}
///////////////////
//Друк бази даних//
///////////////////

void printBase() {
	cout << string( 10, '\n' );
	if (searchBase()) {
		string str;
		ifstream base("/home/cossack/DatabaseSource/Base.txt");
		while(!base.eof()){
			getline(base, str);
			cout << str << endl;
		}
		base.close();
	}
	pressEnt ();
}

///////////////////////////////////////
//Створення об’єкту зі стрічки з бази//
///////////////////////////////////////

Tank createObjFromString (string objString){
	Tank newTank;
	if (objString != ""){
		int start = objString.find("\"") + 1;
		int end = objString.find("\"", start);
		int lenght = end - start;
		string str;
		newTank.setName(objString.substr(start, lenght));
		objString.erase(start - 1, lenght + 3);
		istringstream stringStream(objString);
		int id; stringStream >> id; newTank.setId(id);
		int crew; stringStream >> crew; newTank.setCrew(crew);
		int maxSpeed; stringStream >> maxSpeed; newTank.setMaxSpeed(maxSpeed);
		float caliber; stringStream >> caliber; newTank.setCaliber(caliber);
		int yearOfProduction; stringStream >> yearOfProduction; newTank.setYearOfProduction(yearOfProduction);
		int weigh; stringStream >> weigh; newTank.setWeigh(weigh);
		float armor; stringStream >> armor; newTank.setArmor(armor);
	}
	return newTank;
}

///////////////////////////////////
//Повернення номер поля за ключем//
///////////////////////////////////

int readRecKey(int key) {
	int currentKey = 0;
	int i = 0;
	string str;
	ifstream base("/home/cossack/DatabaseSource/Base.txt");
	while(!base.eof()){
		i++;
		getline(base, str);
		if(str == "") return 0;
		Tank currentTank = createObjFromString(str);
		currentKey = currentTank.getId();
		if (currentKey == key) {
			return i;
		}
	}
	base.close();
	return 0;
}

////////////////////////////////////////////
//Створення об’єкту з даних користувача   //
//в функцію передаємо ключ                //
////////////////////////////////////////////

Tank createObj (unsigned int key) {
	Tank newTank;
//	unsigned int key;
//	if (n == 1) {
//		unsigned int *p = &n;
//		p++;
//		key = *p;
//	} else {
//		cout << "Введіть значення ключа:" << endl;
//		cin >> key;
//	}
	newTank.setId(key);
	cout << "Введіть назву танка" << endl;
	string name; cin >> name; newTank.setName(name);
	cout << "Введіть чисельність екіпажу" << endl;
	int crew; cin >> crew; newTank.setCrew(crew);
	cout << "Введіть максимальну швидкість:" << endl;
	int maxSpeed; cin >> maxSpeed; newTank.setMaxSpeed(maxSpeed);
	cout << "Введіть калібр встановленої гармати:" << endl;
	float caliber; cin >> caliber; newTank.setCaliber(caliber);
	cout << "Введіть рік початку виробництва:" << endl;
	int yearOfProduction; cin >> yearOfProduction; newTank.setYearOfProduction(yearOfProduction);
	cout << "Введіть вагу танка:" << endl;
	int weigh; cin >> weigh; newTank.setWeigh(weigh);
	cout << "Введіть товщину броні танка:" << endl;
	float armor; cin >> armor; newTank.setArmor(armor);
	cin.clear();
	return newTank;
}

/////////////////////////////
//Видалення старої бази, та//
//перейменування нової     //
/////////////////////////////

int deleteFileAndRename() {
	if(remove("/home/cossack/DatabaseSource/Base.txt")){
		remove("/home/cossack/DatabaseSource/BaseNew.txt");
		cout << "Сталася невідома помилка(при видаленні файлу).\nСпробуйте ще раз." << endl;
		pressEnt ();
		return 0;
	} else {
		if(rename ("/home/cossack/DatabaseSource/BaseNew.txt", "/home/cossack/DatabaseSource/Base.txt")) {
			cout << "Сталася невідома помилка(при перейменуванні файлу).\nСпробуйте ще раз." << endl;
			pressEnt ();
			return 0;
		}
	}
	return 1;
}

////////////////////////////
//Отримання ключа з рядка //
////////////////////////////

int getId (string str) {
	int key;
	if (str != ""){
		istringstream stringStream(str);
		stringStream >> key;
	}
	return key;
}

///////////////////////////
//Вставка нового запису  //
//+перевірка чи вже існує//
///////////////////////////

int insertRecord(int key) {
	if (searchBase()) {
		if (readRecKey(key)) {
			cout << "Запис з таким ключем вже є.\n";
			cout << "Спробуйте ще раз.\n";
			pressEnt ();
			return 0;
		} else {
			string str;
			int preKey = 0;
			ifstream base("/home/cossack/DatabaseSource/Base.txt");
			ofstream baseNew("/home/cossack/DatabaseSource/BaseNew.txt");
			while(!base.eof()){
				getline(base, str);
				if(((str == "") && (preKey == 0)) || ((preKey < key) && (getId(str) > key))){
					Tank newTank = createObj(key);
					string newStr = newTank.getAllData();
					baseNew << newStr << endl;
				}
				baseNew << str << endl;
				preKey = getId(str);
			}
			base.close();
			baseNew.close();
			deleteFileAndRename();
			return 1;
		}
	} return 0;
}

//////////////////////////////////
//пошук запису за номером рядка //
//////////////////////////////////

int searchRecordByField(int numberOfField) {
	int i = 0;
	if (numberOfField < 0) {
		cout << "Ви ввели неправильне поле, спробуйте ще." << endl;
		pressEnt ();
		return 0;
	} else if (searchBase()) {
		ifstream base("/home/cossack/DatabaseSource/Base.txt");
		while(!base.eof()){
			string str;
			i++;
			getline(base, str);
			if((numberOfField == i)&&(str != "")) {
				cout << str << endl;
				pressEnt ();
				return 1;
			}
		}
		cout << "Такого поля немає, спробуйте ще раз." << endl;
		pressEnt ();
	} return 0;
}

////////////////////////
//Пошук поля за ключем//
////////////////////////

int searchRecordByKey(int key) {
	int num = readRecKey(key);
	if (!num) {
		cout << "Такого ключа немає, спробуйте ще раз." << endl;
		pressEnt ();
		return 0;
	} else {
		return searchRecordByField(num);
	}
}

////////////////////
//Видалення запису//
////////////////////

int deleteRecord(int key) {
	int num = readRecKey(key);
	int i = 0;
	if (!num) {
		cout << "Такого ключа немає, спробуйте ще раз." << endl;
		pressEnt ();
		return 0;
	} else {
		ifstream base("/home/cossack/DatabaseSource/Base.txt");
		ofstream baseNew("/home/cossack/DatabaseSource/BaseNew.txt");
		while(!base.eof()){
			string str;
			i++;
			getline(base, str);
			if(num != i) {
				baseNew << str << endl;
			}
		}
		base.close();
		baseNew.close();
		return deleteFileAndRename();
	}
}

int modificationRecord(int key) {
	int num = readRecKey(key);
	if(deleteRecord(key))
		return insertRecord(key);
	return 0;
}



