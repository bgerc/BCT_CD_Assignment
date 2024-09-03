#include <iostream>
#include <memory>
using namespace std;


class Account {
protected:
    int accountNumber;
    double balance;
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    virtual ~Account() {} 

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int accountNumber, double balance) : Account(accountNumber, balance) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance in Savings Account!" << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accountNumber, double balance) : Account(accountNumber, balance) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance in Checking Account!" << endl;
        }
    }
};

int main() {

    unique_ptr<Account> acc1 = make_unique<SavingsAccount>(1001, 500.0);
    unique_ptr<Account> acc2 = make_unique<CheckingAccount>(1002, 1000.0);
    acc1->deposit(200);
    acc1->withdraw(100);
    acc1->display();

    acc2->deposit(500);
    acc2->withdraw(1500);
    acc2->display();
    return 0;
}
