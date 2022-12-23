#include "ProductList.h"

ProductList::ProductList(int capacity)
{
    this->capacity=capacity;
    ProductCounter=0;
    products = new Product[capacity];
}
void ProductList::addProduct(Product&product)
{
    if (ProductCounter<capacity)
    {
        products[ProductCounter++]=product;
        cout<<"\nDone !!\n";
    }
    else
    cout<<"\nfail !! the Product capacity is full !!\n";

}
int ProductList::searchProduct(int productId)
{
    for (int i=0;i<ProductCounter;i++)
    {
        if (products[i].getId()==productId)
            return i;
    }
    return -1;
}
void ProductList::deleteProduct(int id)
{
    int ch;
    ch=searchProduct(id);
    if (ch==-1)
        cout<<"\nthere is no Product with id :--> "<<id;
    else{
        for(int i=ch;i<ProductCounter-1;i++)
            products[i]=products[i+1];
        ProductCounter--;
    cout<<"\n\tDeleted Sucessfully!!\n";
    }
}

ostream & operator <<(ostream & out , ProductList & product)
{
    for(int i=0;i<product.ProductCounter;i++)
    out<<product.products[i]<<endl;
    return out;
}

ProductList::~ProductList()
{
  //  delete [] products;
}

Product& ProductList::operator [](int position)
{
  if (position<0||position>=ProductCounter)
    {
        cout<<"\n\tthe index is wrong";
        exit(1);
    }
  else
        return products[position];
}
void ProductList::editProduct(int index)
{
     cin>>products[index];
     cout<<"\n\tEdited Sucessfully!!\n";
}

