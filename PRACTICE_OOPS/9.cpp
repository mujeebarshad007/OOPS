#include <iostream>
using namespace std;
class ABC
{
private:
    int A, B;
    string name;

public:
    ABC(int a, int b, string name)
    {
        A = a;
        B = b;
        this->name = name;
    }
    friend bool operator==(const ABC &a1, const ABC &a2);
    friend istream &operator>>(istream &in, ABC &s);
    friend ABC operator++(ABC &obj, int);
    friend ostream &operator<<(ostream &out, ABC &s);
};

istream &operator>>(istream &in, ABC &s)
{
    in >> s.A;
    in >> s.B;
    in >> s.name;
    return in;
}
ostream &operator<<(ostream &out, ABC &s)
{
    cout << " 1 :";
    out << s.A << endl;
    cout << " 2 :";
    out << s.B << endl;
    cout << " Name :";
    out << s.name << endl;
    return out;
}
bool operator==(const ABC &a1, const ABC &a2)
{
    return (a1.name == a2.name);
}
ABC operator++(ABC &obj, int)
{
    ABC temp = obj;
    obj.A++;
    obj.B++;
    return temp;
}
int main()
{
    ABC a(1, 2, "ALi");
    ABC b(2, 4, "Usman");

    if (a == b)
    {
        cout << "Equal\n";
    }
    else
    {
        cout << "Not Equal\n";
    }

    a++;
    b++;
    cout << a << endl;
    cout << b << endl;

    return 0;
}