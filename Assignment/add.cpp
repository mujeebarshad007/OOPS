#include <iostream>
using namespace std;
int sum(int a)
{
    if (a == 0)
    {
        return a;
    }
    else
        return a % 10 + sum(a / 10);
}
int main()
{
    int b = 1234;
    cout << sum(b);
    cout << endl;
    return 0;
}