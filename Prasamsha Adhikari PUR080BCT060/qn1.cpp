
/*write a c++ program to create a class person with name and date of birth as data members .
Ask the user to enter a date of birth and print all persons name with a matched date of birth.*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string dateOfBirth;  

public:
   
    Person(const string& n = "", const string& dob = "") : name(n), dateOfBirth(dob) {}

    void setDat(const string& n, const string& dob) {
        name = n;
        dateOfBirth = dob;
    }

    void display() const {
        cout << "Name: " << name << ", Date of Birth: " << dateOfBirth << endl;
    }

    bool matchesDateOfBirth(const string& dob) const {
        return dateOfBirth == dob;
    }
};

int main() {
    const int maxPersons = 5;  
    Person persons[maxPersons];  

    for (int i = 0; i < maxPersons; i++) {
        string name, dob;
        cout << "Enter name of person " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter date of birth (YYYY-MM-DD) for person " << (i + 1) << ": ";
        cin >> dob;
        persons[i].setDat(name, dob);
    }

    string searchDateOfBirth;
    cout << "Enter date of birth (YYYY-MM-DD) to search: ";
    cin >> searchDateOfBirth;

    cout << "Persons with date of birth " << searchDateOfBirth << ":" << endl;
    bool found = false;
    for (int i = 0; i < maxPersons; i++) {
        if (persons[i].matchesDateOfBirth(searchDateOfBirth)) {
            persons[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "Not found" << endl;
    }

    return 0;
}
