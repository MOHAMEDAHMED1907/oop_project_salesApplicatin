#include "ProductList.h"
#include "Customers.h"
#include "Transaction.h"
#include "OrderList.h"
#include "Number.h" // this a class i have created for avoiding for loop when user enter char in int variable
#include "Stock.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include <windows.h>        // SetConsoleTextAttribute
 Number number;
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again(){
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,4);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+11);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,5);
    int c;
    printline("ENTER YOUR CHOICE :",false,2);
    cin >> c;
    return c;
}

/** DATA ENTRY AND SUB MENU **/
void sub_sub_menu_1_product(Product &p,ProductList &plist)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> PRODCUTS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
            //printline("Do it here ADD NEW PRODUCT");
            cin>>p;
            plist.addProduct(p);
            system("\npause");
            break;
        case 2:
          //  printline("Do it here EDIT PRODUCT BY ID");
            int pId,index;
            cout<<"\nenter id to search & edit: ";number.cinAndCheck(pId);
            index=plist.searchProduct(pId);
            if (index==-1)
                cout<<"\nthere is no products with id :"<<pId<<endl;
            else
                plist.editProduct(index);
            system("\npause");
            break;
        case 3:
          //  printline("Do it here DELETE PRODUCT BY ID");
            int dId;
            cout<<"\nenter id to search & delete: ";number.cinAndCheck(dId);
            plist.deleteProduct(dId);
            system("\npause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_customer(Customers & cus)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> CUSTOMERS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
            int opt;
           // printline("Do it here ADD NEW CUSTOMER");
            cout <<"\n1.Company\n2.Person\n=============\nenter option  ";number.cinAndCheck(opt);
            cus.addCustomer(opt);
            system("\npause");
            break;
        case 2:
            int cusId;
           // printline("Do it here EDIT CUSTOMER BY ID");
            cout <<"\nenter id Customer to search & edit : ";number.cinAndCheck(cusId);
            cus.updateCustomer(cusId);
            system("\npause");
            break;
        case 3:
           // printline("Do it here DELETE CUSTOMER BY ID");
            cout <<"\nenter id Customer to search & delete : ";number.cinAndCheck(cusId);
            cus.deleteCustomer(cusId);
            system("\npause");
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_stock(Stock &s,ProductList pList)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> STOCK ....");
        c = get_menu_choise("ADD PRODUCT,UPDATE QUANTITY BY ID,CLEAR STOCK",2);
        switch(c)
        {
        case 1:
         //   printline("Do it here ADD PRODUCT TO STOCK BY ID");
            int pId,index,quan;
            cout<<"\nenter id to search & add its product to stock: ";number.cinAndCheck(pId);
            index=pList.searchProduct(pId);
            if (index==-1)
                cout<<"\nthere is no products with id :"<<pId<<endl;
            else
            {
                cout <<"\nenter the quantity of product: ";number.cinAndCheck(quan);
                s.addStock(pList[index].getProductName(),pId,quan);
            }

            system("\npause");
            break;
        case 2:
           // printline("Do it here UPDATE PRODUCT QUANTITY BY ID");
             int sId,newQuan;
            cout<<"\nenter id to  & quantity  to update stock: ";number.cinAndCheck(sId);
            number.cinAndCheck(newQuan);
            s.UpdateStock(sId,newQuan);
            system("\npause");
        break;
        case 3:
           // printline("Do it here CLEAR STOCK");
           s.clearStock();
            system("\npause");
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_menu_1_data_entry(Product &p,ProductList &plist,Stock &stock,Customers &customerlist)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY ....");
        c = get_menu_choise("PRODUCT,CUSTOMER,STOCK",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_1_product(p,plist);
            break;
        case 2:
            sub_sub_menu_1_customer(customerlist);
            break;
        case 3:
            sub_sub_menu_1_stock(stock,plist);
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** SALSES AND SUB MENU **/
int counterOrderList=0;
void sub_sub_menu_2_order(OrderList *OL,Customers cs,ProductList PL,Stock &st)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> ORDERS....");
        c = get_menu_choise("ADD NEW,UPDATE,DELETE",2);
        switch(c)
        {
        case 1:{
                //printline("Do it here 1 ADD NEW ORDER");
            int  productID,quan, n1,n2,option,K=0;
            bool check=false;

            cout<<"\nEnter the ID of the customer data who will order:-\n";
            cout <<"\n1.Company\n2.Person\n=============\nenter option  ";number.cinAndCheck(option);

                if (option==1)
                    { Company CP;
                    cin>>CP;
                    OL[counterOrderList].setCustomer(CP);
                    K++;
                    }

                else if(option==2){
                     Person p;
                     cin>>p;
                      OL[counterOrderList].setCustomer(p);
                     K++;
                     }
                if(K>0){
                cout<<"\nEnter the number of orders";number.cinAndCheck(n1);
            for (int i=0;i<n1;i++){  //cin each order
                    Order order;
                    cout <<"\nthe order number---->"<<i+1<<"\nenter orderItems number";number.cinAndCheck(n2);
                    for(int j=0;j<n2;j++){//cin order items for each Order
                        OrderItem OrderItemTemp;
                        cout<<"\nOrderItem [ "<<j+1<<" ]\nEnter the id of Product you want to order: ";number.cinAndCheck(productID);
                        int f=PL.searchProduct(productID);
                        if (f==-1){
                            continue;
                            cout<<"\nsorry this product is out of stock\n";
                                              }
                        else {
                             int quanInStock=st.getQuantity(productID);
                             cout<<"enter the Quantity of product you want to order [1-->"<<quanInStock<<"]\n";
                             number.cinAndCheck(quan);
                             if (quan>quanInStock){ //check if the orderd quantity < quantity in stock
                                 cout<<"\nFaild\n";
                                if (quanInStock==0)
                                    cout<<"\nsorry this product is out of stock\n";
                                                continue;
                                            }
                            else{

                                 OrderItemTemp.setOrderItem(PL[f].getProductName(),productID,PL[f].getSale(),quan);//productId,sale,quan
                                 order.setItems(OrderItemTemp);//assign orderaItems to the order
                                 check=true;
                                 quanInStock-=quan;
                                 if (quanInStock<0)
                                 quanInStock=0;
                                st.UpdateStock(productID,quanInStock);
                                }
                            }
                                }
                        if (check==true){
                         OL[counterOrderList++].addOrder(order);
                         cout<<"\nDone!! \n";
                        }
                         else
                            cout<<"faild Order Creation !!!";
                         check=false;
                    }
                    }
        }

            system("\npause");
            break;

        case 2:
            {

            //printline("Do it here 2 UPADTE ORDER BY ID");
            int CustomerId,orderID,i=0;
            bool ch=false;
            cout<<"\nEnter the ID of the customer for Order searching & update : ";number.cinAndCheck(CustomerId);
            for (int i;i<counterOrderList;i++)
            {
                if (OL[i].getCustomerId()==CustomerId)
                    {
                        ch=true;
                        cout<<OL[i];
                        break;
                    }
            }
            if(ch==false)
                cout<<"\nNot Found in the system!\n";
            else{
            cout<<"\nEnter the ID of order to access the Data update : ";number.cinAndCheck(orderID);
                    OL[i].editOrder(orderID);

            }
        }
            system("pause");
            break;
        case 3:{
         //   printline("Do it here 2 DELETE ORDER BY ID");
          {

            //printline("Do it here 2 UPADTE ORDER BY ID");
            int CustomerId,orderID,i=0;
            bool ch=false;
            cout<<"\nEnter the ID of the customer for Order searching & update : ";number.cinAndCheck(CustomerId);
            for (int i;i<counterOrderList;i++)
            {
                if (OL[i].getCustomerId()==CustomerId)
                    {
                        ch=true;
                        cout<<OL[i];
                        break;
                    }
            }
            if(ch==false)
                cout<<"\nNot Found in the system!\n";
            else{
            cout<<"\nEnter the ID of order to access the Data then delete : ";number.cinAndCheck(orderID);
                    OL[i].deleteOrder(orderID);

            }
        }
            }
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}
int transactionCounter=0;
double Profits=0;
void sub_sub_menu_2_transaction(Transaction *Transactions,OrderList*orl)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> TRANSACTIONS ....");
        c = get_menu_choise("ADD NEW,Pay,DELETE",2);
        switch(c)
        {
        case 1:{
            //printline("Do it here 1 ADD NEW TRANSACTION");
            int chh,j=0;
            bool ct=false;
            cout<<"\nEnter the Customer ID ";number.cinAndCheck(chh);
            for (j;j<counterOrderList;j++)
            {
                if (orl[j].getCustomerId()==chh)
                {
                    cout<<"\n\t\tFound !!\n";
                    ct=true;
                    break;
                }
            }
            if (ct==true)
            Transactions[transactionCounter++].setOrdersTransaction(orl[j],orl[j].priceCntr,orl[j].counterr);
            else
                cout<<"\nNot Found\n";
        }
            system("\npause");
            break;
        case 2:
            {
            int chh,i=0,l=0;
            bool ct=false;
            cout<<"\nEnter the  Customer ID to access payments S";number.cinAndCheck(chh);
            for (l;l<counterOrderList;l++)
            {
                if(orl[l].getCustomerId()==chh)
                {
                    break;
                }
            }

            for (i;i<transactionCounter;i++)
            {
                if (Transactions[i].getID()==chh)
                {
                    cout<<"\n\t\tFound !!\n";
                    ct=true;
                    break;
                }
            }
            if (ct==false)
                cout<<"\nNot Found\n";
            else{
               int h= Transactions[i].PayOrder(orl[l].priceCntr);
               if (h!=-1){
            cout<<"\nPaid Successfully\n";
            Transactions[i].updaOrderStatues(2);
            orl[l].OrdersStatus(2);
                Profits+=orl[l].priceCntr;
               }
            }
            }
            system("\npause");
            break;
        case 3:{
            //printline("Do it here 2 DELETE TRANSACTION BY ID");
            int chh,i=0;
            bool ct=false;
            cout<<"\nEnter the  ID to search & delete";number.cinAndCheck(chh);
            for (i;i<transactionCounter;i++)
            {
                if (Transactions[i].getID()==chh)
                {
                    cout<<"\n\t\tFound !!\n";
                    ct=true;
                    break;
                }
            }
            if (ct==false)
                cout<<"\nNot Found\n";
            else{
            for (int j=i;j<transactionCounter-1;j++)
            {
             Transactions[j]=Transactions[j+1];
            }
            cout<<"\ndeleted Successfully\n";
            transactionCounter--;
            }
        }
            system("\npause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_menu_2_sales_process(OrderList* ol ,Customers&cs,ProductList PL,Stock &stock,Transaction *Trs)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS ....");
        c = get_menu_choise("ORDER,TRANSCATION",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_2_order(ol,cs,PL,stock);
            break;
        case 2:
            sub_sub_menu_2_transaction(Trs,ol);
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}


/** PRINTS AND SUB MENU **/

void sub_menu_3_prints(ProductList p,Stock s,Customers customerlist,OrderList *OL,Transaction *TT)
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PRINTS ....");
        c = get_menu_choise("PRODUCT,STOCK,CUSTOMER,ORDERS,TRANSACTIONS,PROFIT",1);
        switch(c)
        {
        case 1:
            //printline("Do it here 1 PRINT PRODUCTS");
            cout<<p<<endl;
            system("pause");
            break;
        case 2:
           // printline("Do it here 2 PRINT STOCK");
            cout<<s<<endl;
            system("pause");
            break;
        case 3:
           // printline("Do it here 3 PRINT CUSTOMERS");
            cout<<customerlist;
            system("\npause");
            break;
        case 4:
           // printline("Do it here 4 PRINT ORDERS");
               for(int i=0;i<counterOrderList;i++)
               {
                   cout<<OL[i];
               }
            system("\npause");
            break;
        case 5:
            //printline("Do it here 5 PRINT TRANSACTIONS");
            for(int j=0;j<transactionCounter;j++)
               {
                   cout<<TT[j];
               }
            system("\npause");
            break;
        case 6:
          //  printline("Do it here 6 CALC PROFIT");
          cout<<"\n\n\n\t\t\tProfits :=--------------------> [ "<<Profits<<" ]\n\n\n";
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** MAIN FUNCTION **/
int main()
{
    Order order;
    //Person p;
    OrderList *OL;
    Transaction transctions[100];
    OL=new OrderList[100];
    int mxProduct,mxCustomers;
    cout<<"\nEnter the max Number of productS";number.cinAndCheck(mxProduct);
    cout<<"\nEnter the max Number of Customers";number.cinAndCheck(mxCustomers);
    cout << "\n\n\n\n\n\t\t\t=========================================================\n";
	cout << "\t\t\t*********************************************************\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                     		              |**\n";
	cout << "\t\t\t**|                                            	      |**\n";
	cout << "\t\t\t**|                                           	      |**\n";
	cout << "\t\t\t**|                     WELCOME TO                    |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|              [ Sales Order Application.V2 ]       |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|          By: Mohamed Ahmed Mohamed Sayed Ali      |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|___________________________________________________|**\n";
	cout << "\t\t\t*********************************************************\n\n\n\n\t\t\t";
	system("pause");
    ProductList productList(mxProduct);
    Customers CustomerList(mxCustomers);
    Product product;
    Stock stock;

    printline("START APPLICATION ....",1,6);
    wait_or_clear(1,1);
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,10);
        c = get_menu_choise("DATA ENTRY,SALES PROCESS,PRINTS",0);
        switch(c)
        {
        case 1:
            sub_menu_1_data_entry(product,productList,stock,CustomerList);
            break;
        case 2:
            sub_menu_2_sales_process(OL,CustomerList,productList,stock,transctions);
            break;
        case 3:
            sub_menu_3_prints(productList,stock,CustomerList,OL,transctions);
            break;
        case 0:
            delete[]OL;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t=========================================================\n";
			cout << "\t\t\t\t\t*********************************************************\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                     		              |**\n";
			cout << "\t\t\t\t\t**|                                            	      |**\n";
			cout << "\t\t\t\t\t**|                                           	      |**\n";
			cout << "\t\t\t\t\t**|                     thank you                     |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|          By: Mohamed Ahmed Mohamed Sayed Ali      |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|                                                   |**\n";
			cout << "\t\t\t\t\t**|___________________________________________________|**\n";
			cout << "\t\t\t\t\t*********************************************************\n\n\n\n\t\t\t\t\t";
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            print_try_again();
            wait_or_clear(3, true);
        }
    }
    return 0;
}

