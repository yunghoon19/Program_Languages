/*
    네임스페이스란 무엇인가?
*/

#include <iostream>

using std::cout;
using std::endl;

namespace A
{
    int number = 10;
}

namespace B
{
    int number = 11;
}

void printN(int _num)
{
    cout << _num << endl;
    return;
}

int main(void)
{
    printN(A::number);
    printN(B::number);

    return 0;
}