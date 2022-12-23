#include "Stock.h"

Stock::Stock()
{
	ProductCounter = 0;
}

void Stock::addStock(string productName,int product_id,int quantity)
{
    products[ProductCounter].setProductName(productName);
    products[ProductCounter].setId(product_id);
    products[ProductCounter++].setquantity(quantity);
}
int Stock::searchProduct(int productId)
{
    for (int i=0;i<ProductCounter;i++)
    {
        if (products[i].getId()==productId)
            return i;
    }
    return -1;
}

void Stock::UpdateStock(int product_id,int quantity)
{
    int t=searchProduct(product_id);
    if (t==-1)
    {
        cout<<"\n\tthere is no products with id :"<<product_id;
    }
    else
    {
        products[t].setId(product_id);
        products[t].setquantity(quantity);
        cout <<"\n\tupdated successfully\n";
    }
}
void Stock::deleteProduct(int product_id)
{
    int t=searchProduct(product_id);
    if (t==-1)
    {
        cout<<"\n\tthere is no products with id :"<<product_id;
    }
    else
    {
        for (int i=t;i<ProductCounter-1; i++ )
        {
            products[i]= products[i+1];
        }
        ProductCounter--;
      cout <<"\n\tdeleted successfully\n";

    }
}

int Stock::getQuantity(int productID)
{
    int t=searchProduct(productID);
    if (t==-1)
        return t;
    else
       return products[t].getQuantity();
}

ostream& operator << (ostream& out, Stock& stock)
{
    out<<"\n| Product name | Product ID | Product Quantity |\n";
    for (int i=0;i<stock.ProductCounter ;i++)
        out<<endl<<stock.products[i].getProductName()<<" \t \t "<<stock.products[i].getId()<<" \t\t  "<<stock.products[i].getQuantity()<<endl;
    return out;
}
void Stock::clearStock()
{
    cout<<"\t\t\tWarning all stock data will be deleted !!\n";
    ProductCounter=0;
    cout<<"\n\t\tDone !!";
}

