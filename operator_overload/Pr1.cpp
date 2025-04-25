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
    Circle(double radius)
    {
        this->radius = radius;
    }
    double area()
    {
        return 3.1416 * radius * radius;
    }
};
class rectangle : public Shape
{
public:
    double length, width;
    rectangle(double length, double width)
    {
        this->length = length;
        this->width = width;
    }
    double area()
    {
        return length * width;
    }
};
int main()
{
    Circle c(10);
    cout << " The Area of this Circle is " << c.area() << endl;
    rectangle r(20, 30);
    cout << " The Area of this Rectangle is " << r.area() << endl;
    return 0;
}