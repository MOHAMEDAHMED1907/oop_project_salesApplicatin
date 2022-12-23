#pragma once
#include <iostream>
#include <ctime>
#include "OrderStatus.h"
#include "OrderItem.h"
#include "Cash.h"
#include "Check.h"
#include"Credit.h"
#include <string>


using namespace std;

class Order
{
private:
	int orderItemCounter,itemMax,orderid,number; //= rand() % 100000;  [max value 100000] so modulo with it   % 100000
	string date;
	double TotalPrice;
	OrderStatus statue;
	OrderItem *orderitem;
	//Payment *PMethod;

public:

	Order(int);
    Order();
	void createOrder(istream&);
	void print(ostream&);
	void updateOrderStatue(int );
	void setItems(OrderItem & orderItem);
	double TotalPriceReturn();
    static int cntrIdOrder;
    int getOrderNumber();
	//void updateQuan();
	//void PayOrder();
	void inItems();
	int returnId();
	friend ostream& operator << (ostream& COUT, Order&);
	friend istream& operator >> (istream& CIN, Order&);
    ~Order();

} ;
