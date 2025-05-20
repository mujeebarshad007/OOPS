#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int id;

public:
    Person(string n = "", int i = 0) : name(n), id(i) {}
    virtual ~Person() {}
};
class User : virtual public Person
{
protected:
    static int countuser;

public:
    User(string n, int i) : Person(n, i)
    {
        countuser++;
    }
    static int getTotalUsers()
    {
        return countuser;
    }

    virtual void displayInfo() = 0;
    virtual double calculatePerformance() = 0;
};
int User::countuser = 0;

class Course
{
protected:
    string coursename;

public:
    Course(string coursn = "") : coursename(coursn) {}
    bool operator==(const Course &c) const
    {
        return coursename == c.coursename;
    }

    friend ostream &operator<<(ostream &os, Course &c)
    {
        os << c.coursename;
        return os;
    }
    friend void assignCourse(class Student &, Course &);
};

class Student : public User
{
private:
    double gpa;
    Course *assignedcourse;

public:
    Student(string name, int id, double g) : User(name, id), gpa(g), assignedcourse(nullptr) {};
    void displayInfo()
    {
        cout << "Student Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
        if (assignedcourse)
        {
            cout << " Course: " << *assignedcourse; /*Prints course detail using operator << which I overloaded*/
            cout << endl;
        }
    }
    virtual double calculatePerformance()
    {
        return gpa;
    }
    friend void assignCourse(Student &, Course &);
};
void assignCourse(Student &s, Course &c)
{
    s.assignedcourse = &c;
}

class Professor : public User
{
    double salary;
    int rank;

public:
    Professor(string name, int id, double s, int r) : User(name, id), salary(s), rank(r) {};

    void displayInfo()
    {
        cout << "Professor Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
    virtual double calculatePerformance()
    {
        return rank;
    }
};

int sumofdigits(int a)
{
    if (a == 0)
    {
        return a;
    }
    else
        return a % 10 + sumofdigits(a / 10);
}
float power(float base, int exp)
{
    if (exp == 0)
        return 1;

    float half = power(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main()
{
    return 0;
}