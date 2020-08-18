#include "stdafx.h"
#include "StaffTable.h"

StaffTable::StaffTable():ResTable(5) //because we want acsess to ResTable constractor , thats why virtual
{
}
void StaffTable::setBill(const double x)
{
	ResTable::setBill(x);
	this->freeDrinks++;
}

void StaffTable::checkOut()
{
	CString str; //popup message
	str.Format(_T("%.2lf Shekels will be taken from you Sallary\n You got %d free Drinks :)"), this->getBill()*((100-this->getDiscount())/100),this->freeDrinks);
	AfxMessageBox(str);

	int i = this->getPeople(); //resets values after checkout
	while (i > 0)
	{
		this->lessPeople();
		i--;
	}
	this->setBill(-(this->getBill()));
	

}

