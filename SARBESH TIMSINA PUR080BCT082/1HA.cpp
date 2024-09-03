#include <iostream>
#include <vector>
using namespace std;

class person {
private:
    string name;
    long int dob;

public:
    void getinput() {
        cout << "Enter name and date of birth of a person:" << endl;
        cin >> name >> dob;
    }

    void display() const {
        cout << "Name : " << name << endl
             << "Date Of Birth : " << dob << endl;
    }

    long int DOB() const {
        return dob;
    }
};

int main() {
    int n;
    cout << "Enter how many records you want to store ? " << endl;
    cin >> n;

    if (n < 2) {
        cout << "Number of records should be at least 2." << endl;
        return 1;
    }

    vector<person> persons(n);

    for (int i = 0; i < n; i++) {
        persons[i].getinput();
    }

    bool foundDuplicate = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (persons[i].DOB() == persons[j].DOB()) {
                if (!foundDuplicate) {
                    cout << "Persons with the same date of birth (" << persons[i].DOB() << "):" << endl;
                    foundDuplicate = true;
                }
                persons[i].display();
                persons[j].display();
            }
        }
    }

    if (!foundDuplicate) {
        cout << "No persons with the same date of birth." << endl;
    }

    return 0;
}
