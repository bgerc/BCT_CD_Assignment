#include<iostream>
#include<string>
using namespace std;
class Employee
{
    private:
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getinput()
    {
        cout<<"Enter the ID:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the name:";
        getline(cin,name);
        cout<<"Enter the salary:";
        cin>>salary;
    }
    void showinput()
    {
        cout << "ID: " << id <<endl<< " Name: " << name <<endl<< " Salary: " << salary << endl;
    }
    float getsal()
    {
        return salary;
    }
};
int main()
{
    int n,i;
    cout<<"how many employees information you want?"<<endl;
    cin>>n;
    Employee* e = new Employee[n];
    for(i=0;i<n;i++)
    {
    cout<<"Please enter the data of Employee "<<(i+1)<<endl;
    e[i].getinput();
    cout<<endl;
    }
    float amount;
    cout<<"Enter the amount to be compared";
    cin>>amount;
    cout<<"Employees having salary greater than "<<amount<<":"<<endl;
    bool found=false;
    for(i=0;i<n;i++)
    {
        if(e[i].getsal()>amount)
        {
            e[i].showinput();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"The Employee having salary greater than"<<amount<<" not found.";
    }
    delete[] e;
}
