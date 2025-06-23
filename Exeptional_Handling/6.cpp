#include <iostream>
#include <exception>
using namespace std;
class A : public exception
{
public:
    string msg;
    A()
    {
        msg = "Error Occured";
    }
    A(int m)
    {
        msg = "Error 2 occured ";
    }

    const char *what()
    {
        return msg.c_str();
    }
};
int main()
{
    try
    {
        throw A();
    }
    catch (A &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        throw A(20);
    }
    catch (A &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}