#include "Product.h"

istream& operator>>(istream& Cn, Product& product)
{
	product.add(Cn);
	return Cn;
}

ostream& operator<<(ostream& out, Product& product)
{
	product.print(out);
	return out;
}

Product::Product():id(0),type(00),name("..."),number("..."),price(0.0)
{
}

void Product::add(istream& in)
{
	cout << "\nEnter the product id :"; INT.cinAndCheck(id);
	cout << "\nEnter the product type :"; INT.cinAndCheck(type);
	cout << "\nEnter the product name :"; cin >> name;
	cout << "\nEnter the product number :"; cin >> number;
	cout << "\nEnter the product price :";INT.cinAndCheck(price);


}

void Product::print(ostream& in)
{
	cout << "---------------------------[ " << name<<" ]---------------";
	cout << "\n the product id :" <<id
	 << "\n the product type :" << type
	 << "\n the product number :"<< number
	 << "\n the product price :"<<price;

}

int Product::getId()
{
	return id;
}
void Product::setId(int id)
{
	this ->id=id;
}
string Product::getProductName()
{
    return name;
}
void Product::setquantity(int quantity)
{
    this->quantity=quantity;
}
int Product::getQuantity()
{
    return quantity;
}
double Product::getSale()
{
    return price;
}
void Product::setProductName(string name)
{
    this->name = name;
}
