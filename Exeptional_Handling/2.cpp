#include <iostream>
// exeption is always thrown when all the constructor or destructor of the object are called
using namespace std;
class Test
{
public:
    Test()
    {
        cout << " constructor Called " << endl;
    }
    ~Test()
    {
        cout << " Destructor Called " << endl;
    }
};
int main()
{
    try
    {
        Test t;
        throw 10;
    }
    catch (int n)
    {
        cout << " Caught \n";
    }
    return 0;
}