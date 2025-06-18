#include <iostream>
#include <fstream>
#include <cstring>
struct vehicle
{
    int reg_id;
    char owner_name[30];
    char owner_gender[15];
};
vehicle V;
using namespace std;
int main()
{
    fstream a;
    a.open("/home/muhib009/Desktop/File_Handling/file1.dat", ios::out | ios::binary | ios::trunc);
    if (!a)
    {
        cout << "Error Opening The File" << endl;
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            cout << " Enter The Details of record " << i + 1 << endl;
            cout << " Enter the registration id\n";
            cin >> V.reg_id;
            cin.ignore();
            cout << "Enter the name of Owner" << endl;
            cin.getline(V.owner_name, 30);
            cout << "Enter the Gender of Owner" << endl;
            cin.getline(V.owner_gender, 30);
            a.write((char *)&V, sizeof(V));
        }
        cout << " Data Of record 1 has been added" << endl;
    }
    fstream b;
    b.open("/home/muhib009/Desktop/File_Handling/file2.dat", ios::out | ios::binary | ios::trunc);
    if (!b)
    {
        cout << "Error Opening The File" << endl;
    }
    else
    {
        cout << " Enter The Details of record " << 2 << endl;
        cout << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << " Enter the registration id\n";
            cin >> V.reg_id;
            cin.ignore();
            cout << "Enter the name of Owner" << endl;
            cin.getline(V.owner_name, 30);
            cout << "Enter the Gender of Owner" << endl;
            cin.getline(V.owner_gender, 30);
            b.write((char *)&V, sizeof(V));
        }
        cout << " Data Of record 2 has been added" << endl;
    }
    a.close();
    b.close();
    fstream c;

    a.open("/home/muhib009/Desktop/File_Handling/file1.dat", ios::in | ios::binary);
    b.open("/home/muhib009/Desktop/File_Handling/file2.dat", ios::in | ios::binary);
    c.open("/home/muhib009/Desktop/File_Handling/combine1.dat", ios::out | ios::binary | ios::trunc);
    if (!a)
    {
        cout << "Error opening file1.dat for reading" << endl;
        return 1;
    }
    if (!b)
    {
        cout << "Error opening file2.dat for reading" << endl;
        return 1;
    }
    if (!c)
    {
        cout << "Error opening combine1.dat for writing" << endl;
        return 1;
    }

    while (a.read((char *)&V, sizeof(V)))
    {
        int x;
        x = strlen(V.owner_name);
        if (V.owner_name[x - 1] == 's' || V.owner_name[x - 1] == 'S')
        {
            if (strcmp(V.owner_gender, "female") == 0)
            {
                c.write((char *)&V, sizeof(V));
            }
        }
    }
    while (b.read((char *)&V, sizeof(V)))
    {
        int z;
        z = strlen(V.owner_name);
        if (V.owner_name[z - 1] == 's' || V.owner_name[z - 1] == 'S')
        {
            if (strcmp(V.owner_gender, "female") == 0)
            {
                c.write((char *)&V, sizeof(V));
            }
        }
    }
    a.close();
    b.close();
    c.close();
    fstream d;
    d.open("/home/muhib009/Desktop/File_Handling/combine1.dat", ios::in | ios::binary);
    {
        if (!d)
        {
            cout << "Error opening file" << endl;
        }
        while (d.read((char *)&V, sizeof(V)))
        {
            cout << "Reg ID     : " << V.reg_id << endl;
            cout << "Owner Name : " << V.owner_name << endl;
            cout << "Gender     : " << V.owner_gender << endl;
            cout << "-----------------------------\n";
        }
    }

    cout << endl;
    cout << endl;

    d.close();
    return 0;
}