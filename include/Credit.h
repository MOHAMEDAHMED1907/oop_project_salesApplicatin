#pragma once
#include "Payment.h"
class Credit : public Payment
{
private:
	string number, type, expireDate;
public:
	int Pay(double );
};

