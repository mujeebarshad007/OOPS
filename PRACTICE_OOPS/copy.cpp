#include <iostream>
using namespace std;
class car
{
public:
    string model;
    int seats;
    float price;

    car(string model, int seats, float price)
    {
        this->model = model;
        this->seats = seats;
        this->price = price;
    }

    void display() const
    {
        cout << " model\t Seats \t Price" << endl;
        cout << this->model << "\t" << this->seats << "\t" << this->price << endl;
    }

    car(const car &copy)
    {
        this->model = copy.model;
        this->seats = copy.seats;
        this->price = copy.price;
    }
};
int main()
{
    car c1("Bmw", 5, 52.7);
    car c2(c1);
    c1.display();
    c2.display();
    return 0;
}