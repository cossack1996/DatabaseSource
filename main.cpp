#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "methodsMain.h"
using namespace std;

int out (string);
void groupFileMenu();

int main() {
	setlocale(LC_ALL, "Ukrainian_Ukraine.1251");
	int choice;
	while(1) {
		cout << "--------Головне меню--------\n";
		cout << "   Що ви бажаєте зробити?\n\n";
		cout << "1. Створити файл бази даних.\n";
		cout << "2. Вивести базу даних на екран.\n";
		cout << "3. Вставити новий запис.\n";
		cout << "4. Зчитати запис за полем.\n";
		cout << "5. Зчитати запис за ключем.\n";
		cout << "6. Змінити запис за ключем.\n";
		cout << "7. Видалити запис за ключем.\n";
		cout << "8. Робота з файлом груповоъ обробкию.\n";

		cout << "0. Вихід.\n\n";

		cin >> choice;
		switch (choice) {
		case 1: {
			createBase(0);
			break;
			}
		case 2: {
			printFile(0);
			break;
			}
		case 3: {
			insertRecord(out("Новий ключ:"));
			break;
			}
		case 4: {
			searchRecordByField(out("Введіть номер поля, яке Ви шукаєте:"), 0);
			break;
			}
		case 5: {
			searchRecordByKey(out("Введіть ключ:"), 0);
			break;
			}
		case 6: {
			modificationRecord(out("Введіть ключ запису, який Ви хочете модифікувати:"), 0);
			break;
			}
		case 7: {
			deleteRecord(out("Введіть ключ запису, який Ви хочете видалити:"), 0);
			break;
			}
		case 8: {
			groupFileMenu();
			break;
			}
		case 0:
			return 0;
		default:
			break;
		}
	}
}

int out (string str){
	int key;
	cout << string( 10, '\n' );
	cout << str << endl;
	cin >> key;
	cin.clear();
	return key;
}

void groupFileMenu(){
	int choice;
	while(1) {
		cout << "--Меню файлу групової обробки--\n";
		cout << "    Що ви бажаєте зробити?\n\n";
		cout << "1. Створити файл групової обробки.\n";
		cout << "2. Друк файлу групової обробки.\n";
		cout << "3. Вставити новий запис.\n";
		cout << "4. Пошук запису за ключем.\n";
		cout << "5. Видалення запису за ключем.\n";
		cout << "6. Модифікація запису за ключем.\n";
		cout << "7. Підтвердити зміни.\n";

		cout << "0. Повернутися в головне меню.\n";

		cin >> choice;
		switch (choice) {
		case 1: {
			createBase(1);
			break;
			}
		case 2: {
			printFile(1);
			break;
			}
		case 3: {
			insertRecordToGW(out("Новий ключ:"));
			break;
			}
		case 4: {
			searchRecordByKey(out("Введіть ключ:"), 1);
			break;
			}
		case 5: {
			deleteRecord(out("Введіть ключ запису, який Ви хочете видалити:"), 1);
			break;
			}
		case 6: {
			modificationRecord(out("Введіть ключ запису, який Ви хочете модифікувати:"), 1);
			break;
			}
		case 7: {

			break;
			}
		case 0:
			return;
		default:
			break;
		}
	}
}
