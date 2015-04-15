#ifndef classTank
#define classTank
#include <string>

using namespace std;

class Tank {
private:
	int id;
	string name;
	int crew;
	int maxSpeed;
	float caliber;
	int yearOfProduction;
	int weigh;
	float armor;
public:
	Tank();
	bool deleteRecord;
	bool setId (int newId);
	bool setName (string newName);
	bool setCrew (int newCrew);
	bool setMaxSpeed (int newMaxSpeed);
	bool setCaliber (float newCaliber);
	bool setYearOfProduction (int newYearOfProduction);
	bool setWeigh (int newWeigh);
	bool setArmor (float newArmor);
	int getId ();
	string getName ();
	int getCrew ();
	int getMaxSpeed ();
	float getCaliber ();
	int getYearOfProduction ();
	int getWeigh ();
	float getArmor ();
	string getAllData ();
	void print ();
	void printError ();
};

#endif
