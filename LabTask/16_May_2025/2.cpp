#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct vehicle
{
    int reg_id;
    char owner_name[30];
    char owner_gender[15];
};

vehicle V;

int main()
{
    fstream a, b, c;

    a.open("/home/muhib009/Desktop/Vehicle1.rec", ios::out | ios::binary | ios::app);
    if (!a)
    {
        cout << "Error Opening File A\n";
        return 1;
    }

    b.open("/home/muhib009/Desktop/Vehicle2.rec", ios::out | ios::binary | ios::app);
    if (!b)
    {
        cout << "Error Opening File B\n";
        return 1;
    }

    cout << "Enter 20 records for Vehicle1.rec\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter reg id: ";
        cin >> V.reg_id;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(V.owner_name, 30);

        cout << "Enter Gender: ";
        cin.getline(V.owner_gender, 15);

        a.write((char *)&V, sizeof(V));
    }

    cout << "\nEnter 20 records for Vehicle2.rec\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter reg id: ";
        cin >> V.reg_id;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(V.owner_name, 30);

        cout << "Enter Gender: ";
        cin.getline(V.owner_gender, 15);

        b.write((char *)&V, sizeof(V));
    }

    a.close();
    b.close();
    fstream v1, v2;
    v1.open("/home/muhib009/Desktop/Vehicle1.rec", ios ::in | ios::binary);
    v2.open("/home/muhib009/Desktop/Vehicle2.rec", ios ::in | ios::binary);
    c.open("/home/muhib009/Desktop/Combine.rec", ios ::out | ios::binary | ios::app);

    if (!v1 || !v2 || !c)
    {
        cout << " Error Opening the Files\n";
    }

    while (v1.read((char *)&V, sizeof(V)))
    {

        int l;
        char last_char;
        l = strlen(V.owner_name);
        last_char = V.owner_name[l - 1];
        if ((last_char == 's' || last_char == 'S') && strcmp(V.owner_gender, "female") == 0)
        {
            c.write((char *)&V, sizeof(V));
        }
    }
    while (v2.read((char *)&V, sizeof(V)))
    {

        int l;
        char last_char;
        l = strlen(V.owner_name);
        last_char = V.owner_name[l - 1];
        if ((last_char == 's' || last_char == 'S') && strcmp(V.owner_gender, "female") == 0)
        {
            c.write((char *)&V, sizeof(V));
        }
    }
    v1.close();
    v2.close();
    c.close();

    fstream display;
    display.open("/home/muhib009/Desktop/Combine.rec", ios ::in | ios::binary);
    if (!display)
    {
        cout << " Error Openeing THe Display File " << endl;
    }
    while (display.read((char *)&V, sizeof(V)))
    {
        cout << "Reg ID   : " << V.reg_id << endl;
        cout << "Name     : " << V.owner_name << endl;
        cout << "Gender   : " << V.owner_gender << endl;
        cout << "-----------------------------\n";
    }
    display.close();
    return 0;
}
