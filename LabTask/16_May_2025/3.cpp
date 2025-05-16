#include <iostream>
using namespace std;

class BasicTicket
{
public:
    string p_name;
    string d_city;
    string a_city;
    int f_number;
    double t_price;

    BasicTicket(string p, string d, string a, int f, double t)
    {
        p_name = p;
        d_city = d;
        a_city = a;
        f_number = f;
        t_price = t;
    }

    double getPrice()
    {
        return t_price;
    }
};

class PremiumTicket : public BasicTicket
{
public:
    int ps_number;

    PremiumTicket(string p, string d, string a, int f, double t, int ps)
        : BasicTicket(p, d, a, f, t)
    {
        ps_number = ps;
    }

    double getPrice()
    {
        return BasicTicket::getPrice() * 1.10;
    }
};

int main()
{
    BasicTicket bt("Ali", "Lahore", "Karachi", 1001, 5000);
    PremiumTicket pt("Sara", "Islamabad", "Dubai", 2002, 8000, 12);

    cout << "--- Basic Ticket ---" << endl;
    cout << "Passenger: " << bt.p_name << endl;
    cout << "Price: " << bt.getPrice() << endl;

    cout << "\n--- Premium Ticket ---" << endl;
    cout << "Passenger: " << pt.p_name << endl;
    cout << "Seat No: " << pt.ps_number << endl;
    cout << "Price: " << pt.getPrice() << endl;

    return 0;
}
