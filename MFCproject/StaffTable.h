#pragma once
#include "PartyTable.h"
class StaffTable : public virtual PartyTable //Virtual because we used ResTable constractor in the CPP file
{
	//has 5 people in it
public:
	StaffTable();
	void setBill(const double x); //overrides the Restable func
	void checkOut(); //overrides the Restable func
	~StaffTable() {};

private:
	int freeDrinks = 0; //staff gets free drink for every plate
};

