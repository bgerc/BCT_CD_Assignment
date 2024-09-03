/*Create a base class Account with data members accountNumber and balance.Derive two classes SavingsAccount and CheckingAccount from Account . 
Implement polymorphic behaviour where the base class pointer can point to objects of derived classes ,
 and call their respective member functions to deposit and withdraw money , applying specific rules for each account type. */

 #include <iostream>
using namespace std;


class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(float amount) = 0;   
    virtual void withdraw(float amount) = 0;  
    
    void display()  {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int accNum, float bal) : Account(accNum, bal) {}

    void deposit(float amount) override {
        balance += amount;
    }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance in SavingsAccount." << endl;
        }
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, float bal) : Account(accNum, bal) {}

    void deposit(float amount) override {
        balance += amount;
    }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance in CheckingAccount." << endl;
        }
    }
};


int main() {
    Account* accPtr;  
    SavingsAccount savAcc(1001, 5000.0);
    CheckingAccount chkAcc(2001, 3000.0);

    float amount;

   
    accPtr = &savAcc;
    cout << "Savings Account Operations:" << endl;
    accPtr->display();
    cout << "Enter amount to deposit into Savings Account: ";
    cin >> amount;
    accPtr->deposit(amount);
    cout << "Enter amount to withdraw from Savings Account: ";
    cin >> amount;
    accPtr->withdraw(amount);
    accPtr->display();

    
    accPtr = &chkAcc;
    cout << "Checking Account Operations:" << endl;
    accPtr->display();
    cout << "Enter amount to deposit into Checking Account: ";
    cin >> amount;
    accPtr->deposit(amount);
    cout << "Enter amount to withdraw from Checking Account: ";
    cin >> amount;
    accPtr->withdraw(amount);
    accPtr->display();

    return 0;
}
