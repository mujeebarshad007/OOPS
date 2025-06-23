#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;
    int arr[2]; // for [] operator

public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i)
    {
        arr[0] = feet;
        arr[1] = inches;
    }

    // Addition +
    Distance operator+(const Distance &d)
    {
        return Distance(feet + d.feet, inches + d.inches);
    }

    // Subtraction -
    Distance operator-(const Distance &d)
    {
        return Distance(feet - d.feet, inches - d.inches);
    }

    // Multiplication *
    Distance operator*(int factor)
    {
        return Distance(feet * factor, inches * factor);
    }

    // Division /
    Distance operator/(int divisor)
    {
        return Distance(feet / divisor, inches / divisor);
    }

    // Equality ==
    bool operator==(const Distance &d)
    {
        return (feet == d.feet && inches == d.inches);
    }

    // Not Equal !=
    bool operator!=(const Distance &d)
    {
        return !(*this == d);
    }

    // Greater than >
    bool operator>(const Distance &d)
    {
        return (feet > d.feet) || (feet == d.feet && inches > d.inches);
    }

    // Less than <
    bool operator<(const Distance &d)
    {
        return (feet < d.feet) || (feet == d.feet && inches < d.inches);
    }

    // Greater than or equal >=
    bool operator>=(const Distance &d)
    {
        return !(*this < d);
    }

    // Less than or equal <=
    bool operator<=(const Distance &d)
    {
        return !(*this > d);
    }

    // Assignment =
    Distance &operator=(const Distance &d)
    {
        if (this != &d)
        {
            feet = d.feet;
            inches = d.inches;
        }
        return *this;
    }

    // Subscript []
    int &operator[](int index)
    {
        return arr[index];
    }

    // Function call ()
    void operator()()
    {
        cout << "Object called like a function!" << endl;
    }

    // Pre-increment ++
    Distance &operator++()
    {
        ++feet;
        return *this;
    }

    // Post-increment ++
    Distance operator++(int)
    {
        Distance temp = *this;
        feet++;
        return temp;
    }

    // Pre-decrement --
    Distance &operator--()
    {
        --feet;
        return *this;
    }

    // Post-decrement --
    Distance operator--(int)
    {
        Distance temp = *this;
        feet--;
        return temp;
    }

    // Friend insertion operator <<
    friend ostream &operator<<(ostream &out, const Distance &d);

    // Friend extraction operator >>
    friend istream &operator>>(istream &in, Distance &d);
};

// << operator
ostream &operator<<(ostream &out, const Distance &d)
{
    out << d.feet << "' " << d.inches << "''";
    return out;
}

// >> operator
istream &operator>>(istream &in, Distance &d)
{
    in >> d.feet >> d.inches;
    return in;
}

// Main function
int main()
{
    Distance d1(5, 8), d2(3, 4), d3;

    cout << "D1: " << d1 << "\n";
    cout << "D2: " << d2 << "\n";

    d3 = d1 + d2;
    cout << "D1 + D2 = " << d3 << "\n";

    d3 = d1 - d2;
    cout << "D1 - D2 = " << d3 << "\n";

    d3 = d1 * 2;
    cout << "D1 * 2 = " << d3 << "\n";

    d3 = d1 / 2;
    cout << "D1 / 2 = " << d3 << "\n";

    cout << "Are D1 and D2 equal? " << (d1 == d2 ? "Yes" : "No") << "\n";

    ++d1;
    cout << "++D1 = " << d1 << "\n";

    d1++;
    cout << "D1++ = " << d1 << "\n";

    --d1;
    cout << "--D1 = " << d1 << "\n";

    d1--;
    cout << "D1-- = " << d1 << "\n";

    cout << "Access using []: " << d1[0] << " feet, " << d1[1] << " inches\n";

    d1(); // function call
    return 0;
}
