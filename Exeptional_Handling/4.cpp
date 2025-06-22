#include <iostream>
#include <cstring>
using namespace std;
class Furniture
{
private:
    int price;
    string color;
    virtual void SetPrice() = 0;

public:
    Furniture(int p, string c) : price(p), color(c) {}
    void setPrice(int p)
    {
        price = p;
    }

    void setColor(const string &c)
    {
        color = c;
    }

    int getPrice() const
    {
        return price;
    }

    string getColor() const
    {
        return color;
    }
};
class chair : public Furniture
{
public:
    chair(int pr, string col) : Furniture(pr, col) {};

    void SetPrice() override
    {
        setPrice(100);
    }
};
class Table : public Furniture
{
public:
    Table(int pr, string col) : Furniture(pr, col) {}
    void SetPrice() override
    {
        setPrice(200);
    }
};
int main()
{
    chair c(0, "Black"); // price will be set using SetPrice()
    c.SetPrice();        // apply pricing logic
    cout << "Chair - Color: " << c.getColor() << ", Price: " << c.getPrice() << endl;

    Table t(0, "Brown"); // price will be set using SetPrice()
    t.SetPrice();        // apply pricing logic
    cout << "Table - Color: " << t.getColor() << ", Price: " << t.getPrice() << endl;

    return 0;
}