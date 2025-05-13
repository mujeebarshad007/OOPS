#include <iostream>
using namespace std;
class Person
{
protected:
    string name;

public:
    Person(string n)
    {
        name = n;
    }
};
class Student : public virtual Person
{
protected:
    int rollno;
    Student(string n, int r) : Person(n), rollno(r) {}
};
class Employee : public virtual Person
{
protected:
    int empID;
    Employee(string n, int em) : Person(n), empID(em) {}
};
class Result : public Student, public Employee
{

    int marks;

public:
    Result(string n, int r, int id, int m) : Person(n), Student(n, r), Employee(n, id), marks(m) {}
    void display() const
    {

        cout << " Name :" << name << endl;
        cout << " Roll Number :" << rollno << endl;
        cout << " Employee ID :" << empID << endl;
        cout << " Marks :" << marks << endl;
    }
};

int main()
{
    Result r("Mujeeb", 20, 30, 100);
    r.display();
    return 0;
}