#include <iostream>
#include <string>

using namespace std;

class CoffeeShop {
private:
    string name;
    struct MenuItem {
        string item;
        string type;
        double price;
    };
    
    MenuItem menu[100];
    string orders[100];
    int menuSize = 0;
    int orderSize = 0;

public:
    CoffeeShop(const string& shopName) : name(shopName) {}

    void addMenuItem(const string& item, const string& type, double price) {
        if (menuSize < 100) {
            menu[menuSize].item = item;
            menu[menuSize].type = type;
            menu[menuSize].price = price;
            menuSize++;
            cout << item << " added to the menu." << endl;
        } else {
            cout << "Menu is full, can't add more items." << endl;
        }
    }

    void addOrder(const string& itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].item == itemName) {
                if (orderSize < 100) {
                    orders[orderSize] = itemName;
                    orderSize++;
                    cout << itemName << " has been ordered." << endl;
                    return;
                }
            }
        }
        cout << "This item is currently unavailable" << endl;
    }

    string fulfillOrder() {
        if (orderSize == 0) {
            return "All orders have been fulfilled";
        } else {
            string order = orders[0];
            for (int i = 0; i < orderSize - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderSize--;
            return "The " + order + " is ready";
        }
    }

    void listOrders() {
        if (orderSize == 0) {
            cout << "No orders have been placed." << endl;
        } else {
            cout << "Orders: ";
            for (int i = 0; i < orderSize; i++) {
                cout << orders[i] << " ";
            }
            cout << endl;
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderSize; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].item == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) {
            return "No items in menu";
        }
        
        string cheapestName = menu[0].item;
        double cheapestPrice = menu[0].price;

        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapestPrice) {
                cheapestPrice = menu[i].price;
                cheapestName = menu[i].item;
            }
        }
        return cheapestName;
    }

    void drinksOnly() {
        bool found = false;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].item << " ";
                found = true;
            }
        }
        if (!found) cout << "No drinks on the menu.";
        cout << endl;
    }

    void foodOnly() {
        bool found = false;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].item << " ";
                found = true;
            }
        }
        if (!found) cout << "No food on the menu.";
        cout << endl;
    }
};

int main() {
    CoffeeShop shop("The Brewed Bean");

    int choice;
    string item, type;
    double price;
    
    while (true) {
        cout << "\n--- Coffee Shop Management System ---\n";
        cout << "1. Add Menu Item\n";
        cout << "2. Add Order\n";
        cout << "3. Fulfill Order\n";
        cout << "4. View Orders\n";
        cout << "5. View Total Amount Due\n";
        cout << "6. View Cheapest Item\n";
        cout << "7. View Drinks Only\n";
        cout << "8. View Food Only\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter item type (food/drink): ";
                cin >> type;
                cout << "Enter item price: ";
                cin >> price;
                shop.addMenuItem(item, type, price);
                break;
            case 2:
                cout << "Enter item name to order: ";
                cin >> item;
                shop.addOrder(item);
                break;
            case 3:
                cout << shop.fulfillOrder() << endl;
                break;
            case 4:
                shop.listOrders();
                break;
            case 5:
                cout << "Total amount due: $" << shop.dueAmount() << endl;
                break;
            case 6:
                cout << "Cheapest item: " << shop.cheapestItem() << endl;
                break;
            case 7:
                cout << "Drinks only: ";
                shop.drinksOnly();
                break;
            case 8:
                cout << "Food only: ";
                shop.foodOnly();
                break;
            case 9:
                cout << "Exiting the Coffee Shop Management System." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
