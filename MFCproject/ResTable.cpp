#include "stdafx.h"
#include "ResTable.h"
#include "MFCprojectDlg.h"

ResTable::ResTable(): maxCapacity(8)
{
	this->peopleInTable = 0;
	this->bill = 0;
}
ResTable::ResTable(int nothing) : maxCapacity(nothing)
{
	peopleInTable = 0;
	bill = 0;
}
const double ResTable::getBill()
{
	return this->bill;
}

void ResTable::setBill(const double x)
{
	this->bill += x;
}

void ResTable::addPeople()
{
	if (peopleInTable < maxCapacity)
		peopleInTable++;
}

void ResTable::lessPeople()
{
	if(peopleInTable>0)
		peopleInTable--;
}

const int ResTable::getPeople()
{
	return this->peopleInTable;
}

void ResTable::checkOut()
{
	CString str;
	str.Format(_T("The total bill : %.2lf"), this->bill);
	AfxMessageBox(str);
	this->peopleInTable = 0;
	this->bill = 0;
}
/*
ResTable& ResTable::operator=(const ResTable& aTable)
{
	this->bill = aTable.bill;
	this->peopleInTable = aTable.peopleInTable;
	this->maxCapacity = aTable.maxCapacity;
	return (*this);
}*/

ResTable::~ResTable()
{

}