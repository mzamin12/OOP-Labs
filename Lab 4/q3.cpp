#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNumber, string partDescription, int quantity, double pricePerItem)
        : partNumber(partNumber), partDescription(partDescription), quantity(quantity), pricePerItem(pricePerItem) {
        if (this->quantity < 0) this->quantity = 0;
        if (this->pricePerItem < 0) this->pricePerItem = 0.0;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    Invoice invoice("1234", "Hammer", 5, 10.5);
    cout << "Invoice Amount: $" << invoice.getInvoiceAmount() << endl;
    return 0;
}
