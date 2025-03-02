#include <iostream>
using namespace std;
template <class T>
void swapValues(T a, T b)
{
    swap(a, b);
    cout << a << " " << b << endl;
}
int main()
{
    swapValues<int>(2, 3);
    swapValues<float>(2.8, 3.9);
    swapValues<char>('a', 'z');

    return 0;
}