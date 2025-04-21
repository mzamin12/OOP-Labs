#include <iostream>
#include <string>
using namespace std;

class Physician;
class Accounts;

class PatientFile {
private:
    string fullName;
    string uniqueID;
    string birthDate;
    string* history;
    int historyCount;

    string* charges;
    int chargeCount;

    void updateHistory(const string& note) {
        string* temp = new string[historyCount + 1];
        for (int i = 0; i < historyCount; i++) temp[i] = history[i];
        temp[historyCount++] = note;
        delete[] history;
        history = temp;
    }

    void updateCharges(const string& charge) {
        string* temp = new string[chargeCount + 1];
        for (int i = 0; i < chargeCount; i++) temp[i] = charges[i];
        temp[chargeCount++] = charge;
        delete[] charges;
        charges = temp;
    }

public:
    PatientFile(string id, string name, string dob) {
        uniqueID = id;
        fullName = name;
        birthDate = dob;
        history = nullptr;
        charges = nullptr;
        historyCount = chargeCount = 0;
    }

    string basicDetails() const {
        return "Patient Name: " + fullName + " | ID: " + uniqueID + " | DOB: " + birthDate;
    }

    string showHistory() const {
        string report = "Medical Notes:\n";
        for (int i = 0; i < historyCount; i++) {
            report += "- " + history[i] + "\n";
        }
        return report;
    }

    string showCharges() const {
        string billReport = "Payment Entries:\n";
        for (int i = 0; i < chargeCount; i++) {
            billReport += "- " + charges[i] + "\n";
        }
        return billReport;
    }

    friend class Physician;
    friend class Accounts;

    ~PatientFile() {
        delete[] history;
        delete[] charges;
    }
};

class Physician {
public:
    void writeNote(PatientFile& record, const string& note) {
        record.updateHistory("Note: " + note);
        cout << "Physician added a note to history.\n";
    }

    void reviewHistory(const PatientFile& record) {
        cout << record.showHistory();
    }
};

class Accounts {
public:
    void addCharge(PatientFile& record, const string& charge) {
        record.updateCharges("Charge: " + charge);
        cout << "Accounts recorded a new charge.\n";
    }

    void reviewCharges(const PatientFile& record) {
        cout << record.showCharges();
    }
};

class Assistant {
public:
    void viewBasicInfo(const PatientFile& record) {
        cout << record.basicDetails() << endl;
    }

    void requestHistoryAccess(const PatientFile& record) {
        cout << "Assistant attempting to view history...\n";
        cout << "Access Restricted!\n";
    }

    void requestChargeAccess(const PatientFile& record) {
        cout << "Assistant attempting to view billing...\n";
        cout << "Access Restricted!\n";
    }
};

int main() {
    PatientFile profile("PX001", "Natalie Reed", "1992-07-19");

    Physician docTaylor;
    Accounts financeOffice;
    Assistant adminDesk;

    cout << "\n--- Admin Desk ---\n";
    adminDesk.viewBasicInfo(profile);
    adminDesk.requestChargeAccess(profile);
    adminDesk.requestHistoryAccess(profile);

    cout << "\n--- Medical Staff ---\n";
    docTaylor.writeNote(profile, "Recommended MRI scan.");
    docTaylor.writeNote(profile, "Scheduled review in two weeks.");
    docTaylor.reviewHistory(profile);

    cout << "\n--- Finance Office ---\n";
    financeOffice.addCharge(profile, "MRI Scan: $250");
    financeOffice.addCharge(profile, "General Checkup: $75");
    financeOffice.reviewCharges(profile);

    return 0;
}
