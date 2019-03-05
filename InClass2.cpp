#include<iostream>
#include<string>
using namespace std;

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string n,int i,string d,string p)
    {
        name = n;
        idNumber = i;
        department = d;
        position = p;
    }
    Employee(string n, int i)
    {
        name = n;
        idNumber = i;
        department = "";
        position = "";
    }
    Employee()
    {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    string getName(){
        return this->name;
    }
    int getId(){
        return this->idNumber;
    }
    string getDepartment(){
        return this->department;
    }
    string getPosition(){
        return this->position;
    }
    void setName(string n){
        name = n;
    }
    void setId(int id){
        idNumber = id;
    }
    void setDepartment(string d){
        department = d;
    }
    void setPosition(string p){
        position = p;
    }
};

int main()
{
    cout<<      "NAME         ID#   Department    Position"<<endl;
    Employee e1("Susan Meyers",47899,"Accounting   ","Vice President");
    Employee e2("Mark Jones  ",39119,"IT           ","Programming");
    Employee e3("Joy Rogers  ",81774,"Manufacturing","Engineer");
    Employee a[3] = {e1,e2,e3};
    for(int i = 0;i< 3;i++)
    {
       cout<<a[i].getName()<<" "<<a[i].getId()<<" "
        <<a[i].getDepartment()<<" "<<a[i].getPosition()<<endl;
    }

    return 0;
}
