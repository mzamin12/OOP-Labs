#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
        string personName;
        int personID;

    public:
        virtual void inputData() {
            cout << "Enter Full Name: ";
            getline(cin, personName);
            cout << "Enter Employee ID: ";
            cin >> personID;
            cin.ignore(); 
        }

        virtual void showData() {
            cout << "Employee Name: " << personName << endl;
            cout << "Employee ID: " << personID << endl;
        }

        virtual void calculateBonus() {
            cout << "No bonus applicable for base Person class.\n";
        }

        virtual ~Person() {}
};

class Admin : virtual public Person {
    protected:
        float adminSalary;

    public:
        void inputData() override {
            Person::inputData();
            cout << "Input Admin's Salary: ";
            cin >> adminSalary;
            cin.ignore();
        }

        void showData() override {
            Person::showData();
            cout << "Salary (Admin): $" << adminSalary << endl;
        }

        void calculateBonus() override {
            cout << "Admin Bonus Amount: $" << adminSalary * 0.1 << endl;
        }
};

class Account : virtual public Person {
    protected:
        float accBalance;

    public:
        void inputData() override {
            Person::inputData();
            cout << "Input Account Balance: ";
            cin >> accBalance;
            cin.ignore();
        }

        void showData() override {
            Person::showData();
            cout << "Account Balance: $" << accBalance << endl;
        }

        void calculateBonus() override {
            cout << "Account Bonus Amount: $" << accBalance * 0.05 << endl;
        }
};

class Master : public Admin, public Account {
    public:
        void inputData() override {
            Person::inputData(); 
            cout << "Enter Salary for Admin Role: ";
            cin >> adminSalary;
            cout << "Enter Balance for Account Role: ";
            cin >> accBalance;
            cin.ignore();
        }

        void showData() override {
            Person::showData();
            cout << "Admin Salary: $" << adminSalary << endl;
            cout << "Account Balance: $" << accBalance << endl;
        }

        void calculateBonus() override {
            float combinedBonus = (adminSalary * 0.1f) + (accBalance * 0.05f);
            cout << "Total Bonus (Admin + Account): $" << combinedBonus << endl;
        }
};

int main() {
    Person* ptr;

    Master employee;
    cout << "--- Input Employee Data (Master Role) ---" << endl;
    ptr = &employee;
    ptr->inputData();

    cout << "\n--- Displaying Employee Information ---" << endl;
    ptr->showData();

    cout << "\n--- Bonus Calculation ---" << endl;
    ptr->calculateBonus();

    return 0;
}
