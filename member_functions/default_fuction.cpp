// Functionn with default arguments
#include <iostream>
using namespace std;
void area(int, int length = 3, int width = 4);
void area(int, int length, int width)
{
    cout << " The Area of the Rectangle is " << length * width;
}
int main()
{
    area(3);
    cout << endl;
    area(5);
    cout << endl;
    area(3, 4);
    cout << endl;
    return 0;
}