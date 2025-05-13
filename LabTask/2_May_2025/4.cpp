#include <iostream>
using namespace std;

template <typename T>
class Shape
{
public:
    virtual T calculateArea() = 0;
};
template <typename T>
class Rectangle : public Shape<T>
{
private:
    T length, width;

public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T calculateArea() override
    {
        return length * width;
    }
};

int main()
{
    Rectangle<int> rectInt(5, 10);

    Rectangle<double> rectDouble(5.5, 10.2);

    Shape<int> *shapePtrInt = &rectInt;
    cout << "Area of Rectangle (int): " << shapePtrInt->calculateArea() << endl;

    Shape<double> *shapePtrDouble = &rectDouble;
    cout << "Area of Rectangle (double): " << shapePtrDouble->calculateArea() << endl;

    return 0;
}
