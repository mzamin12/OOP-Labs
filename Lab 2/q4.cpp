#include <iostream>
using namespace std;

struct Employee
{
    int emp_id;
    string name;
    int salary;
};

struct Organisation
{
    string org_name;
    string org_num;
    Employee emp;
};

int main(){
    Organisation org;
    org.emp.emp_id = 127;
    org.org_name = "NU-Fast";
    org.org_num = "NUFAST123ABC";
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;
    cout << "The size of structure organisation : " << sizeof(Organisation) << endl;
    cout << "Organisation Name: " << org.org_name << endl;
    cout << "Organistion Number: " << org.org_num << endl;
    cout << "Employee id: " << org.emp.emp_id << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;
}
