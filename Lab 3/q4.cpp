#include <iostream>
using namespace std;

class Employee {
    private:
        string first_name;
        string last_name;
        double salary;
    
    public: 
        void set_Salary(double salary){
            if (salary < 0)
            {
                this->salary = 0;
            }
            else{
                this->salary = salary;
            }
        }
        double get_Salary(){
            return salary;
        }
};

int main(){
    Employee emp;
    emp.set_Salary(2);
    double salary = emp.get_Salary();
    cout << "Yearly Salary: " << (salary*12)+(salary*0.1);
}