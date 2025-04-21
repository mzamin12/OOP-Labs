#include <iostream>
using namespace std;

class DigitalWallet {
private:
    double currentAmount;
    double dailyDepositTotal, dailyWithdrawalTotal;
    static const double maxDepositPerDay;
    static const double maxWithdrawalPerDay;

public:
    DigitalWallet(double amount) : currentAmount(amount), dailyWithdrawalTotal(0), dailyDepositTotal(0) {}
    DigitalWallet() : currentAmount(0) {}

    void addFunds(double amount) {
        if (dailyDepositTotal + amount > maxDepositPerDay) {
            cout << "Deposit exceeds the daily allowed limit!" << endl;
            return;
        } else {
            currentAmount += amount;
            dailyDepositTotal += amount;
            cout << "Successfully added Rs. " << amount << " to your wallet." << endl;
        }
    }

    void removeFunds(double amount) {
        if (dailyWithdrawalTotal + amount > maxWithdrawalPerDay) {
            cout << "Withdrawal exceeds the daily allowed limit!" << endl;
            return;
        } else if (amount > currentAmount) {
            cout << "Transaction failed: Not enough balance." << endl;
            return;
        } else {
            currentAmount -= amount;
            dailyWithdrawalTotal += amount;
            cout << "Successfully withdrew Rs. " << amount << " from your wallet." << endl;
        }
    }

    void clearDailyLimits() {
        dailyDepositTotal = 0;
        dailyWithdrawalTotal = 0;
    }

    double getCurrentBalance() {
        return currentAmount;
    }
};

const double DigitalWallet::maxDepositPerDay = 35000;
const double DigitalWallet::maxWithdrawalPerDay = 20000;

class AccountHolder {
private:
    string holderName;
    int holderAge;
    int id;
    static int nextID;
    DigitalWallet myWallet;

public:
    AccountHolder(string name, int age, DigitalWallet wallet) 
        : holderName(name), holderAge(age), id(nextID++), myWallet(wallet) {}

    void performDeposit() {
        double amount;
        cout << holderName << ", enter the amount to deposit: ";
        cin >> amount;
        myWallet.addFunds(amount);
    }

    void performWithdrawal() {
        double amount;
        cout << holderName << ", enter the amount to withdraw: ";
        cin >> amount;
        myWallet.removeFunds(amount);
    }

    void showBalance() {
        cout << holderName << "'s Wallet Balance: Rs. " << myWallet.getCurrentBalance() << endl;
    }
};

int AccountHolder::nextID = 0;

int main() {
    DigitalWallet walletA(12000); // Initial balance for Emily
    AccountHolder user1("Emily", 27, walletA);

    DigitalWallet walletB(3000); // Initial balance for Jack
    AccountHolder user2("Jack", 22, walletB);

    user1.showBalance();
    user1.performDeposit();
    user1.performWithdrawal();
    user1.showBalance();

    cout << "==========" << endl;

    user2.showBalance();
    user2.performDeposit();
    user2.performWithdrawal();
    user2.showBalance();

    return 0;
}
