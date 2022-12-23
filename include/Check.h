#pragma once
#include "Payment.h"
class Check :public Payment
{
private:
	string name,bankID;
public:
	int Pay(double );

};

