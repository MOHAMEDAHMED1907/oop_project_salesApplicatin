#pragma once
#include "Customer.h"
#include <string>

class Company :public Customer
{
private:
	string location, company_name;
public:
	Company();
	Company(int, string, string, string);
	 void Print(ostream&)const;
	 void set(istream&);
      virtual ~Company ();

};

