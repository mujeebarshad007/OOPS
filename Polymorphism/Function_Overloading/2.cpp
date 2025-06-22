#include <iostream>
#include <cstring>
using namespace std;
class BT
{
public:
      string name, d_city, a_city;
      double f_number, t_price;
      BT(string name, string d_city, string a_city, double f_number, double t_price) : name(name), d_city(d_city), a_city(a_city), f_number(f_number), t_price(t_price) {}
      double getPrice()
      {
            return t_price;
      }
};
class PT : public BT
{
public:
      int s_number;
      PT(string name, string d_city, string a_city, double f_number, double t_price, int s_number) : BT(name, d_city, a_city, f_number, t_price), s_number(s_number) {}
      double getPrice() {};
};
double PT::getPrice()
{
      return BT::getPrice() * 1.10;
}
int main()
{
      BT b("Ali", "Multan", "Islamabad", 10, 100);
      PT p("usman", "Lahore", "KBW", 17, 100, 89);

      cout << p.getPrice() << endl;
      return 0;
}