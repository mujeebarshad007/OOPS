#include <iostream>
using namespace std;
class A
{
public:
    int a;
    A(int a) : a(a) {}
};
class B
{
public:
    void wrok(A x)
    {
        cout << x.a << endl;
    }
};
int main()
{
    A e(2);
    B c;
    c.wrok(e);
    return 0;
}