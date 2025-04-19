#include <iostream>
using namespace std;
class Student
{

private:
    int regno;
    string name;

public:
    int x;
    Student()
    {
        cout << "Default Constructor Called" << endl;
    }
    Student(int a, string b)
    {

        regno = a;
        name = b;
    }
};

int main()
{
    Student *s1 = new Student;
    Student *s2 = new Student(100, "Mujeeb");
    s2->getData();
    return 0;
}