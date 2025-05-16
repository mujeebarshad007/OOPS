#include <iostream>
using namespace std;
class Book
{
    string title;
    double price;

public:
    Book(string title, double price)
    {
        this->title = title;
        this->price = price;
    }
    void display() const
    {
        cout << " The Title is " << this->title << endl;
        cout << " The Price is " << this->price << endl;
    }

    double getPrice() const
    {
        return this->price;
    }

    string gettitle() const
    {
        return this->title;
    }
    void applyDiscount(double discount, const Book &book)
    {
        double originalPrice = book.getPrice();

        double discountedPrice = originalPrice * (1.0 - discount); // e.g. 50 * 0.9 = 45

        cout << "\nDiscounted Price of \"" << book.gettitle() << "\": $" << discountedPrice << endl;
    }
};
int main()
{
    const double discountrate = 0.10;
    Book b("C++ Programming", 50.00);
    b.display();
    b.applyDiscount(discountrate, b);
    return 0;
}