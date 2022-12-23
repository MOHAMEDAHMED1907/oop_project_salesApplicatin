#include "Person.h"

Person::Person():Customer::Customer(),fullName("moAhmed"), billing_address("/--------------/")
{
}

Person::Person(int id, string phone, string billing_address, string fullName):Customer::Customer(id,phone)
{
	this->billing_address = billing_address;
	this->fullName = fullName;
}

void Person::set(istream&person)
{
	cin.ignore();
	cout << "\nenter the fullName: ";getline(cin,fullName);
	cout << "\nenter the billingAddress: "; cin >> billing_address;

	Customer::set(person);
}


void Person::Print(ostream&person)const
{
	Customer::Print(person);
	cout << " PesronName----> " << fullName<< " BillingAddress----> " << billing_address<<"\n--------------------------------------------------------------------------------------------------------------\n";
}
 Person::~Person (){
}

