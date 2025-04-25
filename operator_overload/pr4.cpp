#include <iostream>
using namespace std;
class InventoryItem
{
private:
    string itemname;
    int quantity;

public:
    InventoryItem(string itemname, int quantity)
    {
        this->itemname = itemname;
        this->quantity = quantity;
    }

    void operator+()
    {
        quantity += 1;
        cout << " The Item " << itemname << " is restocked with final quantity : " << quantity << endl;
    }
    void operator-()
    {
        quantity -= 1;
        cout << " The Item " << itemname << " is sold with final quantity : " << quantity << endl;
    }
};
int main()
{
    InventoryItem i("Milk", 100);
    -i;
    +i;
    return 0;
}