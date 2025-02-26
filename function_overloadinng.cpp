
// lets learn function overloading  concepts
#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}
int sum(int a, int b, int c)
{
    return a + b + c;
}
int main()
{

    int a, b, c;
    cout << " Enter a << b << c";
    cin >> a >> b >> c;
    cout << sum(a, b);
    cout << endl;
    cout << sum(a, b, c);
    return 0;
}