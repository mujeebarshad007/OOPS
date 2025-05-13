#include <iostream>
using namespace std;
template <typename T>
class Pair
{
    T first;
    T second;

public:
    Pair(T f, T s)
    {
        first = f;
        second = s;
    }
    friend T calculateSum(const Pair<T> &p)
    {
        return p.first + p.second;
    }
};
int main()
{
    Pair<int> b(2, 4);
    Pair<float> q(2.2, 4.6);
    cout << "Sum is " << calculateSum(b) << endl;
    cout << "Sum is " << calculateSum(q) << endl;
    return 0;
}