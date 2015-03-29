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
	void setId (int newId);
	void setName (string newName);
	void setCrew (int newCrew);
	void setMaxSpeed (int newMaxSpeed);
	void setCaliber (float newCaliber);
	void setYearOfProduction (int newYearOfProduction);
	void setWeigh (int newWeigh);
	void setArmor (float newArmor);
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
};

#endif
