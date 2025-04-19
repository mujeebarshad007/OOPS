#include <iostream>
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    static int x;

public:
    Student(int r, string n)
    {
        rollno = r;
        name = n;
        x++;
    }
    string getname() const
    {
        return name;
    }
    int getrollno() const
    {
        return rollno;
    }
    static int count()
    {
        return x;
    }
};
int Student::x = 0;

int main()
{
    Student s1(12, "Ali");
    Student s2(13, "Mujeeb");
    Student s3(14, "Rania");
    cout << " The Student 1 " << s1.getname() << " with roll no " << s1.getrollno() << " is added " << endl;
    cout << " The Student 2" << s2.getname() << " with roll no " << s2.getrollno() << " is added " << endl;
    cout << " The Student 3 " << s3.getname() << " with roll no " << s3.getrollno() << " is added " << endl;
    cout << endl;
    cout << " The Total Number of Students added in the system is " << Student::count() << endl;

    return 0;
}