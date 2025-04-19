#include <iostream>
using namespace std;
class Parent
{
public:
    int x;
    string name;

    class child : public Parent
    {
    public:
        child()
        {
            x = 20;
            name = "Ali";
        }
        void display() const
        {
            cout << " The x is " << x << endl;
            cout << " The name is " << endl;
        }
    }
};

int main()
{
    Child obj;
    obj.display();
    return 0;
}