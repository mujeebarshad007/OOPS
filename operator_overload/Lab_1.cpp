#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double area() = 0;
};
class Circle : public Shape
{
public:
    double radius;
    double result;
    Circle(double r)
    {
        radius = r;
    }
    double area()
    {
        result = 3.1416 * radius * radius;
        return result;
    }
};
class Rectangle : public Shape
{
public:
    double length;
    double width;
    double r;
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        r = length * width;
        return r;
    }
};

int main()
{
    Circle c(2);
    cout << c.area() << endl;
    Rectangle r(2, 4);
    cout << r.area() << endl;

    return 0;
}