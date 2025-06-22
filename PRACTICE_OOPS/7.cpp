#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int id;
    string name;
    double height;
};
Student s;

int main()
{
    fstream a, b, c, d;
    a.open("file1.dat", ios::out | ios::binary | ios::trunc);

    if (!a)
    {
        cout << " Error Opening File 1" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << " Enter the name of the student " << i + 1 << endl;
        cin >> s.name;
        cout << " Enter the Id of the student " << i + 1 << endl;
        cin >> s.id;
        cout << " Enter the height of the student " << i + 1 << endl;
        cin >> s.height;

        a.write((char *)&s, sizeof(s));
    }
    cout << endl;
    cout << " Now for record 2\n";

    b.open("file2.dat", ios::out | ios::binary | ios::trunc);

    if (!b)
    {
        cout << " Error Opening File 1" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << " Enter the name of the student " << i + 1 << endl;
        cin >> s.name;
        cout << " Enter the Id of the student " << i + 1 << endl;
        cin >> s.id;
        cout << " Enter the height of the student " << i + 1 << endl;
        cin >> s.height;
        b.write((char *)&s, sizeof(s));
    }
    a.close();
    b.close();
    a.open("file1.dat", ios::in | ios::binary);
    b.open("file2.dat", ios::in | ios::binary);
    c.open("Combine.dat", ios::out | ios::binary | ios::trunc);
    if (!a || !b || !c)
    {
        cout << " Error Openeing all three Files " << endl;
    }
    while (a.read((char *)&s, sizeof(s)))
    {
        char f = s.name[0];
        if (f == 'a' || f == 'A')
        {
            if (s.height == 6)
            {
                c.write((char *)&s, sizeof(s));
            }
        }
    }
    while (b.read((char *)&s, sizeof(s)))
    {
        char f = s.name[0];
        if (f == 'a' || f == 'A')
        {
            if (s.height == 6)
            {
                c.write((char *)&s, sizeof(s));
            }
        }
    }
    a.close();
    b.close();
    c.close();
    d.open("Combine.dat", ios::in | ios::binary);
    while (d.read((char *)&s, sizeof(s)))
    {
        cout << " The name is : " << s.name << endl;
        cout << " The ID is : " << s.id << endl;
        cout << " The Height is : " << s.height << endl;
    }
    d.close();
    return 0;
}