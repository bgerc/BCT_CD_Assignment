/*Design a class Employee with id, name ,and salary as data members .Implement functions to input employee data and display employees 
who have a salary greater than a user specified amount*/
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    char name[30];
    string sal;

public:
    void getdata() {
        cout << "Enter the ID, name and salary of employee: ";
        cin >> id >> name >> sal;
    }

    void showdata() {
        cout << "The ID, name, and salary of employee are: " << endl;
        cout << id << " " << name << " " << sal << endl;
    }

    string getsal() {
        return sal;
    }
};

int main() {
    string comsal;
    cout << "Enter the salary amount to be compared: ";
    cin >> comsal;

    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee e[n];

    for (int i = 0; i < n; i++) {
        e[i].getdata();
    }

    cout << "Employees with salary greater than " << comsal << " are:" << endl;

    for (int i = 0; i < n; i++) {
        
        if (e[i].getsal() > comsal) {
            e[i].showdata();
        }
    }

    return 0;
}