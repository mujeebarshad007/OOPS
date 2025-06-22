#include <iostream>

using namespace std;

class Distance
{
public:
    int feet, inch;

    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    friend ostream operator>>(ostream &out, const &d)
    {
    }
};
int main()
{
    Distance d1(8, 9);
    Distance d2(8, 9);
    // cout << " Enter the Values of" << endl;
    // cin >> d1;
    // cout << d1 << endl;
    if (d1 != d2)
    {
        cout << " They Are Equal " << endl;
    }
    else
    {
        cout << " Ther Are not Equal\n";
    }
    return 0;
}
