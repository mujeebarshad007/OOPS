#include <iostream>
using namespace std;
int main()
{
    int feet;
    int inch;
    cout << " Enter the Feets : ";
    cin >> feet;
    cout << " Enter the inches : ";
    cin >> inch;
    if (inch >= 12)
    {
        feet += inch / 12;
        inch = inch % 12;
        cout << " The Feets are " << feet << endl;
        cout << " The  Remaning  Inches are " << inch << endl;
    }
    else
    {
        cout << " The Feets are " << feet << endl;
        cout << " The  Inches are " << inch << endl;
    }

    return 0;
}