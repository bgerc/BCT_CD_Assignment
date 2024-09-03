#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    int accountNum;
    float balance;

public:
    Account(int a = 0, float b = 0.0) : accountNum(a), balance(b) {}

    virtual void deposit() = 0;
    virtual void withdraw() = 0;

    void getinput()
    {
        cout << "Enter the account number: ";
        cin >> accountNum;
        cout << "Enter the balance: ";
        cin >> balance;
    }

    void display(const string &type) const
    {
        cout << "Account Type: " << type << endl<< "Account Number: " << accountNum << endl<< "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int a = 0, float b = 0.0) : Account(a, b) {}

    void deposit() override
    {
        float amount;
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully\n";
    }

    void withdraw() override
    {
        float amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;
        if (balance - amount >= 0)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int a = 0, float b = 0.0) : Account(a, b) {}

    void deposit() override
    {
        float amount;
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully\n";
    }

    void withdraw() override
    {
        float amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;
        if (balance - amount >= 0)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
};

int main()
{
    Account *a = nullptr;
    int choice;

    cout << "1. Savings Account\n2. Checking Account\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        a = new SavingsAccount();
        a->getinput();
        a->deposit();
        a->withdraw();
        a->display("Savings Account");
        break;
    case 2:
        a = new CheckingAccount();
        a->getinput();
        a->deposit();
        a->withdraw();
        a->display("Checking Account");
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    delete a;
}
