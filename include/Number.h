// i have created this class for avoiding an infinity loop  when enter char instead integer
#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include<iostream>
#include <limits>
using namespace std;
class Number
{
public:
    Number(){};
 void cinAndCheck(int &num)
    {
    while(cout << ": " && !(cin >> num))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
void cinAndCheck(double &num)
    {
    while(cout << ": " && !(cin >> num))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }



};

#endif // NUMBER_H_INCLUDED
