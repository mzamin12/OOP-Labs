#include <iostream>
using namespace std;

class Book {
    private: 
        string name;
        string isbn;
        string author;
        string publisher;

    public:
        void setName(string name){
            this->name = name;
        }
        void setISBN(string isbn){
            this->isbn = isbn;
        }
        void setAuthor(string author){
            this->author = author;
        }
        void setPublisher(string publisher){
            this->publisher = publisher;
        }

        string getName(){
            return this->name;
        }
        string getISBN(){
            return this->isbn;
        }
        string getAuthor(){
            return this->author;
        }
        string getPublisher(){
            return this->publisher;
        }

        string getBookInfo(){
            return "Book Name: " + this->name + "\nISBN: " + this->isbn + "\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
        }
};

int main(){
    Book arr[5];
    arr[0].setName("1984");
    arr[0].setISBN("978-0743273565");
    arr[0].setAuthor("Scott Fitzgerald");
    arr[0].setPublisher("Scrinber");
    string out = arr[0].getBookInfo();
    cout << out; 
}