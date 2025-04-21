#include <iostream>
using namespace std;

class Learner {
public:
    virtual int computeTuition(string level, int creditCount) = 0;
    virtual ~Learner() {}
};

class MastersStudent : public Learner {
private:
    string thesisTopic;

public:
    void setThesis(string topic) { thesisTopic = topic; }
    string getThesis() { return thesisTopic; }

    int computeTuition(string level, int creditCount) override {
        int amount = 0;
        if (level == "Undergraduate") {
            amount = 200 * creditCount;
        } else if (level == "Graduate") {
            amount = 300 * creditCount;
        } else if (level == "Doctoral") {
            amount = 400 * creditCount;
        }
        return amount;
    }
};

int main() {
    MastersStudent student;
    student.setThesis("Blockchain in Finance");
    cout << "Thesis Topic: " << student.getThesis() << endl;

    string studyLevel;
    int credits;

    cout << "Enter classification (Undergraduate / Graduate / Doctoral): ";
    cin >> studyLevel;
    cout << "Enter credit hours: ";
    cin >> credits;

    double fee = student.computeTuition(studyLevel, credits);
    cout << "Total Fee Payable: $" << fee << endl;

    return 0;
}
