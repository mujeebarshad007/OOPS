#include <iostream>
using namespace std;
int calculate(int a, int b)
{
    return a + b;
}

int calculate(int a, int b, int c)
{
    return (a * b * c);
}

float calculate(float a, float b)
{
    return (a + b) / 2;
}

int main()
{
    int a1, b1, c1;
    a1 = 2.1;
    b1 = 3.3;
    c1 = 6;

    cout << " The Sum of the numbers is " << calculate(a1, b1) << endl;
    cout << " The Product of the numbers is " << calculate(a1, b1, c1) << endl;
    cout << " The average of the numbers is " << calculate((float)a1, (float)b1) << endl;

    return 0;
}