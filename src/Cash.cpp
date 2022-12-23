#include "Cash.h"

int Cash::Pay(double d)
{
	Payment::Pay(d);

	cout << "\nenter the cashValue : "; cin >> cashValue;
	if (cashValue < d)
		{cout << "\n the cashValue isn't money you need "<<d-cashValue<<" more\n";
            return -1;
		}
		else
            return 1;

}
