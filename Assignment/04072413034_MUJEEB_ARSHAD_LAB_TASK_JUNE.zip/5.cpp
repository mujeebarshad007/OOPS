#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

int safeSubtract(int a, int b)
{
    int result = a - b;
    if (result < 0)
    {
        throw underflow_error("Underflow: Result is negative");
    }
    return result;
}

int main()
{
    int a = 3, b = 7;
    try
    {
        try
        {
            int result = safeSubtract(a, b);
            cout << "Subtraction Result: " << result << endl;
        }
        catch (underflow_error &e)
        {
            cout << e.what() << endl;
            cout << "Returning 0 as fallback from inner catch." << endl;
            cout << "Absolute Difference: " << abs(a - b) << endl;
        }
    }
    catch (...)
    {
        cout << "Something unexpected happened." << endl;
    }
    return 0;
}