#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;

public:
    Book() {}

    void inputBookDetails() {
        cout << "Enter book title: ";
        cin >> title;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter publisher: ";
        cin >> publisher;
        cout << "Enter stock: ";
        cin >> stock;
    }

    void displayBookDetails() const {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price 
             << ", Publisher: " << publisher << ", Stock: " << stock << endl;
    }

    string getTitle() const {
        return title;
    }
};

class BookShop {
private:
    Book inventory[100];
    int bookCount;

public:
    BookShop() : bookCount(0) {}

    void addBook() {
        if (bookCount < 100) {
            inventory[bookCount].inputBookDetails();
            bookCount++;
        } else {
            cout << "Inventory full. Cannot add more books." << endl;
        }
    }

    void listBooks() {
        if (bookCount == 0) {
            cout << "No books in the inventory." << endl;
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            inventory[i].displayBookDetails();
        }
    }

    void searchBook(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (inventory[i].getTitle() == title) {
                inventory[i].displayBookDetails();
                return;
            }
        }
        cout << "Book not available." << endl;
    }
};

int main() {
    BookShop shop;
    int choice;

    while (true) {
        cout << "\nBook Shop Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addBook();
                break;
            case 2:
                shop.listBooks();
                break;
            case 3: {
                string searchTitle;
                cout << "Enter book title to search: ";
                cin >> searchTitle;
                shop.searchBook(searchTitle);
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
