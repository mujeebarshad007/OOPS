#include <iostream>
#include <exception>
using namespace std;

class XYZException : public exception
{
    string msg; // message to store

public:
    // Default constructor
    XYZException()
    {
        msg = "XYZ: Take cover immediately!";
    }

    // Constructor with int parameter
    XYZException(int m)
    {
        msg = "XYZ: " + to_string(m) + " miles away, and approaching!";
    }

    // what() function to show message
    const char *what()
    {
        return msg.c_str();
    }
};

int main()
{
    try
    {
        throw XYZException(); // call default constructor
    }
    catch (XYZException &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        throw XYZException(10); // call constructor with int
    }
    catch (XYZException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
