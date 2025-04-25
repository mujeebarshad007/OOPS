#include <iostream>
using namespace std;
class Account
{
public:
    virtual void showbalance() = 0;
};
class SavingsAccount : public Account
{
private:
    int balance;

public:
    SavingsAccount(int a)
    {
        balance = a;
    }
    void showbalance()
    {
        cout << " THe Balance is " << balance << endl;
    }
    friend void CheckBalance(SavingsAccount &s);
};
class FriendAuditor
{
public:
    void Audit(SavingsAccount &s)
    {
        CheckBalance(s);
    }
};
void CheckBalance(SavingsAccount &s)
{
    cout << " The Balance is Given as " << s.balance << endl;
}
int main()
{
    SavingsAccount s(100);
    s.showbalance();
    FriendAuditor f;
    f.Audit(s);
    return 0;
}