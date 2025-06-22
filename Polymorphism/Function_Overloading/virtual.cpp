#include <iostream>
using namespace std;
class animal
{
public:
    virtual void sound()
    {
        cout << " Animal sound " << endl;
    }
};
class dog : public animal
{
    void sound() override
    {
        cout << " bark " << endl;
    }
};
class cat : public animal
{
    void sound() override
    {
        cout << " Meow " << endl;
    }
};

int main()
{
    animal *a;
    dog d;
    cat c;
    a = &d;
    a->sound();
    a = &c;
    a->sound();
    return 0;
}