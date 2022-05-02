/*
    using 선언
*/

#include <iostream>

using std::cout;
using std::endl;

namespace A
{
    int _num1;
    int _num2;

    void printA()
    {
        cout << "A space printA" << endl;
    }

    void printB()
    {
        cout << "A space printB" << endl; 
    }
}

using A::_num1;
using A::printA;

int main(void)
{
    printA();                   // 가능
    A::printB();                // 가능

    // printB();                // 불가능

    cout << _num1 << endl;      // 가능
    cout << A::_num2 << endl;   // 가능

    // cout << _num2;           // 불가능

    return 0;
}