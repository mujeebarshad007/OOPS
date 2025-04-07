#include <iostream>
using namespace std;
template(class T);
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    cout << " The maximum of 3 and 4 is " < int > << myMax(3, 4) << endl;
    cout << " The maximum of a and z is " < char > <, myMax('a', 'z') << endl;
    return 0;
}