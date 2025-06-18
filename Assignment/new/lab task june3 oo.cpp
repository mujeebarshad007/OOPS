#include <iostream>
#include <exception>
#include <cmath> 

using namespace std;


class OddNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Odd numbers not allowed!";
    }
};


int sumEvenNumbers(int a, int b) {
    if (a % 2 != 0 || b % 2 != 0) {
        throw OddNumberException();
    }
    return a + b;
}

int main() {
    int a, b;
    cout << "Custom Exception: Odd-Even Sum\n";
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    try {
        int result = sumEvenNumbers(a, b);
        cout << "Sum of even numbers: " << result << endl;
    }
    catch (const OddNumberException& e) {
        cerr << e.what() << endl;

       
        int fallbackSum = abs(a) + abs(b);
        cout << "Fallback sum (absolute values): " << fallbackSum << endl;
    }

    return 0;
}
