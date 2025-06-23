#include <iostream>
#include <exception>
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
        throw t;
    }
    catch (exception &n)
    {
        cout << " Caught \n";
    }
    return 0;
}