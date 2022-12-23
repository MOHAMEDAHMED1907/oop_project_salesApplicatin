#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "Customer.h"
class Person :  public Customer
{
private :
	string billing_address,fullName;
public:
	Person();
	Person(int ,string,string,string);
	 void Print(ostream&)const;
	 void set(istream&);
	 virtual ~Person ();

};

