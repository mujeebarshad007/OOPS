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
        cout << " The Current balance is " << balance << endl;
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
    cout << " Balance is " << s.balance << endl;
}

int main()
{
    SavingsAccount b(200);
    b.showbalance();
    FriendAuditor f;
    f.Audit(b);
    return 0;
}