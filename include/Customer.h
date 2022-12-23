#pragma once
//#include "OrderList.h"
#include "Number.h"
#include <iostream>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(int, string);
	friend ostream&  operator << (ostream&COUT, const Customer&);
	friend istream& operator >> (istream&CIN,  Customer&);
	//int SearchOrder(int OrderId);
	//void createOrder(int pos);
	//void UpdateOrder(int id);
	//void EditOrder();
	int getCustomerID();

    virtual void set(istream&);
	virtual void Print(ostream&)const;
	virtual ~Customer();

private:
	int id;
	string phone;
	int orderQuantityMax, orderCounter;
	Number num;
	//OrderList *Orders;
};
