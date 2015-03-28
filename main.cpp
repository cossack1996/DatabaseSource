#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "methodsMain.h"
using namespace std;

int out (string str){
	int key;
	cout << string( 10, '\n' );
	cout << str << endl;
	cin >> key;
	cin.clear();
	return key;
}

int main() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	int choice;
	while(1) {

		cout << "Що ви бажаєте зробити?\n\n";
		cout << "1. Створити файл бази даних.\n";
		cout << "2. Вивести базу даних на екран.\n";
		cout << "3. Вставити новий запис.\n";
		cout << "4. Зчитати запис за полем.\n";
		cout << "5. Зчитати запис за ключем.\n";
		cout << "6. Змінити запис за ключем.\n";
		cout << "7. Видалити запис за ключем.\n";
		cout << "0. Вихід.\n\n";

		cin >> choice;
		switch (choice) {
		case 1: {
			createBase();
			break;
			}
		case 2: {
			printBase();
			break;
			}
		case 3: {
			insertRecord(out("Новий ключ:"));
			break;
			}
		case 4: {
			searchRecordByField(out("Введіть номер поля, яке Ви шукаєте:"));
			break;
			}
		case 5: {
			searchRecordByKey(out("Введіть ключ:"));
			break;
			}
		case 6: {
			modificationRecord(out("Введіть ключ запису, який Ви хочете видалити:"));
			break;
			}
		case 7: {
			deleteRecord(out("Введіть ключ запису, який Ви хочете модифікувати:"));
			break;
			}
		case 0:
			return 0;
		default:
			break;
		}
	}
}
