#include <iostream>
using namespace std;
class A
{
public:
    int a;
    int b;
    A(int a, int b) : a(a), b(b) {}

    A operator+(const A &obj)
    {
        return A(a + obj.a, b + obj.b);
    }
    void display()
    {
        cout << " The A and b Are" << a << b << endl;
    }
};
int main()
{
    A a1(5, 6);
    A a2(10, 12);
    A a3(0, 0);
    a3 = a1 + a2;
    a3.display();
    return 0;
}