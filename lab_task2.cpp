#include <iostream>
using namespace std;
void printStudentDetails(string name, int rollno = 0, char grade = 'N', double marks = 0.0)
{
    cout << " The Name of the Student is " << name << endl;
    cout << " The Roll no of the Student is " << rollno << endl;
    cout << " The Grade of the Student is " << grade << endl;
    cout << " The marks of the Student is " << marks << endl;
}
int main()
{

    printStudentDetails("Alice", 101, 'A', 95.5);

    return 0;
}