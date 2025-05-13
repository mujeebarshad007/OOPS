#include <iostream>
using namespace std;
class A
{
    void display()
    {
        cout << "Hello" << endl;
    }
};
class B
{
public:
    void display()
    {
        cout << "Hello Bro" << endl;
    }
};
class C : public A, public B
{
public:
};
int main()
{
    C c;
    c.B::display();
    return 0;
}