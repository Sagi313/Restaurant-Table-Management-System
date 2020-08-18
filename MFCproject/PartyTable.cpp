#include "stdafx.h"
#include "PartyTable.h"


PartyTable::PartyTable():ResTable(12) //To call the constractor with maxcap=12
{

}

PartyTable::~PartyTable()
{
}

double PartyTable::getDiscount()
{
	return this->discount;
}


