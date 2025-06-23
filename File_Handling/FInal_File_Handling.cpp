#include <iostream>
#include <fstream>
using namespace std;
class Inventory
{
private:
    int item_number;
    double quantity;
    double wholesalecost;
    double retailcost;

public:
    Inventory() {}
    void Input()
    {
        cout << " Enter The Item Number : " << endl;
        cin >> item_number;
        cout << " Enter theThe Quantity On Hand : " << endl;
        cin >> quantity;
        cout << " Enter The WholeSale Cost : " << endl;
        cin >> wholesalecost;
        cout << " Enter The Retial Cost : " << endl;
        cin >> retailcost;
    }
    int getitemnumber()
    {
        return item_number;
    }
    void Addrecord(const char *filename)
    {
        ofstream a;
        a.open(filename, ios::binary | ios::app);
        if (!a)
        {
            cout << " Error Opening The File " << endl;
        }
        char choice;
        do
        {
            Input();
            a.write((char *)this, sizeof(*this));
            cout << " Record Added Successfully\n";
            cout << " Do you want More records or not" << endl;
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        a.close();
    }

    static void DisplayAllRecords(const char *filename)
    {
        ifstream fin(filename, ios::binary);
        if (!fin)
        {
            cout << "Error opening file.\n";
            return;
        }

        Inventory temp;
        cout << "\n===== All Inventory Records =====\n";
        while (fin.read((char *)&temp, sizeof(temp)))
        {
            temp.Display();
            cout << "-----------------------------\n";
        }

        fin.close();
    }

    void Display() const
    {
        cout << " The Item Number is :" << item_number << endl;
        cout << " The Quantity On Hand is :" << quantity << endl;
        cout << " The WholeSaleCost is :" << wholesalecost << endl;
        cout << " The RetailCost is :" << retailcost << endl;
    }

    static void DisplayRecord(const char *filename, int Search_Item)
    {
        ifstream b(filename, ios::binary);
        if (!b)
        {
            cout << "Error opening file.\n";
            return;
        }

        if (!b)
        {
            cout << " Error Opening B File " << endl;
        }
        Inventory temp;
        bool found = false;
        while (b.read((char *)&temp, sizeof(temp)))
        {
            if (temp.getitemnumber() == Search_Item)
            {
                cout << " The Record Has been Found " << endl;
                temp.Display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Record not found.\n";
        b.close();
    }

    static void DeleteRecord(const char *filename, int del_Item)
    {
        ifstream c;
        c.open(filename, ios::binary);
        ofstream d;
        d.open("temp.dat", ios::binary);
        if (!c || !d)
        {
            cout << " Error Opening File \n";
        }
        Inventory temp;
        bool found = false;
        while (c.read((char *)&temp, sizeof(temp)))
        {
            if (temp.getitemnumber() != del_Item)
            {
                d.write((char *)&temp, sizeof(temp));
            }
            else
            {
                found = true;
            }
        }
        c.close();
        d.close();
        remove(filename);
        rename("temp.dat", filename);
        if (found)
            cout << "Record deleted.\n";
        else
            cout << "Record not found.\n";
    }
};
void Menu()
{
    Inventory inv;
    const char *filename = "file1.dat";

    int choice;

    do
    {
        cout << "\n===== Inventory Menu =====\n";
        cout << "1. Add Inventory Record\n";
        cout << "2. Display Inventory Record (by Item Number)\n";
        cout << "3. Delete Inventory Record (by Item Number)\n";
        cout << "4. Display ALL Inventory Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inv.Addrecord(filename);
            break;
        case 2:
            int itn;
            cout << " Enter the Item Number to Search for Display\n";
            cin >> itn;
            inv.DisplayRecord(filename, itn);
            break;
        case 3:
            int itn1;
            cout << " Enter the Item Number to Delte for REcord\n";
            cin >> itn1;
            inv.DeleteRecord(filename, itn1);
            break;
        case 4:
            inv.DisplayAllRecords(filename);
            break;
        case 5:
            exit(0);
        }
    } while (choice != 5);
}
using namespace std;
int main()
{
    Menu();
    return 0;
}