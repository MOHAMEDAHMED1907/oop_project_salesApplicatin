#ifndef ORDERLIST_H
#define ORDERLIST_H
#include "Order.h"
#include "Person.h"
#include "Company.h"
using namespace std;
class OrderList
{
    public:
       OrderList();
       void addOrder(Order & order );
       void editOrder(int id);
       int searchOrder(int id);
       int deleteOrder(int id);
       void setCustomer(Company customerO2);
       void setCustomer(Person customerO1);
       int getOrdercount();
       int  getOrdersNumber();
       double getTotalPrice();
       Order &operator [](int position);
       int getCustomerId();
    friend ostream & operator <<(ostream & out , OrderList&);
    static int counterr;
    static int priceCntr;
    void OrdersStatus(int);
private:
        Number n;
        Person customerO1;
        Company customerO2;
        int P,orderCounter;
        static int counter;
        Order Orders[100];
        double sum=0;

};
#endif
