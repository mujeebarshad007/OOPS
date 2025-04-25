#include <iostream>
using namespace std;
class Thermometer
{
private:
    double temperatureCelsius;

public:
    Thermometer(double c)
    {
        temperatureCelsius = c;
    }
    friend void showFahrenheit(Thermometer &t);
};
class Convert
{
public:
    void Convert_it(Thermometer &t)
    {
        showFahrenheit(t);
    }
};
void showFahrenheit(Thermometer &t)
{
    double result;
    result = (t.temperatureCelsius * 1.8) + 32;
    cout << " The Converted Farhenheit Temperature is " << result << endl;
}
int main()
{
    Thermometer t(98);
    Convert c;
    c.Convert_it(t);
    return 0;
}