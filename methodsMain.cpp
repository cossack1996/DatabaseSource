#include "methodsMain.h"
#include "classTank.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//////////////////////////////////
int createFile(int);
void printFile(int);
int insertRecord(int);
int insertRecordToGW(int);
//////////////////////////////////
int searchRecordByField(int, int);
int searchRecordByFieldNumber(int, int);
int searchRecordByKey(int, int);
int modificationRecord(int, int);
int deleteRecord(int, int);
//////////////////////////////////
void pressEnt ();
string wayFunction (int);
string nameNewFileUkr (int);
int searchBase(string);
Tank createObjFromString (string);
int readRecKey(int, int);
Tank createObj (int, int);
int deleteFileAndRename();
int getId (string);
//////////////////////////////////
void pressEnt () {
	cout << "** Натисніть ENTER              **" << endl;
	cout << "**********************************" << endl;
	cin.get();
	cin.get();
}

string wayFunction (int DBorGWorNDB){
	string fileName;
	if (DBorGWorNDB == 0) {
		fileName = "Base";
	} else  if (DBorGWorNDB == 1){
		fileName = "GroupWork";
	} else {
		fileName = "BaseNew";
	}
	string way = "/home/cossack/DatabaseSource/" + fileName + ".txt";
	return way;
}

string nameNewFileUkr (int DBorGWorNDB) {
	string fileNameUkr;
	if (DBorGWorNDB == 0) {
		fileNameUkr = "БД";
	} else  if (DBorGWorNDB == 1){
		fileNameUkr = "ГР";
	} else {
		fileNameUkr = "групової обробки (тимчасовий)";
	}
	return fileNameUkr;
}

///////////////////////////
//Створення нового файлу //
///////////////////////////

int createNewFile(const char* way){
	ofstream base(way);
	base.close();
	if (ifstream(way)) {
		return 1;
	} return 0;
}

//////////////////////////////
//Створення нової бази даних//
//////////////////////////////

int createFile(int DBorGWorNDB) {
	string fileNameUkr = nameNewFileUkr(DBorGWorNDB);
	string strWay = wayFunction(DBorGWorNDB);
	char choice = '0';
	char choice2 = '0';
	cout << "**********************************" << endl;
	cout << "**     Меню створення файлу     **" << endl;
	cout << "**********************************" << endl;
	if (ifstream(strWay.c_str())) {
		cout << "** Файл " << fileNameUkr << " вже створений.\t**" << endl;
		cout << "** Що робити?                   **" << endl;
		cout << "**                              **" << endl;
		cout << "** 1. Створити новий файл " << fileNameUkr << ".\t**" << endl;
		cout << "** 0. Вийти.                    **" << endl;
		cout << "**********************************" << endl;
		cout << "** ";
		cin >> choice;
		cin.clear();
		switch (choice) {
			case '1': {
				cout << "**********************************" << endl;
				cout << "**            УВАГА!            **" << endl;
				cout << "** Старий файл " << fileNameUkr << " буде видалений**" << endl;
				cout << "** Ви бажаєте продовжити? (Y/N) **" << endl;
				cout << "**********************************" << endl;
				cout << "** ";
				cin >> choice2;
				cin.clear();
				switch (choice2) {
					case 'Y': {
						remove(strWay.c_str());
						break;
					}
					case 'N':
						return 0;
					default: {
						cout << "**********************************" << endl;
						cout << "** Помилка вводу, спробуйте ще. **" << endl;
						pressEnt ();
						return 0;
					}
				}
				break;
			}
			case '0':
				return 0;
			default: {
				cout << "**********************************" << endl;
				cout << "** Помилка вводу, спробуйте ще. **" << endl;
				pressEnt ();
				return 0;
			}
		}
	}
	if (!createNewFile(strWay.c_str())) {
		cout << "**********************************" << endl;
		cout << "** Сталася невідома помилка.    **" << endl;
		cout << "** Спробуйте ще раз.            **" << endl;
		pressEnt ();
		return 0;

	} else {
		cout << "**********************************" << endl;
		cout << "** Файл " << fileNameUkr << " успішно створений.   **" << endl;
	}
	pressEnt ();
	return 1;
}

////////////////////////////
//Перевірка існування бази//
////////////////////////////

int searchBase(string strWay) {
	if (!ifstream(strWay.c_str())) {
			return 0;
	} return 1;
}

///////////////////////////////////////
//Створення об’єкту зі стрічки з бази//
///////////////////////////////////////

Tank createObjFromString (string objString){
	Tank *newTank = new Tank();
	if (objString != ""){
		int start = objString.find("\"") + 1;
		int end = objString.find("\"", start);
		int lenght = end - start;
		string str;
		newTank->setName(objString.substr(start, lenght));
		objString.erase(start - 1, lenght + 3);
		istringstream stringStream(objString);
		int id; stringStream >> id; newTank->setId(id);
		int crew; stringStream >> crew; newTank->setCrew(crew);
		int maxSpeed; stringStream >> maxSpeed; newTank->setMaxSpeed(maxSpeed);
		float caliber; stringStream >> caliber; newTank->setCaliber(caliber);
		int yearOfProduction; stringStream >> yearOfProduction; newTank->setYearOfProduction(yearOfProduction);
		int weigh; stringStream >> weigh; newTank->setWeigh(weigh);
		float armor; stringStream >> armor; newTank->setArmor(armor);
	}
	return *newTank;
}

///////////////////
//Друк бази даних//
///////////////////

void printFile(int DBorGWorNDB) {
	string strWay = wayFunction(DBorGWorNDB);
	if (searchBase(strWay.c_str())) {
		string str;
		ifstream base(strWay.c_str());
		while(!base.eof()){
			getline(base, str);
			createObjFromString(str).print();
		}
		base.close();
	}
	pressEnt ();
}

///////////////////////////////////
//Повернення номер поля за ключем//
///////////////////////////////////

int readRecKey(int key, int DBorGWorNDB) {
	int currentKey = 0;
	int i = 0;
	string str;
	ifstream base(wayFunction(DBorGWorNDB).c_str());
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
//Створення об’єкта з даних користувача   //
//в функцію передаємо ключ                //
////////////////////////////////////////////

Tank createObj (int key, int DBorGWorNDB) {
	Tank *newTank = new Tank;
	if(DBorGWorNDB && searchRecordByKey(key, 1)){
		newTank->setId(key);
		cout << "** Ви бажаєте видалити запис з  **" << endl;
		cout <<	"** таким ID? (Y/N)              **" << endl;
		cout << "**********************************" << endl;
		char choice;
		cin >> choice;
		cin.clear();
		switch (choice) {
			case 'Y': {
				newTank->deleteRecord = true;
				return *newTank;
			}
			case 'N':
				break;
			default: {
				cout << "** Помилка вводу.               **" << endl;
				cout << "**********************************" << endl;
				pressEnt ();
			}
		}
	}
	newTank->setId(key);
	cout << "** Введіть назву танка.         **" << endl << "** ";
	string name; cin >> name; cin.clear(); newTank->setName(name);
	cout << "** Введіть чисельність екіпажу. **" << endl << "** ";
	int crew; cin >> crew; cin.clear(); newTank->setCrew(crew);
	cout << "** Введіть максимальну швидкість**" << endl << "** ";
	int maxSpeed; cin >> maxSpeed; cin.clear(); newTank->setMaxSpeed(maxSpeed);
	cout << "** Введіть калібр гармати.      **" << endl << "** ";
	float caliber; cin >> caliber; cin.clear(); newTank->setCaliber(caliber);
	cout << "** Введіть рік виробництва.     **" << endl << "** ";
	int yearOfProduction; cin >> yearOfProduction; cin.clear(); newTank->setYearOfProduction(yearOfProduction);
	cout << "** Введіть вагу танка.          **" << endl << "** ";
	int weigh; cin >> weigh; cin.clear(); newTank->setWeigh(weigh);
	cout << "** Введіть товщину броні танка. **" << endl << "** ";
	float armor; cin >> armor; cin.clear(); newTank->setArmor(armor);
	cout << "**********************************" << endl;
	return *newTank;
}

/////////////////////////////
//Видалення старої бази, та//
//перейменування нової     //
/////////////////////////////

int deleteFileAndRename() {
	if(remove("/home/cossack/DatabaseSource/Base.txt")){
		remove("/home/cossack/DatabaseSource/BaseNew.txt");
		cout << "**********************************" << endl;
		cout << "** Сталася невідома помилка.    **" << endl;
		cout <<	"** Спробуйте ще раз.            **" << endl;
		cout << "**********************************" << endl;
		pressEnt ();
		return 0;
	} else {
		if(rename ("/home/cossack/DatabaseSource/BaseNew.txt", "/home/cossack/DatabaseSource/Base.txt")) {
			cout << "**********************************" << endl;
			cout << "** Сталася невідома помилка.    **" << endl;
			cout <<	"** Спробуйте ще раз.            **" << endl;
			cout << "**********************************" << endl;
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
	if (searchBase("/home/cossack/DatabaseSource/Base.txt")) {
		if (readRecKey(key, 0)) {
			cout << "**********************************" << endl;
			cout << "** Запис з таким ключем вже є.  **" << endl;
			cout <<	"** Спробуйте ще раз.            **" << endl;
			cout << "**********************************" << endl;
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
					Tank newTank = createObj(key, 0);
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

int insertRecordToGW(int key){
	ofstream groupWork("/home/cossack/DatabaseSource/GroupWork.txt", ios_base::app);
	Tank newTank = createObj(key, 1);
	string newStr = newTank.getAllData();
	groupWork << newStr << endl;
	groupWork.close();
	return 1;
}

//////////////////////////////////
//пошук запису за номером рядка //
//////////////////////////////////

int searchRecordByFieldNumber(int numberOfField, int DBorGWorNDB) {
	int i = 0;
	if (numberOfField < 0) {
		if (DBorGWorNDB != 1){
			cout << "**********************************" << endl;
			cout << "** Ви ввели неправильне поле.   **" << endl;
			cout <<	"** Спробуйте ще раз.            **" << endl;
			cout << "**********************************" << endl;
			pressEnt ();
		}
		return 0;
	} else if (searchBase(wayFunction(DBorGWorNDB))) {
		ifstream base(wayFunction(DBorGWorNDB).c_str());
		while(!base.eof()){
			string str;
			i++;
			getline(base, str);
			if((numberOfField == i)&&(str != "")) {
				if (DBorGWorNDB != 1){
					createObjFromString(str).print();
					pressEnt ();
				}
				return 1;
			}
		}
		cout << "**********************************" << endl;
		cout << "** Такого поля немає.           **" << endl;
		cout <<	"** Спробуйте ще раз.            **" << endl;
		cout << "**********************************" << endl;
		pressEnt ();
	} return 0;
}

////////////////////////
//Пошук поля за ключем//
////////////////////////

int searchRecordByKey(int key, int DBorGWorNDB) {
	int num = readRecKey(key, DBorGWorNDB);
	if (!num) {
		if (DBorGWorNDB != 1){
			cout << "**********************************" << endl;
			cout << "** Такого ключа немає.          **" << endl;
			cout <<	"** Спробуйте ще раз.            **" << endl;
			cout << "**********************************" << endl;
			pressEnt ();
		}
		return 0;
	} else {
		return searchRecordByFieldNumber(num, DBorGWorNDB);
	}
}

////////////////////
//Видалення запису//
////////////////////

int deleteRecord(int key, int DBorGWorNDB) {
	int num = readRecKey(key, DBorGWorNDB);
	int i = 0;
	if (!num) {
		cout << "**********************************" << endl;
		cout << "** Такого ключа немає.          **" << endl;
		cout <<	"** Спробуйте ще раз.            **" << endl;
		cout << "**********************************" << endl;
		pressEnt ();
		return 0;
	} else {
		ifstream base(wayFunction(DBorGWorNDB).c_str());
		ofstream baseNew(wayFunction(DBorGWorNDB).c_str());
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

//////////////////////
//Модифікація запису//
//////////////////////

int modificationRecord(int key,int DBorGWorNDB) {
	if(deleteRecord(key, DBorGWorNDB)){
		if(DBorGWorNDB)
			return insertRecord(key);
		else
			return insertRecordToGW(key);
	}
	return 0;
}

////////////////////////////////
//Пошук запису за назвою поля //
////////////////////////////////

int searchRecordByField(int numberOfField, int DBorGWorNDB) {
	return 0;
}

