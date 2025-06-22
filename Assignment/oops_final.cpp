#include <iostream>
using namespace std;
#include <cstring>
class Person
{
protected:
    string name;
    int id;

public:
    Person(string n = "", int i = 0) : name(n), id(i) {}
    virtual ~Person() {}

    int getId() const { return id; }
};

class User : virtual public Person
{
protected:
    static int countuser;

public:
    User(string n, int i) : Person(n, i)
    {
        countuser++;
    }
    static int getTotalUsers()
    {
        return countuser;
    }

    virtual void displayInfo() = 0;
    virtual double calculatePerformance() = 0;
};
int User::countuser = 0;

class Course
{
protected:
    string coursename;

public:
    Course(string coursn = "") : coursename(coursn) {}

    bool operator==(const Course &c) const
    {
        return coursename == c.coursename;
    }

    string getName() const { return coursename; } // <-- Added getName()

    friend ostream &operator<<(ostream &os, Course &c)
    {
        os << c.coursename;
        return os;
    }
    friend void assignCourse(class Student &, Course &);
};

class Student : public User
{
private:
    double gpa;
    Course *assignedcourse;

public:
    Student(string name, int id, double g) : User(name, id), gpa(g), assignedcourse(nullptr) {}
    void displayInfo()
    {
        cout << "Student Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
        if (assignedcourse)
        {
            cout << " Course: " << *assignedcourse;
            cout << endl;
        }
    }
    virtual double calculatePerformance()
    {
        return gpa;
    }
    friend void assignCourse(Student &, Course &);
};

void assignCourse(Student &s, Course &c)
{
    s.assignedcourse = &c;
}

class Professor : public User
{
    string department; // changed from salary and rank to department

public:
    Professor(string name, int id, string dept) : User(name, id), department(dept) {}

    void displayInfo()
    {
        cout << "Professor Name: " << name << ", ID: " << id << ", Department: " << department << endl;
    }
    virtual double calculatePerformance()
    {
        return 0; // you can change this as needed
    }
};

int sumofdigits(int a)
{
    if (a == 0)
    {
        return a;
    }
    else
        return a % 10 + sumofdigits(a / 10);
}

float power(float base, int exp)
{
    if (exp == 0)
        return 1;

    float half = power(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

const int MAX_USERS = 5;
Student *students[MAX_USERS];
Professor *professors[MAX_USERS];
Course courses[MAX_USERS];
int studentCount = 0, profCount = 0, courseCount = 0;

// ----- GPA Calculator -----

double calculateGPA(double grades[], double credits[], int size)
{
    double total = 0, totalCredits = 0;
    for (int i = 0; i < size; ++i)
    {
        total += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    return (totalCredits == 0) ? 0 : total / totalCredits;
}

// ----- Main Menu -----

int main()
{
    cout << "Welcome to Smart University Management System\n";
    cout << "---------------------------------------------\n";

    int choice;
    do
    {
        cout << "\n1. Create Student\n2. Create Professor\n3. Assign Course\n4. Calculate GPA\n5. Show User Info\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (studentCount >= MAX_USERS)
            {
                cout << "Limit reached!\n";
                continue;
            }
            string name;
            int id;
            double gpa;
            cout << "Enter name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter GPA: ";
            cin >> gpa;
            students[studentCount++] = new Student(name, id, gpa);
            cout << "Student created.\n";
        }
        else if (choice == 2)
        {
            if (profCount >= MAX_USERS)
            {
                cout << "Limit reached!\n";
                continue;
            }
            string name, dept;
            int id;
            cout << "Enter name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Department: ";
            cin >> ws;
            getline(cin, dept);
            professors[profCount++] = new Professor(name, id, dept);
            cout << "Professor created.\n";
        }
        else if (choice == 3)
        {
            if (studentCount == 0)
            {
                cout << "No students to assign.\n";
                continue;
            }
            int id;
            string cname;
            cout << "Enter student ID: ";
            cin >> id;

            Student *s = nullptr;
            for (int i = 0; i < studentCount; ++i)
            {
                if (students[i]->getId() == id) // <-- Use getter
                {
                    s = students[i];
                    break;
                }
            }

            if (!s)
            {
                cout << "Student not found.\n";
                continue;
            }

            cout << "Enter course name: ";
            cin >> ws;
            getline(cin, cname);
            int index = -1;
            for (int i = 0; i < courseCount; ++i)
            {
                if (courses[i].getName() == cname) // <-- Use getName()
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                if (courseCount >= MAX_USERS)
                {
                    cout << "Course limit reached.\n";
                    continue;
                }
                courses[courseCount] = Course(cname);
                index = courseCount++;
            }

            assignCourse(*s, courses[index]);
        }
        else if (choice == 4)
        {
            double grades[3], credits[3];
            cout << "Enter 3 grades and credits:\n";
            for (int i = 0; i < 3; ++i)
            {
                cout << "Grade " << i + 1 << ": ";
                cin >> grades[i];
                cout << "Credit " << i + 1 << ": ";
                cin >> credits[i];
            }
            double result = calculateGPA(grades, credits, 3);
            cout << "Calculated GPA: " << result << endl;
        }
        else if (choice == 5)
        {
            for (int i = 0; i < studentCount; ++i)
                students[i]->displayInfo();
            for (int i = 0; i < profCount; ++i)
                professors[i]->displayInfo();
        }
        else if (choice == 6)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "Invalid option.\n";
        }

    } while (choice != 6);

    for (int i = 0; i < studentCount; ++i)
        delete students[i];
    for (int i = 0; i < profCount; ++i)
        delete professors[i];

    return 0;
}
