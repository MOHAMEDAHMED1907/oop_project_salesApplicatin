#pragma once
#include <iostream>
#include <string>
#include "Number.h"
using namespace std;

class Product
{
private:
	int id, type;
	string number, name;
	Number INT;
	double price;
	int quantity;
public:
	Product();
	friend istream & operator >>(istream & in  , Product & product);
	friend ostream & operator <<(ostream & out , Product & product);
	void add(istream& in);
	void print(ostream& in);
	int getId();
	void setId(int id);
	void setquantity(int);
	int getQuantity();
	double getSale();
	string getProductName();
	void setProductName(string);

};

