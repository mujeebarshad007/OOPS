#include <iostream>
using namespace std;

double divide(int a, int b)
{
    if (b == 0)
    {
        throw "Error: Division by zero!";
    }
    return (double)a / b;
}

int main()
{
    int x = 10, y = 0;
    try
    {
        double result = divide(x, y);
        cout << "Result: " << result << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        cout << "Trying fallback (b + 1): ";
        double fallback = divide(x, y + 1);
        cout << fallback << endl;
    }
    return 0;
}
