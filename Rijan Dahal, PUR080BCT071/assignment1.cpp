#include<iostream>
#include<string>
using namespace std;
class person
{
    private:
    string name;
    string dateofbirth;
public:
    person ()
    {}
    person (string Name,string dob)
    {
       name=Name;
       dateofbirth=dob;
    }

     void display()
     {

         cout<<"Name="<<name <<" "<<endl<< "Date of Birth="<<dateofbirth<<endl;
     }
     string getdob()
     {
         return dateofbirth;
     }

};
int main()
{
    int i,n=5;
     person p[n] = {
        person("ram singh", "1984-04-12"),
        person("shyam mandal", "2002-09-31"),
        person("sita devi", "2004-06-28"),
        person("dinesh karthik", "1984-04-12"),
        person("virat kohli","1988-05-13")
    };

    string dob;
    cout<<"Enter the date of birth in format of (YY-MM-DD)";
    cin>>dob;
    bool found=false;
    cout<<"The dob matched information is "<<endl;
    for(i=0;i<n;i++)
    {
        if(p[i].getdob()==dob)
        {
            p[i].display();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"Sorry! The Date of Birth doesn't match";
    }
}
