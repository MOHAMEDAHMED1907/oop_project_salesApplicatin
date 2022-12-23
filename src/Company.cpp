#include "Company.h"

Company::Company(): location("noLocation"),company_name("noName")
{
}

Company::Company(int id, string phone, string l, string cn):Customer::Customer(id,phone)
{
	location = l;
	company_name = cn;
}


void Company::set(istream& company)
{
	cin.ignore();
	cout << "\nenter the combanyName: "; cin>>company_name;//getline(cin, company_name);
	cout << "\nenter the location: "; cin >> location;

	Customer::set(company);
}


void Company::Print(ostream& company)const
{
	Customer::Print(company);
	cout << " CompanyName---->" << company_name<<" Location---->" << location<<"\n-------------------------------------------------------------------------------------------------------------\n";
}
 Company::~Company()
{

}

