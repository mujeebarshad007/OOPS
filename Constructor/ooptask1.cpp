#include <iostream>
using namespace std;
class Counter
{
public:
    int count;
    Counter()
    {
        cout << "Default Constructor Called" << endl;
        count = 0;
        cout << "Count initialized to 0" << endl;
    }
    Counter(int c)
    {
        if (count < 0)
        {
            cout << "Count cannot be negative" << endl;
            count = 0;
            cout << "Count initialized to 0" << endl;
        }
        else
        {
            count = c;
        }
    }
    void display() const
    {
        cout << "Count: " << count << endl;
    }
};
int main()
{
    Counter c1;          // Default constructor
    const Counter c2(5); // Parameterized constructor
    c2.display();
    const Counter c3(-10); // Negative count
    c3.display();
    return 0;
}