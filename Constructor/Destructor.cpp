#include <iostream>
using namespace std;
class A
{
    int num;
    float marks;
    string name;

public:
    A()
    {
        num = 10;
        marks = 20.32;
        name = "Ali";
    }
    void display() const
    {
        cout << " The Name is " << name << endl;
        cout << " The Number is " << num << endl;
        cout << " The Marks is " << marks << endl;
    }
    ~A()
    {
        cout << " End of the Program" << endl;
    }
};
int main()
{
    A a1;
    a1.display();
    return 0;
}