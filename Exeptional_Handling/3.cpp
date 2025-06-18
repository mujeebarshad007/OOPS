#include <iostream>
using namespace std;
double divide(int a, int b)
{
    if (b == 0)
    {
        throw "Error : Division By Zero !";
    }
    else
    {

        return a / b;
    }
}
int main()
{
    int a, b;
    cout << " Put A and B \n";
    cin >> a >> b;
    double z;
    try
    {
        z = divide(a, b);
        cout << " The Result is " << z << endl;
    }
    catch (const char *message)
    {
        cout << message << endl;
        z = a / (b + 1);
        cout << "The New result after the fall is " << z << endl;
    }
    return 0;
}