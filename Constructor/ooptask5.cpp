#include <iostream>
using namespace std;
class Box
{
private:
    int length;
    int width;
    static int totalBoxes;

public:
    Box()
    {
        cout << " Default Constructor Called" << endl;
        length = 0;
        width = 0;
    }
    Box(int length, int width)
    {
        cout << " Parametrized Constructor Called" << endl;
        this->length = length;
        this->width = width;
        totalBoxes++;
    }

    Box(Box &copy)
    {
        cout << " Copy Constructor Called" << endl;
        length = copy.length;
        width = copy.width;
        totalBoxes++;
    }

    static void printtotalboxes()
    {
        cout << " Total Boxes Created: " << totalBoxes << endl;
    }
    void showarea() const
    {
        cout << " The Area is : " << length * width << endl;
    }
};

int Box ::totalBoxes = 0;
int main()
{
    Box b1;
    Box b2(10, 40);
    Box b3(b2);
    b2.showarea();
    b3.showarea();
    b1.printtotalboxes();
    return 0;
}