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
		cout << "**********************************" << endl;
		cout << "**         Головне меню         **" << endl;
		cout << "**********************************" << endl;
		cout << "**    Що ви бажаєте зробити?    **" << endl;
		cout << "**                              **" << endl;
		cout << "** 1. Створити файл бази даних. **" << endl;
		cout << "** 2. Вивести базу даних.       **" << endl;
		cout << "** 3. Вставити новий запис.     **" << endl;
		cout << "** 4. Зчитати запис за полем.   **" << endl;
		cout << "** 5. Зчитати запис за ключем.  **" << endl;
		cout << "** 6. Змінити запис за ключем.  **" << endl;
		cout << "** 7. Видалити запис за ключем. **" << endl;
		cout << "** 8. Файл групової роботи.     **" << endl;
		cout << "**                              **" << endl;
		cout << "** 0. Вихід.                    **" << endl;
		cout << "**********************************" << endl;
		cout << "** ";
		cin >> choice;
		 if(!cin) {
		     cin.clear();
		     cin.ignore(cin.rdbuf()->in_avail());
		 }
		switch (choice) {
		case 1: {
			createFile(0);
			break;
			}
		case 2: {
			printFile(0);
			break;
			}
		case 3: {
			insertRecord(out("** Введіть новий ключ.          **"));
			break;
			}
		case 4: {
			searchRecordByField(out("** Введіть номер поля,          **\n** яке Ви шукаєте.              **"), 0);
			break;
			}
		case 5: {
			searchRecordByKey(out("** Введіть ключ запису.         **"), 0);
			break;
			}
		case 6: {
			modificationRecord(out("** Введіть ключ запису.         **\n** Який Ви хочете модифікувати. **"), 0);
			break;
			}
		case 7: {
			deleteRecord(out("** Введіть ключ запису.         **\n** Який Ви хочете видалити.     **"), 0);
			break;
			}
		case 8: {
			groupFileMenu();
			break;
			}
		case 0:
			cout << "** Робота з програмою завершена.**" << endl;
			cout << "**********************************" << endl;
			return 0;
		default:
			break;
		}
	}
}

int out (string str){
	int key;
	cout << "**********************************" << endl;
	cout << str << endl;
	cout << "** ";
	cin >> key;
	cout << "**********************************" << endl;
	cin.clear();
	return key;
}

void groupFileMenu(){
	int choice;
	while(1) {
		cout << "**********************************" << endl;
		cout << "**  Меню файлу групової роботи. **" << endl;
		cout << "**********************************" << endl;
		cout << "**    Що ви бажаєте зробити?    **" << endl;
		cout << "**                              **" << endl;
		cout << "** 1. Створити файл ГР.         **" << endl;
		cout << "** 2. Вивести файл ГР.          **" << endl;
		cout << "** 3. Вставити новий запис.     **" << endl;
		cout << "** 4. Зчитати запис за ключем.  **" << endl;
		cout << "** 5. Змінити запис за ключем.  **" << endl;
		cout << "** 6. Видалити запис за ключем. **" << endl;
		cout << "** 7. Підтвердити зміни.        **" << endl;
		cout << "**                              **" << endl;
		cout << "** 0. Вихід в головне меню.     **" << endl;
		cout << "**********************************" << endl;
		cout << "** ";
		cin >> choice;
		 if(!cin) {
		     cin.clear();
		     cin.ignore(cin.rdbuf()->in_avail());
		 }
		switch (choice) {
		case 1: {
			createFile(1);
			break;
			}
		case 2: {
			printFile(1);
			break;
			}
		case 3: {
			insertRecordToGW(out("** Введіть новий ключ.          **"));
			break;
			}
		case 4: {
			searchRecordByKey(out("** Введіть ключ запису.         **"), 1);
			break;
			}
		case 5: {
			modificationRecord(out("** Введіть ключ запису.         **\n** Який Ви хочете модифікувати. **"), 1);
			break;
			}
		case 6: {
			deleteRecord(out("** Введіть ключ запису.         **\n** Який Ви хочете видалити.     **"), 1);
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
