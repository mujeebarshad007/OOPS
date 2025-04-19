#include <iostream>
using namespace std;
class score
{
public:
    int points;

    score(int points)
    {
        if (points < 0)
        {
            cout << " Points Cannot be negative " << endl;
            cout << " Enter the Points " << endl;
            cin >> points;
            this->points = points;
        }
        else
        {
            this->points = points;
        }
    }

    int addPoints(int points)
    {
        if (points < 0)
        {
            cout << " Points Cannot be negative " << endl;
            return 0;
        }
        else
        {
            this->points += points;
            return this->points;
        }
    }

    void showPoints() const
    {
        cout << "Points: " << points << endl;
    }

    score(const score &copy)
    {
        points = copy.points;
        cout << "Copy Constructor Called" << endl;
    }

    void printscore() const
    {
        cout << " The Points are " << points << endl;
    }
};
int main()
{
    score s1(-3);
    s1.addPoints(76);
    s1.printscore();
    return 0;
}