#pragma once
#include <iostream>
#include <string>
using namespace std; class Payment
{
protected:
	string paid_date;
	double amount;
public:
	virtual int Pay(double );

};

