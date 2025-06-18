#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) {
        throw "Error: Division by zero!";
    }
    return static_cast<double>(a) / b;
}

int main() {
    int a, b;
    cout << "Task 1: Safe Division\n";
    cout << "Enter numerator: ";
    cin >> a;
    cout << "Enter denominator: ";
    cin >> b;

    try {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    }
    catch (const char* errorMsg) {
        cerr << errorMsg << endl;

      
        if (b == 0) {
            cout << "Attempting fallback with b + 1 = " << (b + 1) << endl;
            try {
                double fallbackResult = divide(a, b + 1);
                cout << "Fallback Result: " << fallbackResult << endl;
            }
            catch (...) {
                cerr << "Fallback also failed!" << endl;
            }
        }
    }

    return 0;
}
