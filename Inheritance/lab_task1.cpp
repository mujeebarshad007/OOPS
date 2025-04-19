#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
public:
    int x;
    int y;
    int x2;
    int y2;
    int l;
    int w;
    void setpoints(int x, int y, int x2, int y2)
    {
        this->x = x;
        this->y = y;
        this->x2 = x2;
        this->y2 = y2;
    }

    double distance()
    {
        return sqrt(pow((x2 - x), 2) + pow((y2 - y), 2));
    }
    virtual void displaydetails()
    {
        cout << " Details are displayed in the base class" << endl;
    }
};
class Rectangle : public Shape
{
public:
    void setArea(int l, int w)
    {
        this->l = l;
        this->w = w;
    }

    double area()
    {
        return (l * w);
    }
    double Preimeter()
    {
        return (2 * (l + w));
    }

    void displaydetails()
    {
        cout << "Area of the rectangle is: " << area() << endl;
        cout << "Perimeter of the rectangle is: " << Preimeter() << endl;
        cout << "Distance between two points is: " << distance() << endl;
    }
};
int main()
{
    Rectangle r;
    r.setpoints(5, 1, 20, 10);
    r.setArea(20, 40);
    r.displaydetails();
    return 0;
}