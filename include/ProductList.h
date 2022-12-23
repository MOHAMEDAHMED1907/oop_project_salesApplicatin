#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#include "Product.h"

class ProductList
{
    public:
    ProductList(int );
    void addProduct(Product&product);
    int searchProduct(int productId);
    void deleteProduct(int id);
    void editProduct(int index);
	friend ostream & operator <<(ostream & out , ProductList & product);
	Product  & operator [](int position);


    virtual ~ProductList();
    private:
        int ProductCounter,capacity;
        Product *products;

};

#endif // PRODUCTLIST_H
