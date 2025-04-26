#include <iostream>
using namespace std;
class Student
{
    int rollno;
    static int count;

public:
    string name;
    int age;

    Student(int r, string n, int a)
    {
        rollno = r;
        name = n;
        age = a;
        count++;
    }
    static void countdisplay();
};
void Student ::countdisplay()
{
    cout << " The Total Number Of Objects Created are " << count << endl;
}
int Student ::count = 0;
int main()
{
    Student s1(1, "Mujeeb", 1);
    Student s2(1, "Yumnah", 4);
    Student s3(1, "Rania", 3);
    Student::countdisplay();
    return 0;
}