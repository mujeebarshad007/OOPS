#include <iostream>
using namespace std;
class A
{
public:
    string name;
    int age;
    static int count;
    A(string name, int age)
    {
        this->name = name;
        this->age = age;
        count++;
    }
    void static showcount()
    {
        cout << " The Total Objects Created are " << count << endl;
    }
};
int A::count = 0;
int main()
{
    A a("ali", 60);
    A a2("Usman", 69);
    A::showcount();
    return 0;
}