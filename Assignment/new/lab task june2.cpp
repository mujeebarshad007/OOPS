#include <iostream>
#include <stdexcept> 
#include <cmath>      
using namespace std;


double calculateArea(double length, double width) {
    if (length <= 0 || width <= 0) {
        throw invalid_argument("Error: Length and width must be greater than 0!");
    }
    return length * width;
}

int main() {
    double length, width;
    cout << "\nTask 2: Area of Rectangle\n";
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    try {
        double area = calculateArea(length, width);
        cout << "Area: " << area << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;

      
        double fallbackArea = abs(length) * abs(width);
        cout << "Using absolute values...\n";
        cout << "Corrected Area: " << fallbackArea << endl;
    }

    return 0;
}
