#include <iostream>
using namespace std;
class binary
{
public:
    string s;
    void read(void);
    void check(void);
};
void binary::read(void)
{
    cout << " Enter the Number you want to check binary" << endl;
    cin >> s;
}
void binary::check(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' || s.at(i) != '1')
        {
            cout << " Incorect Binary NUmber" << endl;
            exit(0);
        }
    }
}
int main()
{
    binary b;
    b.read();
    b.check();
    return 0;
}