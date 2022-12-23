#include "Order.h"
int Order::cntrIdOrder=0;
ostream& operator<<(ostream& COUT,  Order&OUT)
{
	OUT.print(COUT);
	return COUT;
}

istream& operator>>(istream& CIN, Order&IN)
{
	IN.createOrder(CIN);
	return CIN;
}

Order::Order(int maxItems=100)
{
	// CREATe A random number
	number = rand() % 100000; // [max value 100000] so modulo with it   % 100000

	// current date and time on the current system
    time_t now = time(0);

	 //convert now to string form
	char* date_time_order = ctime(&now);
	date = date_time_order;
	orderItemCounter=0;
	TotalPrice=0;
	itemMax=maxItems;
	orderitem=new OrderItem[itemMax];
	orderid=++cntrIdOrder;

}
Order::Order()
{
	// CREATe A random number
	number = rand() % 100000; // [max value 100000] so modulo with it   % 100000

	// current date and time on the current system
    time_t now = time(0);

	 //convert now to string form
	char* date_time_order = ctime(&now);
	date = date_time_order;
	orderItemCounter=0;
	TotalPrice=0;
	itemMax=10;
	orderitem=new OrderItem[itemMax];

}



void Order::createOrder(istream& in)
{
	cout << "\n\t\t\t\t add an order\nenter id : "; cin >> orderid;
	statue = OrderStatus::NEW;

	// CREATe A random number
	number = rand() % 100000; // [max value 100000] so modulo with it   % 100000

	// current date and time on the current system
	time_t now = time(0);

//	 convert now to string form
	char* date_time_order = ctime(&now);
	date = date_time_order;
	orderid=++cntrIdOrder;
}
void Order::setItems(OrderItem & orderItem) // store item after checking in main
{
    TotalPrice+=orderItem.sale_price_Return();
    orderitem[orderItemCounter++]=orderItem;
}

double Order::TotalPriceReturn() // for transaction
{
    return TotalPrice;
}
void Order::print(ostream&)
{
	cout << "\nid : " << orderid << "     the order number: " << number <<"    orderItemsNumber : "<<orderItemCounter<<"    price; "<<TotalPriceReturn()<< "      Date: " << date<<endl;
	switch (statue)
	{
	case OrderStatus::NEW: cout << "\nthe OrderStatue : NEW  ";break;
	case OrderStatus::HOLD: cout << "\nthe OrderStatue : HOLD ";break;
	case OrderStatus::CANCELED: cout << "\nthe OrderStatue : CANCELED  "; break;
	case OrderStatus::PAID: cout << "\nthe OrderStatue : PAID   ";break;
	default:
		break;
	}

    for (int i=0;i<orderItemCounter;i++)
    {
        cout<<orderitem[i].getData();
    if (i<orderItemCounter-1)
        cout<<" , ";
    }

}

void Order::updateOrderStatue(int s)
{
	switch (s)
	{
	case 0:statue = OrderStatus::NEW; break;
	case 2:statue = OrderStatus::PAID; break;
	case 1:statue = OrderStatus::HOLD; break;
	case 3:statue = OrderStatus::CANCELED; break;

	default:
		break;
	}

}
int Order::getOrderNumber()
{
    return number;
}


/*void Order::PayOrder()
{
	int key;
	cout << "\n Choose the method of payment :\n 1.[ cash ]  2.[ check ]  3.[ credit ]"; cin >> key;
	if (key == 1)
	{
        PMethod=new Cash();
        PMethod->Pay();
		cout << "\nThe cash Method of Payment has been done successfully";
		updateOrderStatue(2);
	}
	else if (key == 2)
	{
	PMethod=new Check();
        PMethod->Pay();
		cout << "\nThe check Method of Payment has been done successfully";
		updateOrderStatue(2);

	}

	else if (key == 3)
	{
        PMethod=new Credit();
        PMethod->Pay();
		cout << "\nThe credit Method of Payment has been done successfully";
		updateOrderStatue(2);
	}
	else
		cout << "\ninvaild input";

}*/


int Order::returnId()
{
		return orderid;
}

Order::~Order()
{
    //delete []orderitem;
    //delete PMethod;
}

