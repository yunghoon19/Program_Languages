#include <iostream>

using namespace std;

class BankBook
{
private:
    BankBook* bankBook;
    int consumption[13] = {0, };
    
public:
    BankBook () { bankBook = this; }

public:
    BankBook& use(int _month, int _money)
    {
        consumption[_month] = _money;

        return *this;
    }

    void consumptionPrint()
    {
        for (int i = 1; i < 13; i++)
        {
            cout << i << " month consumption : " << consumption[i] << endl;
        }
    }
};

int main(void)
{
    BankBook iBankBook;

    iBankBook.use(1, 100).use(2, 200).use(3, 300);
    iBankBook.use(4, 400);

    iBankBook.consumptionPrint();

    return 0;
}