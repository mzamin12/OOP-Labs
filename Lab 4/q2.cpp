#include <iostream>

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            std::cout << "Invalid initial balance. Setting balance to 0.0" << std::endl;
        }
    }

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Debit amount exceeded account balance." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account myAccount(100.0);
    std::cout << "Initial Balance: $" << myAccount.getBalance() << std::endl;

    myAccount.credit(50.0);
    std::cout << "Balance after credit: $" << myAccount.getBalance() << std::endl;

    myAccount.debit(30.0);
    std::cout << "Balance after debit: $" << myAccount.getBalance() << std::endl;

    myAccount.debit(150.0);
    std::cout << "Final Balance: $" << myAccount.getBalance() << std::endl;

    return 0;
}
