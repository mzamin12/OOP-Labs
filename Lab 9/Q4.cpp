#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Traveler;

class AirlineFlight {
private:
    string code;
    string from;
    string to;
    int capacity;
    int booked = 0;
    unordered_set<string> travelerIDs;

public:
    AirlineFlight(const string& flightCode, const string& origin, const string& destination, int seats)
        : code(flightCode), from(origin), to(destination), capacity(seats) {}

    bool assignSeat(const Traveler& t);
    bool removeSeat(const Traveler& t);
    bool requestUpgrade(const Traveler& t);
    void displayInfo() const;

private:
    bool isBooked(const string& id) const {
        return travelerIDs.find(id) != travelerIDs.end();
    }
};

class Traveler {
private:
    string id;
    string name;

public:
    Traveler(const string& travelerID, const string& travelerName) : id(travelerID), name(travelerName) {}

    string getID() const { return id; }

    void book(AirlineFlight& flight) {
        if (flight.assignSeat(*this)) {
            cout << name << " successfully booked a seat.\n";
        } else {
            cout << name << " could not be booked.\n";
        }
    }

    void cancel(AirlineFlight& flight) {
        if (flight.removeSeat(*this)) {
            cout << name << "'s booking has been canceled.\n";
        } else {
            cout << "Cancellation failed for " << name << ".\n";
        }
    }

    void requestSeatUpgrade(AirlineFlight& flight) {
        if (flight.requestUpgrade(*this)) {
            cout << name << " has been granted an upgrade.\n";
        } else {
            cout << name << " is not eligible for an upgrade.\n";
        }
    }
};

bool AirlineFlight::assignSeat(const Traveler& t) {
    if (booked >= capacity || isBooked(t.getID())) {
        return false;
    }
    travelerIDs.insert(t.getID());
    booked++;
    return true;
}

bool AirlineFlight::removeSeat(const Traveler& t) {
    if (!isBooked(t.getID())) {
        return false;
    }
    travelerIDs.erase(t.getID());
    booked--;
    return true;
}

bool AirlineFlight::requestUpgrade(const Traveler& t) {
    return isBooked(t.getID());
}

void AirlineFlight::displayInfo() const {
    cout << "Flight: " << code << " | Departure: " << from 
         << " | Destination: " << to << " | Occupied: " << booked << "/" << capacity << endl;
}

int main() {
    AirlineFlight flight1("AF428", "New York", "Paris", 2);
    AirlineFlight flight2("BA212", "London", "Toronto", 1);

    Traveler emma("T101", "Emma Watson");
    Traveler oliver("T102", "Oliver Stone");
    Traveler mia("T103", "Mia Johnson");

    flight1.displayInfo();
    emma.book(flight1);
    oliver.book(flight1);
    mia.book(flight1);
    flight1.displayInfo();

    emma.requestSeatUpgrade(flight1);
    mia.requestSeatUpgrade(flight1);

    oliver.cancel(flight1);
    flight1.displayInfo();

    mia.book(flight1);
    flight1.displayInfo();

    return 0;
}
