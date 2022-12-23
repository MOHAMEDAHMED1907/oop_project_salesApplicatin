#include "Transaction.h"

Transaction::Transaction()
{
}
void Transaction::setOrdersTransaction(OrderList orders,double p,int ctr)
{
    ordersList=orders;
    time_t now = time(0);

//	 convert now to string form
	char* date_time_order = ctime(&now);
	transaction_date = date_time_order;
	totalPriceOfOrders=p;
    Onum=ctr;
    O = OrderStatus::NEW;
}
void Transaction::getTransaction(ostream&)
{
    cout<<"\n=============================================================================================================";
    cout<<"\nthe Transaction date"<<transaction_date<<"\nThe Transaction of customer ID : "<<ordersList.getCustomerId()<<endl;
        {cout<<"the orderNumber ----->"<<ordersList.getOrdersNumber();}
    cout<<"    the number Of orders : [ "<<Onum<<" ]\n\t\tthe total Price = "<<totalPriceOfOrders;
    switch (O)
	{
	case OrderStatus::NEW: cout << "\nthe OrdersStatue : NEW  ";break;
	case OrderStatus::HOLD: cout << "\nthe OrdersStatue : HOLD ";break;
	case OrderStatus::CANCELED: cout << "\nthe OrdersStatue : CANCELED  "; break;
	case OrderStatus::PAID: cout << "\nthe OrdersStatue : PAID   ";break;
	default:
		break;
	}
}

ostream& operator<<(ostream&out, Transaction&t)
{
	t.getTransaction(out);
	return out;
}

int Transaction::getID()
{
    return ordersList.getCustomerId();
}
int Transaction::PayOrder(double money)
{
    int opt;
    cout<<"\nENTER the method of payment;-\n\t[ 1.Cash  2.Check  3.Credit ] :";cin>>opt;
    if (opt==1)
    {
        Pmethod=new Cash();
      return  Pmethod->Pay(money);
    }
   else if (opt==2)
    {
        Pmethod=new Check();
       return Pmethod->Pay(money);
    }
   else if (opt==3)
    {
        Pmethod=new Credit();
       return Pmethod->Pay(money);
    }
    return -1;
}
void Transaction::updaOrderStatues(int s)
{
    switch (s)
	{
	case 0:O = OrderStatus::NEW; break;
	case 2:O = OrderStatus::PAID; break;
	case 1:O = OrderStatus::HOLD; break;
	case 3:O = OrderStatus::CANCELED; break;

	default:
		break;
	}
}
Transaction::~Transaction()
{

}

