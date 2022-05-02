/*
    using 지시문
*/

#include <iostream>

using namespace std;

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

using namespace A;

int main(void)
{
    printA();                   // 가능
    A::printB();                // 가능

    printB();                   // 가능

    cout << _num1 << endl;      // 가능
    cout << A::_num2 << endl;   // 가능

    cout << _num2;              // 가능

    return 0;
}