/*
    namespace 별칭 지정
*/

#include <iostream>

using namespace std;

namespace Student_Namespace_A
{
    int Student_Namespace_num1;

    void Student_Namespace_printA()
    {
        cout << "A space printA" << endl;
    }

    namespace B
    {
        void PrintB()
        {
            cout << "B space printB" << endl;
        }
    }
}

namespace A = Student_Namespace_A;          // 네임스페이스 별칭 지정
auto printA = A::Student_Namespace_printA;  // 네임스페이스::식별자 형태로 별칭 지정
auto num1 = A::Student_Namespace_num1;      // 네임스페이스::식별자 형태로 별칭 지정

namespace B = Student_Namespace_A::B;       // 네임스페이스 중첩 형태 별칭 지정

int main(void)
{
    Student_Namespace_A::Student_Namespace_printA();
    A::Student_Namespace_printA();
    printA();

    cout << Student_Namespace_A::Student_Namespace_num1 << endl;
    cout << A::Student_Namespace_num1;
    cout << num1;

    Student_Namespace_A::B::PrintB();
    B::PrintB();

    return 0;
}