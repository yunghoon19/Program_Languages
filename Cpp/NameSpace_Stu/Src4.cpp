/*
    namespace 중첩
*/

#include <iostream>

using namespace std;

namespace First
{
    void printA()
    {
        cout << "First > printA" << endl;
    }

    namespace Second
    {
        void printA()
        {
            cout << "Second > printA" << endl;
        }
    }
}

using First::Second::printA;
// using First::printA;         // 이름 충돌로 오류 발생

int main(void)
{
    First::printA();

    First::Second::printA();
    printA();
    

    return 0;
}