#include <iostream>
using namespace std;
class Student
{

private:
    int regno;
    string name;

public:
    int x;
    void display()
    {
        cout << x << endl;
    }
};
int main()
{
    Student *s1 = new Student();

    return 0;
}