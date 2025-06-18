// MUJEEB ARSHAD
// 04072413034
// This Project is used to make a smart university system
// in which we can store students and professors using classes and
// we can assign course calculate gpa as well also

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    string name;
    int id;

public:
    Person(string n = "", int i = 0) : name(n), id(i) {}
    virtual ~Person() {}

    int getId() const { return id; } // Added getter for id
};

class User : virtual public Person // using virtual to avoid the diamond problem
{
protected:
    static int countuser; // countuser to count total users

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

    string getName() const { return coursename; }

    friend ostream &operator<<(ostream &os, Course &c)
    {
        os << c.coursename;
        return os;
    }
    friend void assignCourse(class Student &, Course &); // telling compiler that here is a friend function
};

class Student : public User
{
private:
    double gpa;
    Course *assignedcourse;

public:
    Student(string name, int id, double g) : Person(name, id), User(name, id), gpa(g), assignedcourse(nullptr) {}

    void displayInfo()
    {
        cout << "\n--- Student Info ---\n";
        cout << "Name       : " << name << endl;
        cout << "ID         : " << id << endl;
        cout << "GPA        : " << gpa << endl;
        if (assignedcourse)
            cout << "Course     : " << assignedcourse->getName() << endl;
        else
            cout << "Course     : Not assigned\n";
        cout << "---------------------\n";
    }

    virtual double calculatePerformance()
    {
        return gpa;
    }
    friend void assignCourse(Student &, Course &); // again telling compiler that there is a freind function here
};

void assignCourse(Student &s, Course &c)
{
    s.assignedcourse = &c;
}

class Professor : public User
{
    string department;

public:
    Professor(string name, int id, string dept) : Person(name, id), User(name, id), department(dept) {}

    void displayInfo() override
    {
        cout << "\n--- Professor Info ---\n";
        cout << "Name       : " << name << endl;
        cout << "ID         : " << id << endl;
        cout << "Department : " << department << endl;
        cout << "------------------------\n";
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
const int MAX_USERS = 5; // taking sample users
Student *students[MAX_USERS];
Professor *professors[MAX_USERS];
Course courses[MAX_USERS];
int studentCount = 0, profCount = 0, courseCount = 0;

//  GPA Calculator recursion code

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

int main()
{
    int ex, digits;
    float bs;
    cout << "Welcome to Smart University Management System\n";
    cout << "---------------------------------------------\n";

    int choice;
    do
    {
        // system("clear");
        cout << "1. Create Student" << endl;
        cout << "2. Create Professor" << endl;
        cout << "3. Assign Course" << endl;
        cout << "4. Calculate GPA" << endl;
        cout << "5. Show User Info" << endl;
        cout << "6. Find Power" << endl;
        cout << "7. Find Sum of Digits" << endl;
        cout << "8. Exit" << endl;
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
            cin >> name;
            cin.ignore();
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
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
            cin >> name;
            cin.ignore();
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Department: ";
            cin >> dept;
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
            cout << " Enter the base " << endl;
            cin >> bs;
            cout << " Enter the exponent  " << endl;
            cin >> ex;
            cout << " The Result is " << power(bs, ex) << endl;
        }
        else if (choice == 7)
        {
            cout << " Enter The Number to Find Digits Sum " << endl;
            cin >> digits;
            cout << " The Sum Of the digits is " << sumofdigits(digits) << endl;
        }
        else if (choice == 8)
        {
            cout << "Thank you !\n";
        }
        else
        {
            cout << "Invalid option.\n";
        }

    } while (choice != 8);

    for (int i = 0; i < studentCount; ++i)
        delete students[i];
    for (int i = 0; i < profCount; ++i)
        delete professors[i];

    return 0;
}
