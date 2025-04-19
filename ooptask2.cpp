#include <iostream>
using namespace std;
class BOOK
{
public:
    int pages;
    BOOK()
    {
        cout << "Default Constructor Called" << endl;
        pages = 100;
    }
    BOOK(int a)
    {
        if (a < 1)
        {
            pages = 1;
        }
        else
        {
            pages = a;
        }
    }

    BOOK(BOOK &copy)
    {
        pages = copy.pages;
        cout << "Copy Constructor Called" << endl;
    }

    void showPages() const
    {
        cout << "Pages: " << pages << endl;
    }
};
int main()
{
    BOOK b1(1000);
    b1.showPages();
    BOOK b2(b1); // Copy constructor called
    b2.showPages();
    return 0;
}
