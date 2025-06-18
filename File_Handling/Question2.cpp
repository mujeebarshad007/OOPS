#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float averageMarks;
};

// Function to enter multiple student records and save to stu.dat
void writeStudentsToFile()
{
    ofstream outFile("stu.dat", ios::binary);
    if (!outFile)
    {
        cout << "Error opening stu.dat for writing!\n";
        return;
    }

    Student s;
    char choice;

    do
    {
        cout << "\nEnter Student ID: ";
        cin >> s.id;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(s.name, 50);

        cout << "Enter Average Marks: ";
        cin >> s.averageMarks;

        outFile.write((char *)&s, sizeof(s));

        cout << "Add another student? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "\nAll student records saved to stu.dat\n";
}

// Function to categorize students based on grade and write to respective files
void classifyStudents()
{
    ifstream inFile("stu.dat", ios::binary);
    if (!inFile)
    {
        cout << "Error opening stu.dat for reading!\n";
        return;
    }

    ofstream gradeA("gradeA.dat", ios::binary);
    ofstream gradeB("gradeB.dat", ios::binary);
    ofstream gradeC("gradeC.dat", ios::binary);
    ofstream gradeF("gradeF.dat", ios::binary);

    int countA = 0, countB = 0, countC = 0, countF = 0;
    Student s;

    while (inFile.read((char *)&s, sizeof(s)))
    {
        if (s.averageMarks >= 80)
        {
            gradeA.write((char *)&s, sizeof(s));
            countA++;
        }
        else if (s.averageMarks >= 60)
        {
            gradeB.write((char *)&s, sizeof(s));
            countB++;
        }
        else if (s.averageMarks >= 50)
        {
            gradeC.write((char *)&s, sizeof(s));
            countC++;
        }
        else
        {
            gradeF.write((char *)&s, sizeof(s));
            countF++;
        }
    }

    inFile.close();
    gradeA.close();
    gradeB.close();
    gradeC.close();
    gradeF.close();

    cout << "\nClassification done!\n";
    cout << "Students with A grade: " << countA << endl;
    cout << "Students with B grade: " << countB << endl;
    cout << "Students with C grade: " << countC << endl;
    cout << "Students with F grade: " << countF << endl;
}

// Function to display students who got F grade
void displayGradeF()
{
    ifstream inFile("gradeF.dat", ios::binary);
    if (!inFile)
    {
        cout << "Error opening gradeF.dat!\n";
        return;
    }

    Student s;
    int count = 1;

    cout << "\nStudents who got F grade:\n";
    cout << "---------------------------\n";
    while (inFile.read((char *)&s, sizeof(s)))
    {
        cout << "Student #" << count++ << endl;
        cout << "ID     : " << s.id << endl;
        cout << "Name   : " << s.name << endl;
        cout << "Marks  : " << s.averageMarks << endl;
        cout << "---------------------------\n";
    }

    inFile.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n========= Student Grade Program =========\n";
        cout << "1. Add Student Records\n";
        cout << "2. Classify Students into Grades\n";
        cout << "3. Display Students with F Grade\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            writeStudentsToFile();
            break;
        case 2:
            classifyStudents();
            break;
        case 3:
            displayGradeF();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
