#include <iostream>
using namespace std;
class Student
{
    string name = "Ali";
    const int id = 1;

public:
    string Getname() const
    {
        // we cannot do like name ="Mujeeb"
        // Here if you try to modify data member name,it will cause error although it is non-const
        // like:
        // name="Mujeeb";
        return name;
    }
    int Getid() const
    {
        // we cannot do like id =2;
        // Here if you try to modify data member Id,it will cause error
        //  like:
        //  Id=9;
        return id;
    }
};

int main()
{
    Student s1;
    Student const s2;
    cout << s1.Getid() << endl;   /*non Const Object*/
    cout << s2.Getid() << endl;   /*Const Object can also call Const Function*/
    cout << s1.Getname() << endl; /*non Const Object*/
    cout << s2.Getname() << endl; /*Const Object can also call Const Function*/

    return 0;
}