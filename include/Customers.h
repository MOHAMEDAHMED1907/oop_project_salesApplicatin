#pragma once
#include <iostream>
#include "Person.h"
#include"Company.h"
#include <string>
using namespace std;
class Customers
{
private:
    int capacity, CustomerCounter;
	Customer **customerKind;
public:
    Customers();
	Customers(int);
	void addCustomer(int);
	int IdRETURN();
	~Customers();
	int SearchCustomer (int customerId);
	void updateCustomer(int customerId);
	void deleteCustomer(int customerId);
    friend ostream&  operator << (ostream&COUT, const Customers&);
    Customer &operator [](int);




};

