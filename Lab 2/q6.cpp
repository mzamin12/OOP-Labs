#include <iostream>
#include <vector>

using namespace std;

struct Subject {
    string subjectName;
};

struct Student {
    int ID;
    Subject subjects[3];
};

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];

    for (int i = 0; i < N; i++) {
        cout << "Enter ID for Student " << i + 1 << ": ";
        cin >> students[i].ID;

        cout << "Enter 3 subjects for Student " << i + 1 << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].subjects[j].subjectName;
        }
    }

    cout << "\nStored Student Data:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Student ID: " << students[i].ID << endl;
        cout << "Subjects: ";
        for (int j = 0; j < 3; j++) {
            cout << students[i].subjects[j].subjectName << " ";
        }
        cout << endl;
    }

    delete[] students;

    return 0;
}