// C++ OOP Lab Tasks - Simple Code Without Vectors
#include <iostream>
#include <string>
using namespace std;

// ------------------- Question 1: Association -------------------
class Test;

class Student
{
public:
    string name;
    int roll;
    Test *tests[4];
    int testCount;

    Student(string n, int r)
    {
        name = n;
        roll = r;
        testCount = 0;
    }

    void addTest(Test *t);
    void showPerformance();
};

class Test
{
public:
    string subject;
    int marks;

    Test(string s, int m)
    {
        subject = s;
        marks = m;
    }
};

void Student::addTest(Test *t)
{
    if (testCount < 4)
    {
        tests[testCount++] = t;
    }
}

void Student::showPerformance()
{
    int total = 0, passed = 0, highest = 0, lowest = 100;
    for (int i = 0; i < testCount; i++)
    {
        int m = tests[i]->marks;
        total += m;
        if (m >= 40)
            passed++;
        if (m > highest)
            highest = m;
        if (m < lowest)
            lowest = m;
    }
    float avg = (float)total / testCount;
    float percentage = ((float)total / (testCount * 100)) * 100;
    cout << "Student: " << name << ", Roll: " << roll << endl;
    cout << "Average: " << avg << ", Percentage: " << percentage << "%" << endl;
    cout << "Highest: " << highest << ", Lowest: " << lowest << endl;
    cout << "Passed Tests: " << passed << "\n\n";
}

// ------------------- Question 2: Composition -------------------
class Engine
{
public:
    int horsepower;
    float consumption; // per km

    Engine(int hp, float c)
    {
        horsepower = hp;
        consumption = c;
    }
};

class Car
{
public:
    string model;
    Engine engine;

    Car(string m, int hp, float c) : engine(hp, c)
    {
        model = m;
    }

    void fuelCost(float distance, float price)
    {
        float fuel = distance * engine.consumption;
        float cost = fuel * price;
        float efficiency = 100 / (engine.consumption * 100);
        cout << "Model: " << model << ", Fuel Needed: " << fuel << "L, Cost: $" << cost;
        cout << ", Efficiency: " << efficiency << " km/L\n";
    }
};

// ------------------- Question 3: Aggregation -------------------
class Book
{
public:
    string title, author;
    float price;
    int pages;

    Book(string t, string a, float p, int pg)
    {
        title = t;
        author = a;
        price = p;
        pages = pg;
    }
};

class Library
{
public:
    string name;
    Book *books[6];
    int bookCount;

    Library(string n)
    {
        name = n;
        bookCount = 0;
    }

    void addBook(Book *b)
    {
        if (bookCount < 6)
        {
            books[bookCount++] = b;
        }
    }

    void stats()
    {
        float total = 0;
        int totalPages = 0;
        float avgPrice;
        float most = 0, least = 99999;
        for (int i = 0; i < bookCount; i++)
        {
            total += books[i]->price;
            totalPages += books[i]->pages;
            if (books[i]->price > most)
                most = books[i]->price;
            if (books[i]->price < least)
                least = books[i]->price;
        }
        avgPrice = total / bookCount;
        cout << "Library: " << name << endl;
        cout << "Total Value: $" << total << ", Average Price: $" << avgPrice;
        cout << ", Average Pages: " << (totalPages / bookCount) << endl;
        cout << "Most Expensive: $" << most << ", Least Expensive: $" << least << "\n\n";
    }
};

// ------------------- Question 4: Mixed Relationships -------------------
class ReportCard
{
public:
    int marks[3];

    ReportCard(int m1, int m2, int m3)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float average()
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    char grade()
    {
        float avg = average();
        if (avg >= 90)
            return 'A';
        else if (avg >= 80)
            return 'B';
        else if (avg >= 70)
            return 'C';
        else if (avg >= 60)
            return 'D';
        else
            return 'F';
    }
};

class MixedStudent; // forward declaration

class Teacher
{
public:
    string name;
    MixedStudent *students[4];
    int count;

    Teacher(string n)
    {
        name = n;
        count = 0;
    }

    void addStudent(MixedStudent *s);
    void showWorkload();
};

class MixedStudent
{
public:
    string name;
    ReportCard report;

    MixedStudent(string n, int m1, int m2, int m3) : report(m1, m2, m3)
    {
        name = n;
    }

    void show()
    {
        cout << "Student: " << name << ", Average: " << report.average() << ", Grade: " << report.grade() << endl;
    }
};

void Teacher::addStudent(MixedStudent *s)
{
    if (count < 4)
    {
        students[count++] = s;
    }
}

void Teacher::showWorkload()
{
    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += students[i]->report.average();
    }
    cout << "Teacher: " << name << ", Students: " << count << ", Class Avg: " << (total / count) << endl;
}

int main()
{
    // Question 1
    Test t1("Math", 85), t2("Science", 45), t3("English", 75), t4("History", 30);
    Student s1("Ali", 1), s2("Sara", 2), s3("Omar", 3);
    s1.addTest(&t1);
    s1.addTest(&t2);
    s2.addTest(&t2);
    s2.addTest(&t3);
    s3.addTest(&t3);
    s3.addTest(&t4);
    s1.showPerformance();
    s2.showPerformance();
    s3.showPerformance();

    // Question 2
    Car c1("Toyota", 100, 0.07), c2("Honda", 90, 0.05);
    c1.fuelCost(200, 1.5);
    c2.fuelCost(200, 1.5);

    // Question 3
    Book b1("Book1", "Author1", 20, 200), b2("Book2", "Author2", 30, 150),
        b3("Book3", "Author3", 25, 180), b4("Book4", "Author4", 15, 120),
        b5("Book5", "Author5", 22, 140), b6("Book6", "Author6", 28, 160);
    Library lib("City Library");
    lib.addBook(&b1);
    lib.addBook(&b2);
    lib.addBook(&b3);
    lib.addBook(&b4);
    lib.addBook(&b5);
    lib.addBook(&b6);
    lib.stats();

    // Question 4

    MixedStudent ms1("Ayesha", 85, 90, 95), ms2("Hamza", 70, 65, 60), ms3("Nida", 75, 85, 80), ms4("Ali", 50, 55, 60);
    Teacher teacher1("Mr. Ahmad"), teacher2("Ms. Fatima");

    teacher1.addStudent(&ms1);
    teacher1.addStudent(&ms2);
    teacher2.addStudent(&ms3);
    teacher2.addStudent(&ms4);

    ms1.show();
    ms2.show();
    ms3.show();
    ms4.show();

    teacher1.showWorkload();
    teacher2.showWorkload();

    return 0;
}
