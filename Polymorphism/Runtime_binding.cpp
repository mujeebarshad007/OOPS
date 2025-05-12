#include <iostream>
using namespace std;
int main()
{
    return 0;
}

class Shape
{
public:
    virtual void Draw()
    {
        cout << "Drawing a shape." << endl;
    }
};

class Rectangle : public Shape
{
public:
    void Draw()
    {
        cout << "Drawing a rectangle." << endl;
    }
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout << "Drawing a circle." << endl;
    }
};

int main()
{
    Shape *shape1 = new Rectangle();
    Shape *shape2 = new Circle();
    shape1->Draw(); // Output: "Drawing a rectangle."
    shape2->Draw(); // Output: "Drawing a circle."
    return 0;
}
