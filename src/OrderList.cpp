#include "OrderList.h"
int OrderList::counterr=0;
int OrderList::priceCntr=0;

OrderList::OrderList()
{
   orderCounter=0;
    P=0;

}

void OrderList::setCustomer(Person customerO1)
{
    this->customerO1=customerO1;
    P=1;
}
void OrderList::setCustomer(Company customerO2)
{
    this->customerO2=customerO2;
    P=-1;
}
void  OrderList::addOrder(Order & order )
{     Orders[orderCounter++]=order;
        counterr+=1;
        priceCntr+=order.TotalPriceReturn();
}

void OrderList::editOrder(int id)
{
    int t=searchOrder(id);
    if (t==-1)
        cout<<"\nthere is no orders in this id "<<id<<endl;
    else
    {
	int statue;
	cout<<"\n0.NEW 1.HOLD  2.PAID 3.CANACELD  \nEnter the status of order: ";n.cinAndCheck(statue);
    Orders[t].updateOrderStatue(statue);
    }
}
int OrderList::deleteOrder(int id)
{
    int t=searchOrder(id);
    if (t==-1)
        cout<<"\nthere is no orders in this id "<<id<<endl;
    else
    {
	for (int i=t;i<orderCounter-1;i++ )
	    {
	        Orders[i]=Orders[i+1];
	    }
	    orderCounter--;
    }
}

int OrderList::searchOrder(int id)
{
    for(int i=0;i<orderCounter;i++)
    {
        if (Orders[i].returnId()==id)
            return i;
    }
    return -1;
}
 ostream &operator <<(ostream& out,OrderList&oList)
{
    if (oList.P==1)
    {
        out<<"\n--------------------------------------------------[ Customer  ]-----------------------------------------------\n";
        out<<oList.customerO1<<endl;
    }
    else if (oList.P==-1)
        {
        out<<"\n--------------------------------------------------[ Customer  ]-----------------------------------------------\n";
        out<<oList.customerO2;
        }

    for (int i=0;i<oList.orderCounter;i++)
         {out<<oList.Orders[i]<<endl;}
        return out;

}
int OrderList::getCustomerId()
{
    if (P==1)
    return customerO1.getCustomerID();
    else
    return customerO2.getCustomerID();
}


Order &OrderList::operator [](int position)
{
    return Orders[position];
}

int OrderList::getOrdercount()
{
    return orderCounter;
}
int OrderList::getOrdersNumber()
{
        return  Orders[0].getOrderNumber(); ;
}
void OrderList::OrdersStatus(int s)
{
    for(int i=0;i<orderCounter;i++)
        Orders[i].updateOrderStatue(s);
}


