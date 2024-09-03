#include <iostream>
#include <string>

using namespace std;

class DOB
{
    int day; 
    int month;
    int year;

public:
    DOB()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    DOB(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void setDOB()
    {
        cout << "Enter the date of birth (d/m/y):";
        cin >> day >> month >> year;
    }

    void showDOB() const
    {
        cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;
    }
    bool checkDOB(const DOB &dob) const
    {
        return (day == dob.day && month == dob.month);
    }
};

class Person
{
    string name;
    DOB dob;

public:
    Person()
    {
        name = "";
    }
    Person(string n, DOB d) : name(n), dob(d)
    {
    }
    void getPerson()
    {
        cout << "Enter the name: ";
        cin >> name;
        dob.setDOB();
    }
    void showPerson() const
    {
        cout << "Name: " << name << endl;
        dob.showDOB();
    }
    bool checkPerson(const DOB &d) const
    {
        return dob.checkDOB(d);
    }
};

int main()
{
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    Person *p = new Person[n]; 

    for (int i = 0; i < n; i++)
    {
        p[i].getPerson();
    }

    DOB dob;
    cout << "Enter the date of birth to search: ";
    dob.setDOB();

    cout << "Persons with matching DOB:\n";
    for (int i = 0; i < n; i++)
    {
        if (p[i].checkPerson(dob))
        {
            p[i].showPerson();
        }
    }

    delete[] p; 
    

    return 0;
}