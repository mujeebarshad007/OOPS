#include <iostream>
using namespace std;
class Thermometer
{
    double temperatureCelsius;

public:
    Thermometer(double c)
    {
        temperatureCelsius = c;
    }
    friend double showFahrenheit(Thermometer &t);
};
class Convert
{
public:
    double Convert_it(Thermometer &t)
    {

        return showFahrenheit(t);
    }
};
double showFahrenheit(Thermometer &t)
{
    double farhenheit;
    farhenheit = (t.temperatureCelsius * 1.8) + 32;
    return farhenheit;
}

int main()
{
    Thermometer r(98);
    Convert c;

    cout << " The Farhenheight of this temperature is " << c.Convert_it(r) << "F" << endl;

    return 0;
}