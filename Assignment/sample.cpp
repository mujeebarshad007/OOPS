/*
 * Smart University Management System
 * Author: Your Name
 * Roll No: Your Roll Number
 * Summary: Implements OOP concepts including inheritance, polymorphism,
 * friend functions, static members, templates, operator overloading,
 * recursion, virtual functions, and virtual inheritance.
 */

#include <iostream>
#include <string>
using namespace std;

// 8. Virtual Base Class to avoid ambiguity
class Person
{
protected:
    string name;
    int id;

public:
    Person(string n = "", int i = 0) : name(n), id(i) {}
    virtual ~Person() {}
};

// 1 & 7. User class inherits virtually from Person, pure virtual displayInfo and calculatePerformance
class User : virtual public Person
{
protected:
    static int totalUsers; // 3. Static variable for total users

public:
    User(string n, int i) : Person(n, i)
    {
        totalUsers++;
    }

    virtual void displayInfo() = 0;            // pure virtual function
    virtual double calculatePerformance() = 0; // pure virtual function

    static int getTotalUsers()
    { // static function to get user count
        return totalUsers;
    }
};
int User::totalUsers = 0;

// 5. Course class with operator overloading
class Course
{
private:
    string courseName;

public:
    Course(string c = "") : courseName(c) {}

    // Overload == operator to compare courses by name
    bool operator==(const Course &other) const
    {
        return courseName == other.courseName;
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &os, const Course &course)
    {
        os << course.courseName;
        return os;
    }

    string getName() const { return courseName; }

    // Friend function to assign course to Student (access private members)
    friend void assignCourse(class Student &, Course &);
};

// 1. Student class derived from User
class Student : public User
{
private:
    double gpa;
    Course *assignedCourse;

public:
    Student(string n, int i, double g) : User(n, i), gpa(g), assignedCourse(nullptr) {}

    void displayInfo() override
    {
        cout << "Student Name: " << name << ", ID: " << id << ", GPA: " << gpa;
        if (assignedCourse)
            cout << ", Course: " << *assignedCourse;
        cout << endl;
    }

    double calculatePerformance() override
    {
        return gpa; // For student, performance is GPA
    }

    friend void assignCourse(Student &student, Course &course);
};

// 1. Professor class derived from User
class Professor : public User
{
private:
    string department;

public:
    Professor(string n, int i, string dept) : User(n, i), department(dept) {}

    void displayInfo() override
    {
        cout << "Professor Name: " << name << ", ID: " << id << ", Dept: " << department << endl;
    }

    double calculatePerformance() override
    {
        // Example: For professor, performance could be fixed or based on dept
        return 75.0; // Dummy fixed performance score
    }
};

// 2. Friend function to assign course to student
void assignCourse(Student &student, Course &course)
{
    student.assignedCourse = &course;
    cout << "Assigned course '" << course.courseName << "' to student " << student.name << endl;
}

// 4. Template class Calculator<T> with recursive GPA calculation
template <typename T>
class Calculator
{
public:
    // Recursive function to compute weighted sum of grades
    static T recursiveGPA(const T *grades, const T *credits, int size)
    {
        if (size == 0)
            return 0;
        return grades[size - 1] * credits[size - 1] + recursiveGPA(grades, credits, size - 1);
    }

    // Operator overloading example: adding two values (not used extensively here)
    T operator+(const T &other)
    {
        return value + other;
    }

    Calculator(T val = 0) : value(val) {}

private:
    T value;
};

// 6. Recursive functions

// Sum of digits of an integer
int sumOfDigits(int num)
{
    if (num == 0)
        return 0;
    return (num % 10) + sumOfDigits(num / 10);
}

// Power calculation (base^exp) using divide and conquer
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

// Simple menu-driven interface (for demonstration)
int main()
{
    cout << "Welcome to Smart University Management System\n";
    cout << "---------------------------------------------\n";

    Student s1("Alice", 101, 3.8);
    Professor p1("Dr. Bob", 201, "Physics");

    Course c1("Calculus");
    Course c2("Physics");

    // Display initial info
    s1.displayInfo();
    p1.displayInfo();

    // Assign course
    assignCourse(s1, c1);

    // Show updated student info
    s1.displayInfo();

    // Show total users count
    cout << "Total users created: " << User::getTotalUsers() << endl;

    // GPA Calculation using Calculator template
    double grades[] = {3.5, 4.0, 2.7, 3.8};
    double credits[] = {3, 4, 2, 3};
    int n = sizeof(grades) / sizeof(grades[0]);

    double weightedSum = Calculator<double>::recursiveGPA(grades, credits, n);
    double totalCredits = 0;
    for (int i = 0; i < n; i++)
        totalCredits += credits[i];

    double gpa = (totalCredits == 0) ? 0 : weightedSum / totalCredits;
    cout << "Calculated GPA: " << gpa << endl;

    // Recursive sum of digits
    int num = 12345;
    cout << "Sum of digits of " << num << " is " << sumOfDigits(num) << endl;

    // Recursive power calculation
    float base = 2.0;
    int exponent = 10;
    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    return 0;
}
