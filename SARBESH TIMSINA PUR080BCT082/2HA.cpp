#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    void getdata() {
        cout << "Enter id, name, and salary of an employee: " << endl;
        cin >> id;
        cin.ignore(); 
        getline(cin, name);
        cin >> salary;
    }

    void display() const {
        cout << "Name: " << name << " | ID: " << id << " | Salary: " << salary << endl;
    }

    float show_salary() const {
        return salary;
    }
};

int main() {
    int n;
    float amount;

    cout << "How many records do you want to store?" << endl;
    cin >> n;

    if (n <= 0) {
        cout << "Number of records must be positive." << endl;
        return 1;
    }

    vector<Employee> employees(n);

    for (int i = 0; i < n; i++) {
        employees[i].getdata();
    }

    cout << "Enter the salary you want to take as a reference for comparison: " << endl;
    cin >> amount;

    cout << "The information of employees having salary greater than " << amount << " is: " << endl;
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.show_salary() > amount) {
            emp.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No employees have a salary greater than " << amount << "." << endl;
    }

    return 0;
}
