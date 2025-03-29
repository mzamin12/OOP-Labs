#include <iostream>

using namespace std;

class Employee {
protected:
    int empCode;
public:
    Employee(int code = 0) : empCode(code) {}

    int getEmpCode() const {
        return empCode;
    }

    virtual double calculateBonus() const = 0;

    virtual void showDetails() const {
        cout << "Employee Code: " << empCode << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
protected:
    string empName;
    double salary;
public:
    Manager(int code, string name, double sal) : Employee(code), empName(name), salary(sal) {}

    double calculateBonus() const override {
        return salary * 0.05 * 12;
    }

    void showDetails() const override {
        Employee::showDetails();
        cout << "Name: " << empName << endl;
        cout << "Monthly Salary: $" << salary << endl;
        cout << "Yearly Bonus: $" << calculateBonus() << endl;
    }
};

class Finance : public Employee {
protected:
    string empName;
    double salary;
public:
    Finance(int code, string name, double sal) : Employee(code), empName(name), salary(sal) {}

    double calculateBonus() const override {
        return salary * 0.05 * 12;
    }

    void showDetails() const override {
        Employee::showDetails();
        cout << "Name: " << empName << endl;
        cout << "Monthly Salary: $" << salary << endl;
        cout << "Yearly Bonus: $" << calculateBonus() << endl;
    }
};

int main() {
    int code;
    string name;
    double salary;

    cout << "Enter Manager Details:\n";
    cout << "Employee Code: ";
    cin >> code;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "Monthly Salary: ";
    cin >> salary;
    Manager manager(code, name, salary);

    cout << "\nEnter Finance Employee Details:\n";
    cout << "Employee Code: ";
    cin >> code;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "Monthly Salary: ";
    cin >> salary;
    Finance finance(code, name, salary);

    Employee* staff[2] = { &manager, &finance };

    cout << "\nEmployee Information:\n";
    for (int i = 0; i < 2; i++) {
        staff[i]->showDetails();
        cout << "-------------------------\n";
    }

    return 0;
}
