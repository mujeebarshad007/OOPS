#include <iostream>
#include <stdexcept>  
#include <cmath>      
using namespace std;


int safeSubtract(int a, int b) {
    int result = a - b;
    if (result < 0) {
        throw underflow_error("Underflow error: Result is negative!");
    }
    return result;
}

int main() {
    int a, b;
    cout << "Nested Exceptions: Safe Subtraction\n";
    cout << "Enter first number (a): ";
    cin >> a;
    cout << "Enter second number (b): ";
    cin >> b;

    try {
        try {
            int result = safeSubtract(a, b);
            cout << "Safe subtraction result: " << result << endl;
        }
        catch (const underflow_error& e) {
            cerr << "Inner catch block: " << e.what() << endl;

           
            cout << "Fallback result (0): " << 0 << endl;

           
            int absDiff = abs(a - b);
            cout << "Extension fallback (|a - b|): " << absDiff << endl;
        }
    }
    catch (...) {
        cerr << "Outer catch block: An unexpected error occurred." << endl;
    }

    return 0;
}
