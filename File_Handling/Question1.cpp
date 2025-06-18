#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee
{
    int emp_ID;
    float emp_salary;
    char emp_name[50];
};

const char *filename = "employee.dat";

void addEmployees()
{
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout)
    {
        cout << "Error opening file.\n";
        return;
    }

    Employee e;
    char choice;

    do
    {
        cout << "Enter ID: ";
        cin >> e.emp_ID;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(e.emp_name, 50);
        cout << "Enter Salary: ";
        cin >> e.emp_salary;

        fout.write((char *)&e, sizeof(e));

        cout << "Add another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    fout.close();
    cout << "Employees added successfully!\n";
}

void displayAll()
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Error opening file.\n";
        return;
    }

    Employee e;
    int count = 1;
    while (fin.read((char *)&e, sizeof(e)))
    {
        cout << "\nEmployee #" << count++;
        cout << "\nID     : " << e.emp_ID;
        cout << "\nName   : " << e.emp_name;
        cout << "\nSalary : " << e.emp_salary;
        cout << "\n---------------------------";
    }
    fin.close();
}

void find()
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Error opening file.\n";
        return;
    }

    int id;
    bool found = false;
    cout << "Enter ID to search: ";
    cin >> id;

    Employee e;
    while (fin.read((char *)&e, sizeof(e)))
    {
        if (e.emp_ID == id)
        {
            cout << "\nRecord Found!";
            cout << "\nID     : " << e.emp_ID;
            cout << "\nName   : " << e.emp_name;
            cout << "\nSalary : " << e.emp_salary << "\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Record not found.\n";
    }

    fin.close();
}

void modify()
{
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    int id;
    cout << "Enter ID to modify: ";
    cin >> id;

    Employee e;
    bool found = false;
    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.emp_ID == id)
        {
            cout << "\nEnter new details:\n";
            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(e.emp_name, 50);
            cout << "Enter Salary: ";
            cin >> e.emp_salary;

            file.seekp(-sizeof(e), ios::cur); // move back to current record
            file.write((char *)&e, sizeof(e));
            found = true;
            cout << "Record modified successfully.\n";
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

void insert()
{
    ifstream fin(filename, ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin || !fout)
    {
        cout << "File error.\n";
        return;
    }

    int pos;
    cout << "Enter position to insert (0 = beginning): ";
    cin >> pos;

    Employee e, newEmp;
    cout << "Enter new employee details:\n";
    cout << "Enter ID: ";
    cin >> newEmp.emp_ID;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(newEmp.emp_name, 50);
    cout << "Enter Salary: ";
    cin >> newEmp.emp_salary;

    int i = 0;
    while (fin.read((char *)&e, sizeof(e)))
    {
        if (i == pos)
            fout.write((char *)&newEmp, sizeof(newEmp));
        fout.write((char *)&e, sizeof(e));
        i++;
    }
    if (pos >= i) // If inserting at the end
        fout.write((char *)&newEmp, sizeof(newEmp));

    fin.close();
    fout.close();

    remove(filename);
    rename("temp.dat", filename);
    cout << "Record inserted.\n";
}

void deleteRecord()
{
    ifstream fin(filename, ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin || !fout)
    {
        cout << "File error.\n";
        return;
    }

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    Employee e;
    bool found = false;
    while (fin.read((char *)&e, sizeof(e)))
    {
        if (e.emp_ID == id)
        {
            found = true;
            continue; // skip writing this record
        }
        fout.write((char *)&e, sizeof(e));
    }

    fin.close();
    fout.close();
    remove(filename);
    rename("temp.dat", filename);

    if (found)
        cout << "Record deleted.\n";
    else
        cout << "Record not found.\n";
}

void sort()
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "File error.\n";
        return;
    }

    Employee arr[100];
    int n = 0;
    while (fin.read((char *)&arr[n], sizeof(Employee)))
    {
        n++;
    }
    fin.close();

    // Simple Bubble Sort by salary
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].emp_salary > arr[j + 1].emp_salary)
            {
                Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    ofstream fout(filename, ios::binary);
    for (int i = 0; i < n; i++)
    {
        fout.write((char *)&arr[i], sizeof(Employee));
    }
    fout.close();
    cout << "Records sorted by salary.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n===== Employee Menu =====";
        cout << "\n1. Add Employees";
        cout << "\n2. Display All";
        cout << "\n3. Find by ID";
        cout << "\n4. Modify by ID";
        cout << "\n5. Insert at Position";
        cout << "\n6. Delete by ID";
        cout << "\n7. Sort by Salary";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployees();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            find();
            break;
        case 4:
            modify();
            break;
        case 5:
            insert();
            break;
        case 6:
            deleteRecord();
            break;
        case 7:
            sort();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
