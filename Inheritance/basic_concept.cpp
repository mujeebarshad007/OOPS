#include <iostream>
using namespace std;
class Parent
{
public:
    int x;
    string name;
};
class Child : public Parent
{
public:
    Child()
    {
        x = 10;
        name = "Ali";
    }
    void display() const
    {
        cout << " The Value of the x is : " << x << endl;
        cout << " The Value of the Name is : " << name << endl;
    }
};
'

' int main()
{
    Child c;
    c.display();
    return 0;
}