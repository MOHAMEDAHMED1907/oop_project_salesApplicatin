 #pragma once
#include <iostream>
#include <cstring>
#include "Stock.h"
using namespace std;
class OrderItem
{
private:
	double sale_price, quantity;
	int ProductID;
    string Pname;
public:
	OrderItem();
    void setOrderItem(string Pname,int productId,double sale,double quantity);
    void updateQuantity(double newQuantity);
	OrderItem operator++(int);
	OrderItem operator--(int);
	void operator+=(float);
	void operator-=(float);
	void updateQuantityInStock(double &);
	double quantityReturn();
	double sale_price_Return();
	string getData();

};

