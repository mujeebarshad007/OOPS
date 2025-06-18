#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << " x value : ";
    cin >> x;
    cout << "Before try";
    try
    {
        cout << "\nInside try";
        if (x < 0)
        {
            throw x;
            cout << "\nafter throw (Never  Executed)";
        }
    }
    catch (int n)
    {
        cout << "\nExeption Caught";
    }
    cout << "\nAfter catch will be executed\n";
    return 0;
}