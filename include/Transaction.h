#pragma once
#include <iostream>
#include "OrderList.h"
#include "Check.h"
#include "Cash.h"
#include "Credit.h"
#include <string>

using namespace std;
class Transaction
{
private:
    string transaction_date;
    double totalPriceOfOrders=0;
    int Onum=0;
	OrderList ordersList;
	Payment *Pmethod;
	OrderStatus O;
public:
	Transaction();
	~Transaction();
	friend ostream& operator << (ostream&, Transaction&);
	void setOrdersTransaction(OrderList orders,double,int);
	void getTransaction(ostream&);
	int getID();
	int PayOrder(double money);
    void updaOrderStatues(int s);

};

