#include <iostream>

using namespace std;
class Engine
{
public:
    double horsep;
    double fuelc;
    Engine(double horsepower, double fuelconsumption)
    {
        horsep = horsepower;
        fuelc = fuelconsumption;
    }
};
class Car
{
public:
    double fuelneeded;
    double f_price = 1.50;
    string modelname;
    Engine e;
    void show()
    {
        double distance;
        cout << " Enter the Distance " << endl;
        cin >> distance;
        fuelneeded = distance * e.fuelc;
        cout << " Fuel Needed For the trip is " << fuelneeded << endl;
        cout << " The Trip Cost is " << fuelneeded * f_price << endl;
    }
};
int main()
{
    return 0;
}