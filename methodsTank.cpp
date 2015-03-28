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
}

void Tank::setId (int newId){
	if (newId < 0) {
		cout << "Error." << endl;
	} else {
		id = newId;
	}
}

void Tank::setName (string newName){
	if (newName == "")  {
		cout << "Error." << endl;
	} else {
		name = newName;
	}
}

void Tank::setCrew (int newCrew){
	if (newCrew < 1) {
		cout << "Error." << endl;
	} else {
		crew = newCrew;
	}
}

void Tank::setMaxSpeed (int newMaxSpeed){
	if ((newMaxSpeed < 0) && (newMaxSpeed > 150)) {
		cout << "Error." << endl;
	} else {
		maxSpeed = newMaxSpeed;
	}
}

void Tank::setCaliber (float newCaliber){
	if ((newCaliber < 0) && (newCaliber > 300)) {
		cout << "Error." << endl;
	} else {
		caliber = newCaliber;
	}
}

void Tank::setYearOfProduction (int newYearOfProduction){
	if ((newYearOfProduction < 1900) && (newYearOfProduction > 2015)) {
		cout << "Error." << endl;
	} else {
		yearOfProduction = newYearOfProduction;
	}
}

void Tank::setWeigh (int newWeigh){
	if (newWeigh < 0) {
		cout << "Error." << endl;
	} else {
		weigh = newWeigh;
	}
}

void Tank::setArmor (float newArmor){
	if (newArmor < 0) {
		cout << "Error." << endl;
	} else {
		armor = newArmor;
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
	out << id << " \"" << name << "\" "<< crew << ' ' << maxSpeed << ' '
			<< caliber << ' ' << yearOfProduction << ' ' << weigh << ' ' << armor;
	return out.str();
}
