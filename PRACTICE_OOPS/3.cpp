#include <iostream>
using namespace std;
class Test
{
public:
    string s_name;
    float marks;

    Test(string s_name, float marks) : s_name(s_name), marks(marks) {}
};
class Student
{
public:
    string name;
    int rn;
    Test *t1, *t2;
    Student(string name1, int rn1)
    {

        name = name1;
        rn = rn1;
        t1 = nullptr;
        t2 = nullptr;
    }
    void givetest(Test *test1, Test *test2)
    {
        t1 = test1;
        t2 = test2;
    }
    void show()
    {
        cout << " \nStudent :" << name << "(Roll #" << rn << ")\n";
        float total = t1->marks + t2->marks;
        float avg = total / 2;
        float perc = (total / 200) * 100;
        cout << t1->s_name << " " << t1->marks << (t1->marks >= 40 ? "(PASS)" : "(FAIL)") << endl;
        cout << t2->s_name << " " << t2->marks << (t2->marks >= 40 ? "(PASS)" : "(FAIL)") << endl;
        cout << "Total Marks : " << total << endl;
        cout << "Average Marks : " << avg << endl;
        cout << "Percentage Marks : " << perc << endl;
    }
};
int main()
{
    Test t1("English", 100);
    Test t2("Math", 39);
    Student s("Mujeeb", 2);
    s.givetest(&t1, &t2);
    s.show();
    return 0;
}