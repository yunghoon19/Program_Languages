#include <iostream>

using namespace std;

class Card
{
private:
    Card* card;
    int consumption[13] = {0, };
    
public:
    Card () { card = this; }

public:
    Card& use(int _month, int _money)
    {
        consumption[_month] = _money;

        return *card;
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
    Card hCard;

    hCard.use(1, 100).use(2, 200).use(3, 300);
    hCard.use(4, 400);

    hCard.consumptionPrint();

    return 0;
}