#include <iostream>

using namespace std;

class Book {
    protected:
        string genre;

    public: 
        Book(string g) : genre(g) {}

        virtual void displayDetails() {
            cout << "Genre = " << genre << endl;
        }

};

class Mystery : virtual public Book {
    private:
        string name;
        string author;
        int ISBN;

    public:
        Mystery(string n, string a, int isbn) : Book("Mystery"), name(n), author(a), ISBN(isbn) {}

        void displayDetails() override {
            cout << "Name: " << name << ", Author: " << author << ", ISBN number: " << ISBN << ", ";
            Book::displayDetails();
        }

};

class Novel : virtual public Book {
    private:
        string name;
        string author;
        int ISBN;

    public:
        Novel(string n, string a, int isbn) : Book("Fantasy"), name(n), author(a), ISBN(isbn) {}

        void displayDetails() override {
            cout << "Name: " << name << ", Author: " << author << ", ISBN number: " << ISBN << ", ";
            Book::displayDetails();
        }

};

int main() {
    Mystery m1("Sherlock Holmes", "Arthur Conon Doyle", 1010);
    m1.displayDetails();

    Novel n1("Harry Potter", "JK Rowling", 2020);
    n1.displayDetails();

    Book *newBook = &m1;
    Book *newBook2 = &n1;

    cout << endl;

    newBook->displayDetails();
    newBook2->displayDetails();

    return 0;
}