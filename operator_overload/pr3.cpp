#include <iostream>
using namespace std;
class Complex
{
public:
    int real;
    int imag;

    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex operator+(Complex &a1)
    {
        Complex a2;
        a2.real = this->real + a1.real;
        a2.imag = this->imag + a1.imag;
        return a2;
    }
    Complex operator-(Complex &a3)
    {
        Complex a4;
        a4.real = this->real - a3.real;
        a4.imag = this->imag - a3.imag;
        return a4;
    }
    Complex operator*(Complex &a5)
    {
        Complex a6;
        a6.real = this->real * a5.real;
        a6.imag = this->imag * a5.imag;
        return a6;
    }
};
int main()
{
    Complex c1(2, 30);
    Complex c2(3, 5);
    Complex c3, c4, c5;
    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    cout << " The Addition Operator Result is " << c3.real << " + " << c3.imag << " i " << endl;
    cout << " The Subtraction Operator Result is " << c4.real << " + " << c4.imag << " i " << endl;
    cout << " The Multipilication Operator Result is " << c5.real << " + " << c5.imag << " i " << endl;

    return 0;
}