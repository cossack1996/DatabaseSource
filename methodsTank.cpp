#include <iostream>
#include <string>
#include <sstream>
#include "classTank.h"
using namespace std;

Tank::Tank(){
	id = 0;
	name = "";
	crew = 0;
	maxSpeed = 0;
	caliber = 0.0;
	yearOfProduction = 0;
	weigh = 0;
	armor = 0.0;
	deleteRecord = false;
}
void Tank::printError() {
	cout << "**            ERROR             **" << endl;
	cout << "**********************************" << endl;
}
bool Tank::setId (int newId){
	if (newId < 1) {
		printError();
		return 0;
	} else {
		id = newId;
		return 1;
	}
}

bool Tank::setName (string newName){
	if (newName == "")  {
		printError();
		return 0;
	} else {
		name = newName;
		return 1;
	}
}

bool Tank::setCrew (int newCrew){
	if (newCrew < 1) {
		printError();
		return 0;
	} else {
		crew = newCrew;
		return 1;
	}
}

bool Tank::setMaxSpeed (int newMaxSpeed){
	if ((newMaxSpeed <= 0) && (newMaxSpeed > 150)) {
		printError();
		return 0;
	} else {
		maxSpeed = newMaxSpeed;
		return 1;
	}
}

bool Tank::setCaliber (float newCaliber){
	if ((newCaliber <= 0) && (newCaliber > 300)) {
		printError();
		return 0;
	} else {
		caliber = newCaliber;
		return 1;
	}
}

bool Tank::setYearOfProduction (int newYearOfProduction){
	if ((newYearOfProduction < 1900) && (newYearOfProduction > 2015)) {
		printError();
		return 0;
	} else {
		yearOfProduction = newYearOfProduction;
		return 1;
	}
}

bool Tank::setWeigh (int newWeigh){
	if (newWeigh <= 0) {
		printError();
		return 0;
	} else {
		weigh = newWeigh;
		return 0;
	}
}

bool Tank::setArmor (float newArmor){
	if (newArmor <= 0) {
		printError();
		return 0;
	} else {
		armor = newArmor;
		return 1;
	}
}

int Tank::getId (){
	return id;
}

string Tank::getName (){
	return name;
}

int Tank::getCrew (){
	return crew;
}

int Tank::getMaxSpeed (){
	return maxSpeed;
}

float Tank::getCaliber (){
	return caliber;
}

int Tank::getYearOfProduction (){
	return yearOfProduction;
}

int Tank::getWeigh (){
	return weigh;
}

float Tank::getArmor (){
	return armor;
}

string Tank::getAllData (){
	ostringstream out;
	if (deleteRecord) {
		out << id << " \"0\" ";
	} else {
		out << id << " \"" << name << "\" "<< crew << ' ' << maxSpeed << ' '
		<< caliber << ' ' << yearOfProduction << ' ' << weigh << ' ' << armor;
	}
	return out.str();
}

void Tank::print (){
	if (!id) return;
	cout << "**********************************" << endl;
	cout << "** ID: " << id << "\t\t\t**" << endl;
	if (deleteRecord) {
		cout << "** ЗАПИС В ЧЕРЗІ НА ВИДАЛЕННЯ\t**" << endl;
	} else {
		cout << "** НАЗВА: " << name << "\t\t**" << endl;
		cout << "** ЕКІПАЖ: " << crew << "\t\t\t**" << endl;
		cout << "** МАКСИМАЛЬНА ШВИДКІСТЬ: " << maxSpeed << "\t**" << endl;
		cout << "** КАЛІБР ГАРМАТИ: " << caliber << "\t\t**" << endl;
		cout << "** РІК ВИГОТОВЛЕННЯ: " << yearOfProduction << "\t**" << endl;
		cout << "** МАСА: " << weigh << "\t\t\t**" << endl;
		cout << "** БРОНЯ: " << armor << "\t\t\t**" << endl;
	}
	cout << "**********************************" << endl;
}





