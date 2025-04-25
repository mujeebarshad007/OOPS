#include <iostream>
using namespace std;
class Inverntory
{
private:
    string itemName;
    int quantity;

public:
    Inverntory(string i, int q)
    {
        itemName = i;
        quantity = q;
    }

    void operator+()
    {
        quantity = quantity + 1;
        cout << " The Quantity of Item " << itemName << " After restocking is " << quantity << endl;
    }
    void operator-()
    {
        quantity = quantity - 1;
        cout << " The Quantity of Item " << itemName << " After Selling is " << quantity << endl;
    }
};
int main()
{
    Inverntory a("Milk", 10);
    Inverntory b("Toothpase", 100);
    +a;
    -a;
    +b;
    -b;

    return 0;
}