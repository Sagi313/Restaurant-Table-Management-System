#pragma once
#include "ResTable.h"
class PartyTable: public virtual ResTable
{
public:
	PartyTable();
	~PartyTable();
	double getDiscount();
private:
	double discount = 10; //Pecentage Disccount
};

