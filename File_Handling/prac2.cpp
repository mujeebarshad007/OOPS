#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream a;
    a.open("/home/muhib009/Desktop/newfile.dat", ios::in);
    if (!a)
    {
        cout << "error opening file" << endl;
    }
    else
    {
        string line;
        while ((getline(a, line)))
        {
            cout << line << endl;
        }
    }
    a.close();
    return 0;
}
