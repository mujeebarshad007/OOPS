#include <iostream>
using namespace std;
class Complex
{
public:
    int real, imaginary;

    Complex(int r, int i)
    {
        this->real = r;
        this->imaginary = i;
    }
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    Complex operator+(Complex &c2)
    {
        Complex c3;
        c3.real = this->real + c2.real;
        c3.imaginary = this->imaginary + c2.imaginary;
        return c3;
    }
    Complex operator-(Complex &c5)
    {
        Complex c4;
        c4.real = this->real - c5.real;
        c4.imaginary = this->imaginary - c5.imaginary;
        return c4;
    }
    Complex operator*(Complex &c7)
    {
        Complex c6;
        c6.real = this->real * c7.real;
        c6.imaginary = this->imaginary * c7.imaginary;
        return c6;
    }
};

int main()
{
    Complex c1(5, 9);
    Complex c2(3, 5);
    Complex c3;
    Complex c4;
    Complex c6;
    c3 = c1 + c2;
    c4 = c1 - c2;
    c6 = c1 * c2;

    cout << " The Plus Overloaded Operator Answer is " << c3.real << "+" << c3.imaginary << "i" << endl;
    cout << " The Subtract Overloaded Operator Answer is " << c4.real << "+" << c4.imaginary << "i" << endl;
    cout << " The Star Overloaded Operator Answer is " << c6.real << "+" << c6.imaginary << "i" << endl;
    return 0;
}