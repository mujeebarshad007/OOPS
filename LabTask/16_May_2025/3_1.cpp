#include <iostream>
using namespace std;
class BasicTicket
{
public:
    string p_name;
    string d_city;
    string a_city;
    int f_number;
    int t_price;
    BasicTicket(string p, string d, string a, int f, int t)
    {
        p_name = p;
        d_city = d;
        a_city = a;
        f_number = f;
        t_price = t;
    }
    int getPrice()
    {
        return t_price;
    }
};
class PremiumTicket : public BasicTicket
{
public:
    int s_number;
    PremiumTicket(string p, string d, string a, int f, int t, int sn) : BasicTicket(p, d, a, f, t)
    {
        s_number = sn;
    }
    int getPrice()
    {
        return BasicTicket::getPrice() * 1.10;
    }
};
int main()
{
    BasicTicket bt("Mujeeb", "Multan", "Islamabad", 1001, 5000);
    PremiumTicket pt("Yums", "Islamabad", "Multan", 2002, 8000, 12);

    cout << "--- Basic Ticket ---" << endl;
    cout << "Passenger: " << bt.p_name << endl;
    cout << "Price: " << bt.getPrice() << endl;

    cout << "\n--- Premium Ticket ---" << endl;
    cout << "Passenger: " << pt.p_name << endl;
    cout << "Seat No: " << pt.s_number << endl;
    cout << "Price: " << pt.getPrice() << endl;
    return 0;
}