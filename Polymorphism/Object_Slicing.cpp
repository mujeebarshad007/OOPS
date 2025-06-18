#include <iostream>
using namespace std;

class Base
{
public:
    int baseValue;
    Base(int val) : baseValue(val) {}
    virtual void display()
    {
        cout << "Base Value: " << baseValue << endl;
    }
};

class Derived : public Base
{
public:
    int derivedValue;
    Derived(int baseVal, int derivedVal) : Base(baseVal), derivedValue(derivedVal) {}
    void display() override
    {
        cout << "Base Value: " << baseValue << ", Derived Value: " << derivedValue << endl;
    }
};

int main()
{
    Derived d(10, 20);
    Base b = d;  // Object slicing occurs here
    b.display(); // Only Base class members are accessible
    return 0;
}
