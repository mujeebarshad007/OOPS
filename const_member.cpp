#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    Student(string name)
    {
        this->name = name;
    }
    string getname() const
    {
        return name;
    }
};
int main()
{
    Student s1("NIko");
    string names;
    names = s1.getname();
    cout << names << endl;
    return 0;
}