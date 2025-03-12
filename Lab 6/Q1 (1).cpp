#include <iostream>

using namespace std;

class BankAccount {
    protected:
        int account;
        double balance;
        double maxWithdraw;
        bool accountFrozen;

    public: 
        BankAccount(int a, double b, double max) : account(a), balance(b), maxWithdraw(max) {
            accountFrozen = false;
        }

        virtual void deposit(double deposit) {
            balance += deposit;
            cout << "$" << deposit << " successfully deposited" << endl;
        }

        virtual void withdraw(double withdraw) {
            if (withdraw > maxWithdraw) {
                cout << "$" << withdraw << " exceeds your withdrawal limit" << endl;
                return;
            }
            if (withdraw > balance) {
                cout << "Not enough money" << endl;
            } else {
                balance -= withdraw;
                cout << "$" << withdraw << " successfully withdrawn" << endl;
            }
        }

        void freezeAccount() {
            accountFrozen = true;
            cout << "Account has been frozen" << endl;
        }

        void unfreezeAccount() {
            accountFrozen = false;
            cout << "Account has been unfrozen" << endl;
        }

        bool checkAccountStatus() {
            return accountFrozen;
        }

        void changeWithdrawalLimit(double newLimit) {
            maxWithdraw = newLimit;
            cout << "Withdrawal limit changed to $" << maxWithdraw << endl;
        }

};

class SavingsAccount : public BankAccount {
    private:
        int monthlyInterestRate;

    public:
        SavingsAccount(int account, double balance, double max, int interestRate) : BankAccount(account, balance, max) {
            this->monthlyInterestRate = interestRate;
        }

        void applyMonthlyInterest() {
            balance = balance * (1 + (monthlyInterestRate / 100));
            cout << "New balance after monthly interest: $" << balance << endl;
        }

};

class CheckingAccount : public BankAccount {
    private:
        double currentOverdraft;
        double overdraftLimit;
        bool overdraftLimitReached;

    public:
        CheckingAccount(int account, double balance, double max, double limit) : BankAccount(account, balance, max) {
            overdraftLimit = limit;
            currentOverdraft = 0;
            overdraftLimitReached = false;
        }

        void withdraw(double withdraw) override {
            if (withdraw > maxWithdraw) {
                cout << "$" << withdraw << " exceeds your withdrawal limit" << endl;
                return;
            }
            if (withdraw <= balance) {
                balance -= withdraw;
                cout << "$" << withdraw << " successfully withdrawn. No overdraft needed. Balance remaining: $" << balance << endl;
            } else {
                double amountTaken = balance;
                withdraw -= balance;
                balance = 0;
                if (overdraftLimit == currentOverdraft) {
                    cout << "You were only able to withdraw $" << amountTaken << " due to limited balance and overdraftlimit reached" << endl;
                } else if (withdraw <= (overdraftLimit - currentOverdraft)) {
                    currentOverdraft += withdraw;
                    amountTaken += withdraw;
                    cout << "$" << amountTaken << " successfully withdrawn with $" << overdraftLimit - currentOverdraft << " overdraft remaining" << endl;
                    if (overdraftLimit == currentOverdraft) {
                        overdraftLimitReached = true;
                    }
                } else {
                    amountTaken += (overdraftLimit - currentOverdraft);
                    currentOverdraft = overdraftLimit;
                    cout << "$" << amountTaken << " able to be withdrawn. However, overdraft limit has been reached" << endl;
                    
                }
            }
        }
        
        void changeOverdraftLimit(double newLimit) {
            overdraftLimit = newLimit;
            cout << "Overdraft limit changed to $" << overdraftLimit << endl;
        }

};

class BusinessAccount : public BankAccount {
    private:
        double corporateTaxPerc;

    public:
        BusinessAccount(int account, double balance, double max, double perc) : BankAccount(account, balance, max) {
            corporateTaxPerc = perc;
        }

        void deposit(double deposit) override {
            deposit -= (deposit * (corporateTaxPerc / 100));
            balance += deposit;
            cout << "$" << deposit << " successfully deposited after corporate tax :)" << endl;
        }

};


class Employee {
    private:
        string name;
        int employeeID;

    public: 
        Employee(string n, int id) : name(n), employeeID(id) {}

        void deposit(BankAccount *account, double deposit) {
            bool status = account->checkAccountStatus();
            if (!status) account->deposit(deposit);
            else cout << "Your account is frozen" << endl;
        }

        void withdraw(BankAccount *account, double withdraw) {
            bool status = account->checkAccountStatus();
            if (!status) account->withdraw(withdraw);
            else cout << "Your account is frozen" << endl;
        }

};

class Teller : public Employee {
    public:
        Teller(string n, int id) : Employee(n, id) {}

        void freezeAccount(BankAccount *account) {
            account->freezeAccount();
        }

        void unfreezeAccount(BankAccount *account) {
            account->unfreezeAccount();
        }

};

class Manager : public Teller {
    public:
        Manager(string n, int id) : Teller(n, id) {}

        void changeWithdrawalLimit(BankAccount *account, double newLimit) {
            bool status = account->checkAccountStatus();
            if (!status) account->changeWithdrawalLimit(newLimit);
            else cout << "Your account is frozen" << endl;
            
        }

        void changeOverdraftLimit(CheckingAccount *account, double newLimit) {
            bool status = account->checkAccountStatus();
            if (!status) account->changeOverdraftLimit(newLimit);
            else cout << "Your account is frozen" << endl;
        }

};

class Customer {
    private:
        string name;
        int customerID;

    public:
        Customer(string n, int id) : name(n), customerID(id) {}

        void deposit(BankAccount *account, double deposit) {
            bool status = account->checkAccountStatus();
            if (!status) account->deposit(deposit);
            else cout << "Your account is frozen" << endl;
        }

        void withdraw(BankAccount *account, double withdraw) {
            bool status = account->checkAccountStatus();
            if (!status) account->withdraw(withdraw);
            else cout << "Your account is frozen" << endl;
        }
        
};


int main() {

    SavingsAccount savings(1001, 5000.0, 1000.0, 5); 
    CheckingAccount checking(1002, 2000.0, 500.0, 1500.0); 
    BusinessAccount business(1003, 10000.0, 2000.0, 10.0); 
    
    Employee employee("Naheel", 123);
    Teller teller("Abdullah", 456);
    Manager manager("Ali", 789);
    Customer customer("Ibrahim", 101);

    customer.deposit(&savings, 200.0);
    customer.withdraw(&savings, 100.0);

    teller.freezeAccount(&checking); // Acount is frozen, so following functions won't work
    teller.deposit(&checking, 500.0);  
    teller.withdraw(&checking, 300.0); 

    manager.changeWithdrawalLimit(&checking, 800.0);  
    manager.changeOverdraftLimit(&checking, 2000.0); 

    customer.deposit(&business, 1000.0); // Tax will be applied

    teller.unfreezeAccount(&checking);
    customer.withdraw(&checking, 2500.0); // Exceeds balance but within overdraft limit
    customer.deposit(&checking, 500.0); 
    customer.withdraw(&checking, 200.0); 

    return 0;
}