#pragma once
class ResTable
{
public:
	ResTable();
	ResTable(const int);
	virtual ~ResTable() = 0;
	const double getBill();
	virtual void setBill(const double x);
	void addPeople();
	void lessPeople();
	const int getPeople();
	virtual void checkOut();

private:
	const int maxCapacity; //The max people in table
	double bill; 
	int peopleInTable;


};

