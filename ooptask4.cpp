#include <iostream>
using namespace std;
class Duration
{
private:
    int hours;
    int minutes;
    static int totalduration;

    void simplify()
    {
        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }

public:
    Duration()
    {
        cout << "Default Constructor Called" << endl;
        hours = 0;
        minutes = 0;
    }
    Duration(int h, int m)
    {
        hours = h;
        minutes = m;
        simplify();
        totalduration++;
    }
    static void showTotalDuration()
    {
        cout << "Total Duration objects created: " << totalduration << endl;
    }
    void display() const
    {
        cout << "Duration: " << hours << " hours, " << minutes << " minutes" << endl;
    }
};
int Duration::totalduration = 0;
int main()
{
    Duration d1;
    Duration d2(4, 100);
    Duration d3(0, 100);
    d1.display();
    d2.display();
    d3.display();
    d1.showTotalDuration();
    return 0;
}