#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream a;
    ofstream b;
    ofstream c;
    b.open("file1.txt", ios::out);
    if (!b)
    {
        cout << "Error" << endl;
    }
    else
    {
        b << "Hello I am Niko\n";
        cout << " Data Written Successfully" << endl;
    }
    b.close();
    a.open("file1.txt", ios::in);
    c.open("file2.txt", ios::out);
    if (!a)
    {
        "Error\n";
    }
    char ch;
    while (!a.eof())

    {
        a.get(ch);
        ch == toupper(ch);
        c << ch;
    }
    cout << " Data Copied" << endl;
    a.close();
    b.close();
    c.close();
    return 0;
}