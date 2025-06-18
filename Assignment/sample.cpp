#include <iostream>
using namespace std;

float power(float base, int exp)
{
    if (exp == 0)
        return 1;

    float half = power(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main()
{
    float base = 2;
    int exponent = 2;

    float result = power(base, exponent);

    cout << "Result: " << result << endl;

    return 0;
}
