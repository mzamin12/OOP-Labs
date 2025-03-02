#include <iostream>
#include <vector>
using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
private:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> shopMenu) : name(shopName), menu(shopMenu) {}

    string addOrder(string itemName) {
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].name == itemName) {
                orders.push_back(itemName);
                return "You have successfully added " + itemName + " to your order.";
            }
        }
        return "Sorry, " + itemName + " is not available right now.";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string readyItem = orders[0];
            orders.erase(orders.begin());
            return "Your " + readyItem + " is now ready for pickup!";
        }
        return "No orders to fulfill at the moment.";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (size_t i = 0; i < orders.size(); i++) {
            for (size_t j = 0; j < menu.size(); j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "Currently, no menu items are available.";
        MenuItem cheapest = menu[0];
        for (size_t i = 1; i < menu.size(); i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return "The least expensive item is " + cheapest.name + " at $" + to_string(cheapest.price);
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].type == "drink") {
                drinks.push_back(menu[i].name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i].type == "food") {
                foods.push_back(menu[i].name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 1.8, "drink"},
        {"Sandwich", 4.5, "food"},
        {"Muffin", 3.0, "food"},
        {"Juice", 3.2, "drink"}
    };

    CoffeeShop shop("Java Beans", menu);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Pizza") << endl;
    cout << shop.fulfillOrder() << endl;

    vector<string> currentOrders = shop.listOrders();
    cout << "Current orders in the system: ";
    for (size_t i = 0; i < currentOrders.size(); i++) {
        cout << currentOrders[i] << " ";
    }
    cout << endl;

    cout << "Total amount due for your orders: $" << shop.dueAmount() << endl;
    cout << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Available drinks: ";
    for (size_t i = 0; i < drinks.size(); i++) {
        cout << drinks[i] << " ";
    }
    cout << endl;

    vector<string> foods = shop.foodOnly();
    cout << "Available food items: ";
    for (size_t i = 0; i < foods.size(); i++) {
        cout << foods[i] << " ";
    }
    cout << endl;

    return 0;
}
