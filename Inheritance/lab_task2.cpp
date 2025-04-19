#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
public:
    double x1;
    double y1;
    double x2;
    double y2;

    Shape(double x1, double y1, double x2, double y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    double distance()
    {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }
    virtual void displayDetails()
    {
        cout << "Details are displayed in the base class" << endl;
    }
};
class Color
{
    string color;
    string setColor(string color)
    {
        this->color = color;
    }
};
int main()
{
    return 0;
}