#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

double calculateArea(double length, double width)
{
    if (length <= 0 || width <= 0)
    {
        throw invalid_argument("Invalid input: length and width must be positive");
    }
    return length * width;
}

int main()
{
    double l = -5, w = 4;
    try
    {
        double area = calculateArea(l, w);
        cout << "Area: " << area << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        cout << "Using absolute values for fallback..." << endl;
        double fallbackArea = abs(l) * abs(w);
        cout << "Fallback Area: " << fallbackArea << endl;
    }
    return 0;
}
