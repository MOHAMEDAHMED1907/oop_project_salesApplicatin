#include "OrderItem.h"

OrderItem::OrderItem()
{
}

void OrderItem::updateQuantityInStock(double &new_quantity)
{
    new_quantity-=quantity;
}

void OrderItem::updateQuantity(double newQuantity)
{
    quantity=newQuantity;
   /* double q;
    cout<<"\nEnter the new quantity  "; number.cinAndCheck(q);
    if (q>quantity)
    {
        updateQuantityInStock(q-quantity);
        quantity=q;
    }
    else (){
            updateQuantityInStock(-(quantity-q))
            quantity=q;
    }*/
}


OrderItem OrderItem::operator++(int)
{
    OrderItem tempeditem;
    tempeditem.quantity = quantity++;
    return tempeditem;
}

OrderItem OrderItem::operator--(int)
{
    OrderItem tempeditem;
    tempeditem.quantity = quantity--;
    return tempeditem;
}

void OrderItem::operator+=(float n)
{
    quantity += n;
}

void OrderItem::operator-=(float n)
{
    quantity -= n;

}


double OrderItem::quantityReturn()
{
    return quantity;
}

void OrderItem::setOrderItem(string Pname,int ProductID,double sale_price,double quantity)
{
    this->ProductID=ProductID;
    this->sale_price=sale_price;
    this->quantity=quantity;
    this->Pname=Pname;
}
string OrderItem::getData()
{
    string quan = to_string(int(quantity));
    return quan+" -from-> "+Pname;
}


double OrderItem::sale_price_Return()
{
    return sale_price*quantity;
}






