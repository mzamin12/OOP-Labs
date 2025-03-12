#include <iostream>
#include <vector>

using namespace std;

class Employee {
    protected:
        int employeeID;
        string name;
    public:
        Employee(int id, string n) : employeeID(id), name(n) {}

};

class Waiter : virtual public Employee {
    public:
        Waiter(int id, string n) : Employee(id, n) {}

        virtual void IOrderTaker() {
            cout << "Hello, what's your order?" << endl;
        }

};

class Cashier : virtual public Employee {
    public:
        Cashier(int id, string n) : Employee(id, n) {}

        virtual void IBiller() {
            cout << "Hello, what have you ordered?" << endl;
        }

};

class Manager : public Cashier, public Waiter {
    public:
        Manager(int id, string n) : Employee(id, n), Waiter(id, n), Cashier(id, n) {}

        void IOrderTaker() override {
            Waiter::IOrderTaker();
            cout << "I'm actually the manager btw" << endl;
        }

        void IBiller() override {
            Cashier::IBiller();
            cout << "I'm actually the manager btw" << endl;
        }

};

class Chef : virtual public Employee {
    public:
        Chef(int id, string n) : Employee(id, n) {}

        void IOrderPreparer() {
            cout << "Hello, what to cook?" << endl;
        }

};

class Menu {
    protected:
        vector<double> prices;
        double currentBill;

    public:
        Menu() : currentBill(0) {}

        virtual void addItemToBill(double item) {
            prices.push_back(item);
        }

        void resetBill() {
            prices.clear();
            cout << "All items removed from bill" << endl;
        }

        virtual void calculateFinal() {
            for (auto i=prices.begin(); i != prices.end(); i++) {
                currentBill += *i;
            }
            cout << "Final Bill = $" << currentBill << endl;
        }

};

class FoodMenu : virtual public Menu {
    public:
        void calculateFinal() { // Discount if multiple items 
            Menu::calculateFinal();
            if (prices.size() >= 5) currentBill *= 0.8;
            cout << "Final bill after discounts = $" << currentBill << endl;
            currentBill = 0;
        }

};

class BeverageMenu : virtual public Menu {
    public:
        void calculateFinal() { // Each beverage has 1.1x the price
            for (auto i=prices.begin(); i != prices.end(); i++) {
                currentBill += ((*i) * 1.1);
            }
            cout << "Final bill = $" << currentBill << endl;
            currentBill = 0;
        }
        
};


int main() {
    Waiter waiter(101, "waiter");
    Cashier cashier(202, "cashier");
    Chef chef(303, "chef");

    waiter.IOrderTaker();
    cashier.IBiller();
    chef.IOrderPreparer();

    cout << endl << endl;

    Manager manager(1000, "manager");
    manager.IBiller();
    manager.IOrderTaker();

    cout << endl << endl;

    FoodMenu food;
    BeverageMenu beverage;

    cout << endl << endl;

    Menu* menuItem = &food;
    Menu* menuItem2 = &beverage;

    menuItem->addItemToBill(100);
    menuItem->calculateFinal();
    menuItem->resetBill();

    cout << endl << endl;

    menuItem2->addItemToBill(100);
    menuItem2->addItemToBill(200);
    menuItem2->calculateFinal();
    menuItem2->resetBill();

    return 0;
}