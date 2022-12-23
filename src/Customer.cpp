#include "Customer.h"

ostream& operator<<(ostream& COUT, const Customer& currentCustomer)
{
	currentCustomer.Print(COUT);
	return COUT;
}

istream& operator>>(istream& CIN, Customer&currentCustomer)
{
	currentCustomer.set(CIN);
	return CIN;
}

Customer::Customer():id(0),phone("[][][][][][][][]")
{

}

Customer::Customer(int id, string phone)
{
	this->id = id;
	this->phone = phone;
}

int Customer::getCustomerID()
{
    return id;
}
/*int Customer::SearchOrder(int orderId)
{
    for (int i=0;i<orderCounter;i++)
    {
        if (order[i].getId()==orderId)
            return i;
    }
    return -1;4
}*/

void Customer::set(istream&)
{
	cout << "Enter Id : "; num.cinAndCheck(id);
	cout << "Enter Phone : "; cin >>phone;
}

void Customer::Print(ostream&)const
{
	cout << "\nID----> "<<id<< " Phone----> "<<phone;

}
Customer::~Customer()
{
//    delete [] order;
}


//void Customer::createOrder(Order &OrderIn);

//void UpdateOrder(int id)

