#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string releaseDate;
    string uniqueID;
    string publisher;
    bool available;

public:
    Media(string t, string date, string id, string pub)
        : title(t), releaseDate(date), uniqueID(id), publisher(pub), available(true) {}

    virtual void showDetails() {
        cout << "Title            : " << title << endl;
        cout << "Release Date     : " << releaseDate << endl;
        cout << "Reference ID     : " << uniqueID << endl;
        cout << "Published By     : " << publisher << endl;
        cout << "Status           : " << (available ? "Available" : "Checked Out") << endl;
    }

    void borrowMedia() {
        if (available) {
            available = false;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }

    void returnMedia() {
        if (!available) {
            available = true;
            cout << title << " has been returned to the library." << endl;
        } else {
            cout << title << " was not borrowed." << endl;
        }
    }

    string getTitle() { return title; }
    string getReleaseDate() { return releaseDate; }
    string getUniqueID() { return uniqueID; }
    string getPublisher() { return publisher; }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string writer;
    string ISBN;
    int totalPages;

public:
    Book(string t, string date, string id, string pub, string author, string isbn, int pages)
        : Media(t, date, id, pub), writer(author), ISBN(isbn), totalPages(pages) {}

    void showDetails() override {
        Media::showDetails();
        cout << "Author           : " << writer << endl;
        cout << "ISBN Code        : " << ISBN << endl;
        cout << "Total Pages      : " << totalPages << endl;
    }

    string getWriter() { return writer; }
};

class DVD : public Media {
private:
    string filmmaker;
    int playTime;
    string ageRating;

public:
    DVD(string t, string date, string id, string pub, string director, int duration, string rating)
        : Media(t, date, id, pub), filmmaker(director), playTime(duration), ageRating(rating) {}

    void showDetails() override {
        Media::showDetails();
        cout << "Director         : " << filmmaker << endl;
        cout << "Duration (min)   : " << playTime << endl;
        cout << "Rating           : " << ageRating << endl;
    }
};

class CD : public Media {
private:
    string musician;
    int totalTracks;
    string category;

public:
    CD(string t, string date, string id, string pub, string artist, int tracks, string genre)
        : Media(t, date, id, pub), musician(artist), totalTracks(tracks), category(genre) {}

    void showDetails() override {
        Media::showDetails();
        cout << "Artist           : " << musician << endl;
        cout << "Number of Tracks : " << totalTracks << endl;
        cout << "Genre            : " << category << endl;
    }
};

class Magazine : public Media {
private:
    int editionNumber;

public:
    Magazine(string t, string date, string id, string pub, int issue)
        : Media(t, date, id, pub), editionNumber(issue) {}

    void showDetails() override {
        Media::showDetails();
        cout << "Edition Number   : " << editionNumber << endl;
    }
};

class Library {
private:
    Media* collection[10];
    int totalMedia;

public:
    Library() : totalMedia(0) {}

    void insertMedia(Media* item) {
        if (totalMedia < 10) {
            collection[totalMedia] = item;
            totalMedia++;
        } else {
            cout << "Library collection is at full capacity." << endl;
        }
    }

    void displayAllMedia() {
        for (int i = 0; i < totalMedia; i++) {
            collection[i]->showDetails();
            cout << "--------------------------" << endl;
        }
    }

    void findByTitle(string t) {
        for (int i = 0; i < totalMedia; i++) {
            if (collection[i]->getTitle() == t) {
                cout << "Item Found (Title Match):" << endl;
                collection[i]->showDetails();
                return;
            }
        }
        cout << "No media found with the title: " << t << endl;
    }

    void findByPublisher(string p) {
        for (int i = 0; i < totalMedia; i++) {
            if (collection[i]->getPublisher() == p) {
                cout << "Item Found (Publisher Match):" << endl;
                collection[i]->showDetails();
                return;
            }
        }
        cout << "No media found from publisher: " << p << endl;
    }

    void findByYear(string year) {
        for (int i = 0; i < totalMedia; i++) {
            if (collection[i]->getReleaseDate() == year) {
                cout << "Item Found (Publication Year Match):" << endl;
                collection[i]->showDetails();
                return;
            }
        }
        cout << "No media found for release year: " << year << endl;
    }
};

int main() {
    Library myLibrary;

    Book book1("C++ Essentials", "2020", "B001", "TechPress", "Bjarne Stroustrup", "1234567890", 350);
    DVD dvd1("Interstellar", "2014", "D001", "WB", "Christopher Nolan", 169, "PG-13");
    CD cd1("Greatest Hits", "1980", "C001", "Epic", "Queen", 15, "Rock");
    Magazine mag1("National Geographic", "2021", "M001", "NatGeo", 101);

    myLibrary.insertMedia(&book1);
    myLibrary.insertMedia(&dvd1);
    myLibrary.insertMedia(&cd1);
    myLibrary.insertMedia(&mag1);

    cout << "=== Library Collection ===" << endl;
    myLibrary.displayAllMedia();

    cout << "=== Searching by Title ===" << endl;
    myLibrary.findByTitle("Interstellar");

    cout << "=== Searching by Publisher ===" << endl;
    myLibrary.findByPublisher("Epic");

    cout << "=== Searching by Release Year ===" << endl;
    myLibrary.findByYear("2020");

    cout << "=== Borrowing & Returning ===" << endl;
    book1.borrowMedia();
    book1.borrowMedia();
    book1.returnMedia();
    book1.returnMedia();

    return 0;
}
