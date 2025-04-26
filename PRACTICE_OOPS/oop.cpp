#include <iostream>
using namespace std;
class Student

{
private:
    int *marks;
    string name;

public:
    Student(string name, int m[])
    {
        this->name = name;
        marks = new int[5];
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
        cout << "Student object created: " << name << endl;
    }
    ~Student()
    {
        delete marks;
        cout << "Student object destroyed: " << name << endl;
    }
    void display() const
    {
        cout << " Student Name :  " << name << endl;
        cout << " Marks ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int marks[5] = {100, 97, 78, 80, 84};
    Student s1("Mujeeb", marks);
    s1.display();
    return 0;
}