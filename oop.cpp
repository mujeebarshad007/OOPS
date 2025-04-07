#include <iostream>
using namespace std;
class Employee
{
public:
    int x;
};
int main()
{
    Employee a;
    int v = a.x = 10;
    cout << v << endl;
    return 0;
}
