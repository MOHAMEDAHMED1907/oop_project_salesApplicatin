#include "Credit.h"
int Credit::Pay(double d)
{
	Payment::Pay(d);
	cout << "enter the credit number : "; cin >> number;
	cout << "enter the type :"; cin >> type;
	cout << "enter the expireDate :"; cin >> expireDate;
    return 1;
}

