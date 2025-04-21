#include <iostream>
#include <vector>
using namespace std;

class LogSystem {
private:
    vector<string> entries;
    static const int maxEntries;

    void record(string type, string message) {
        if (entries.size() >= maxEntries) entries.erase(entries.begin());
        entries.push_back("[" + type + "] " + message);
    }

public:
    void info(string message) { record("INFO", message); }
    void warning(string message) { record("WARNING", message); }
    void error(string message) { record("ERROR", message); }

    friend class Inspector;
};

const int LogSystem::maxEntries = 1000;

class Inspector {
private:
    string accessKey;
    bool isLoggedIn;

public:
    Inspector(string key) : accessKey(key), isLoggedIn(false) {}

    bool login() {
        if (isLoggedIn) return true;
        string inputKey;
        cout << "Please enter admin key to access logs: ";
        cin >> inputKey;
        if (inputKey == accessKey) {
            cout << "Access granted." << endl;
            isLoggedIn = true;
            return true;
        } else {
            cout << "Access denied. Invalid key." << endl;
            return false;
        }
    }

    void viewLogs(const LogSystem& system) {
        if (login()) {
            for (int i = 0; i < system.entries.size(); i++) {
                cout << system.entries[i] << endl;
            }
        }
    }
};

int main() {
    LogSystem system;
    Inspector inspector("admin123");

    system.info("Server started successfully.");
    system.warning("Memory usage is high.");
    system.error("Unable to reach authentication server.");

    inspector.viewLogs(system); // try wrong password
    inspector.viewLogs(system); // try correct password

    return 0;
}
