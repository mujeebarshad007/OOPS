#include <iostream>

class Base
{
public:
    int x;
    Base(int x) : x(x) {}
};

class Derived : public Base
{
public:
    int y;
    Derived(int x, int y) : Base(x), y(y) {}
};

int main()
{
    Derived d(1, 2);
    Base b = d; // Object slicing occurs here
    std::cout << "b.x: " << b.x << std::endl;
    // std::cout << "b.y: " << b.y << std::endl;  // Error: 'y' is not a member of 'Base'

    Derived *dp = &d;
    Base *bp = dp; // Base pointer can point to Derived object
    std::cout << "bp->x: " << bp->x << std::endl;
    // std::cout << "bp->y: " << bp->y << std::endl;  // Error: 'y' is not a member of 'Base'

    // but Note
    //  Derived *ptr=new  Base(2);
    // Error:Every derived is a base but every base is not a derived.
    // Allowed if explicit cast(dynamic casting by which derived class pointer can also point to base class object) made

    Derived &dr = d;
    Base &br = dr; // Base reference can refer to Derived object
    std::cout << "br.x: " << br.x << std::endl;
    // std::cout << "br.y: " << br.y << std::endl;  // Error: 'y' is not a member of 'Base'

    return 0;
}
