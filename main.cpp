#include <iostream>
#include<conio.h>
#include "DataEntry.h"
#include "SalesProcess.h"
using namespace std;

int main()
{
	DataEntry data;
	SalesProcess sales;
	int ch1, ch2, ch3,ch4,ch5,ch6,ch7,ch8;
	bool input = true;
	cout << "\n\n\n\n\n\t\t\t=========================================================\n";
	cout << "\t\t\t*********************************************************\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                     		              |**\n";
	cout << "\t\t\t**|                                            	      |**\n";
	cout << "\t\t\t**|                                           	      |**\n";
	cout << "\t\t\t**|                     WELCOME TO                    |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|              [ Sales Order Application ]          |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|          By: Mohamed Ahmed Mohamed Sayed Ali      |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|                                                   |**\n";
	cout << "\t\t\t**|___________________________________________________|**\n";
	cout << "\t\t\t*********************************************************\n\n\n\n\t\t\t";
	system("pause");
	while (1) {
		system("cls");
		cout << "\n\n==========================================\n";
		cout << "Welcome to the Sales Order Application\n";
		cout << "==========================================\n\n";
		cout << "1. Menu" << "\n\n";;
		cout << "2. Exit" << "\n\n";
		cout << "==========================================\n\n";
		cout << "Enter Your Choice: ";
		cin >> ch1;
		if (ch1 == 1)
		{
			system("cls");
			cout << "\n\n******************************************\n";
			cout << "========================================**\n";
			cout << "                                        **\n";
			cout << "1.[ Data Entry ]                        **\n";
			cout << "                                        **\n";
			cout << "2.[ Sales Process ]                     **\n";
			cout << "                                        **\n";
			cout << "3.[ Print ]                             **\n";
			cout << "                                        **\n";
			cout << "5.[ EXIT ]                              **\n";
			cout << "                                        **\n";
			cout << "========================================**\n";
			cout << "******************************************\n";

			cout << "Enter Your choice: ";cin >> ch2;
			switch (ch2)
			{
			case 1:
				cout << "\n1. [ Customer ]\n\n2. [ Product ]";
					cout << "\n=====================";
				cout << "\nEnter Your choice: "; cin >> ch3;
				if (ch3 == 1)
				{
					system("cls");
					cout << "\n\n1.[ add a new customer ]\n\n2.[ update customer ]\n\n3.[ delete a customer ]\n===============================\nEnter Your choice:"; cin >> ch4;
					switch (ch4)
					{
					case 1:
						data.addCustomer();
						break;
					case 2:
						data.updateCustomer();
						break;
					case 3:
						data.deleteCustomer();
						break;
					default:
						cout << "\ninvaild input";
						break;
					}
				}
				else if (ch3 == 2)
				{
					system("cls");
					cout << "\n\n1.[ add a new product ]\n\n2.[ update a product ]\n\n3.[ delete a product ]\n=========================\nEnter Your choice:"; cin >> ch5;
					switch (ch5)
					{
					case 1:
						data.addPrdouct();
						break;
					case 2:
						data.updatePrdouct();
						break;
					case 3:
						data.deletePrdouct();
						break;
					default:
						cout << "\ninvaild input";
						break;
					}

				}
			default:
				break;
			case 2:
				cout << "\n\n1. [ add transaction ]\n\n2. [ update order ]\n\n3. [ pay order ]\n\n4. [ edit order ]";
				cout << "\n=================";
				cout << "\nEnter Your choice: "; cin >> ch6;
				switch (ch6)
				{
				case 1:
					sales.addTransation();
					break;
				case 2:
					sales.updateOrder();
					break;
				case 3:
					sales.PayOrder();
					break;
				case 4:
					sales.editOrder();
				default:
					cout << "\ninvaild input";
					break;
				}
			case 3:
				cout << "\n1. [ Print customers ]\n\n2. [ print stockData ]\n\n3. [ print Transactions ]";
				cout << "\n============";
				cout << "\nEnter Your choice: "; cin >> ch7;
				switch (ch7)
				{
				case 1:
					data.printCustomers();
					system("pause");
					break;
				case 2:
					data.printPrdouct();
					system("pause");
					break;
				case 3:
					sales.printTransations();
					system("pause");
					break;
				default:
					cout << "\ninvaild input";
					system("pause");
					break;
				}

			}


		}
		else if (ch1 == 2)
		{
			system("cls");
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



			return 0;
		}
		else
		{
			continue;

		}
	}
return 0;

}
