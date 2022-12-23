#include "Customers.h"

void Customers::addCustomer(int opt)
{

	if (opt == 1)
	{
	    customerKind[CustomerCounter]=new Company();
        cin >> *(customerKind[CustomerCounter++]);
	}
	else if (opt == 2)
	{
	    customerKind[CustomerCounter]=new Person();
        cin>>*(customerKind[CustomerCounter++]);
	}
    cout<<"\nAdded successfully!!";
}


int Customers::SearchCustomer(int CustomerId)
{
    for (int i=0;i<CustomerCounter;i++)
    {
        if (customerKind[i]->getCustomerID()==CustomerId)
            return i;
    }
    return -1;
}
void Customers::updateCustomer(int customerId)
{
    int t;
    t=SearchCustomer(customerId);
    if (t==-1)
        cout<<"\nThere is no Customers with id : "<<customerId<<endl;
    else
    {
        cin>>*(customerKind[t]);

        cout<<"\nUpdated successfully!!";
    }
}
void Customers::deleteCustomer(int customerId)
{
    int t;
    t=SearchCustomer(customerId);
    if (t==-1)
        cout<<"\nThere is no Customers with id : "<<customerId<<endl;
    else
    {
        for (int i=t;i<CustomerCounter-1;i++)
        {
            customerKind[i]=customerKind[i+1];
        }
        CustomerCounter--;
        cout<<"\ndeleted successfully!!";
    }
}

 ostream&  operator << (ostream&out, const Customers&c)
{
    for(int i=0;i<c.CustomerCounter;i++)
        out<<*(c.customerKind[i])<<endl;
    return out;
}

Customers::~Customers()
{
 /*   for (int i=0;i<CustomerCounter;i++)
        delete customerKind[i];//delete pointed objects

    delete []customerKind;//delete Pointers*/

}
Customers::Customers(int capacity)
{
    this->capacity=capacity;
    CustomerCounter=0;
    customerKind=new Customer*[capacity];
}
Customer &Customers::operator [](int position)
{
    return *(customerKind[position]);
}


Customers::Customers()
{

}

