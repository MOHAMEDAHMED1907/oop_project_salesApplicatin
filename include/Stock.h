#pragma once
#include <iostream>
#include "Product.h"
#include <string>
using namespace std;

class Stock
{
private:
    int ProductCounter;
    Product products[600];
public:
	Stock();
	void addStock(string productName,int product_id,int quantity);
	void UpdateStock(int products_id,int quantity);
	int searchProduct(int productId);
	void deleteProduct(int product_id);
	void clearStock();
	int getQuantity(int); // print product quantity
	friend ostream& operator << (ostream& out, Stock& );
};

