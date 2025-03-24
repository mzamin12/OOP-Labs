#include <iostream>
#include <vector>
using namespace std;

// Forward declaration
class Course;

// Base class: Person
class Person {
protected:
    string fullName, uniqueID, homeAddress, contactNumber, emailAddress;
public:
    Person(string name, string id, string address, string phone, string email)
        : fullName(name), uniqueID(id), homeAddress(address), contactNumber(phone), emailAddress(email) {}

    virtual void showDetails() const {
        cout << "Full Name: " << fullName << "\nID: " << uniqueID
             << "\nAddress: " << homeAddress << "\nContact: " << contactNumber
             << "\nEmail: " << emailAddress << endl;
    }

    virtual void modifyDetails(string newAddress, string newPhone, string newEmail) {
        homeAddress = newAddress;
        contactNumber = newPhone;
        emailAddress = newEmail;
    }

    virtual ~Person() {}
};

// Derived class: Student
class Student : public Person {
private:
    vector<string> enrolledCourses;
    double gradePointAverage;
    int yearOfEnrollment;
public:
    Student(string name, string id, string address, string phone, string email, int year, double gpa)
        : Person(name, id, address, phone, email), yearOfEnrollment(year), gradePointAverage(gpa) {}

    void registerCourse(const string& courseTitle) {
        enrolledCourses.push_back(courseTitle);
    }

    void showDetails() const override {
        Person::showDetails();
        cout << "Year of Enrollment: " << yearOfEnrollment << "\nGPA: " << gradePointAverage << "\nCourses: ";
        for (const string& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived class: Professor
class Professor : public Person {
private:
    string departmentName;
    vector<string> assignedCourses;
    double annualSalary;
public:
    Professor(string name, string id, string address, string phone, string email, string department, double salary)
        : Person(name, id, address, phone, email), departmentName(department), annualSalary(salary) {}

    void allocateCourse(const string& courseTitle) {
        assignedCourses.push_back(courseTitle);
    }

    void showDetails() const override {
        Person::showDetails();
        cout << "Department: " << departmentName << "\nAnnual Salary: $" << annualSalary << "\nAssigned Courses: ";
        for (const string& course : assignedCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Derived class: Staff
class Staff : public Person {
private:
    string workDepartment;
    string jobTitle;
    double monthlySalary;
public:
    Staff(string name, string id, string address, string phone, string email, string department, string position, double salary)
        : Person(name, id, address, phone, email), workDepartment(department), jobTitle(position), monthlySalary(salary) {}

    void showDetails() const override {
        Person::showDetails();
        cout << "Department: " << workDepartment << "\nJob Title: " << jobTitle << "\nMonthly Salary: $" << monthlySalary << endl;
    }
};

// Class: Course
class Course {
private:
    string courseCode, courseTitle, instructorName, classSchedule;
    int creditHours;
public:
    Course(string code, string title, int credits, string instructor, string schedule)
        : courseCode(code), courseTitle(title), creditHours(credits), instructorName(instructor), classSchedule(schedule) {}

    void addStudent(Student& student) {
        student.registerCourse(courseTitle);
    }

    void showCourseDetails() const {
        cout << "Course Code: " << courseCode << "\nCourse Title: " << courseTitle
             << "\nCredit Hours: " << creditHours << "\nInstructor: " << instructorName
             << "\nSchedule: " << classSchedule << endl;
    }
};

// Main function
int main() {
    // Creating instances
    Student student1("Alice Johnson", "S123", "123 Maple Street", "555-1234", "alice@email.com", 2022, 3.8);
    Professor professor1("Dr. Robert Smith", "P456", "456 Oak Avenue", "555-5678", "smith@email.com", "Computer Science", 75000);
    Staff staff1("Mr. John Miller", "ST789", "789 Pine Road", "555-9876", "john@email.com", "Administration", "Manager", 50000);
    Course course1("CS101", "Introduction to Programming", 3, "Dr. Robert Smith", "MWF 9 AM");

    // Assigning courses
    professor1.allocateCourse("Introduction to Programming");

    // Registering student in the course
    course1.addStudent(student1);

    // Displaying details
    cout << "\n--- Student Information ---\n";
    student1.showDetails();
    
    cout << "\n--- Professor Information ---\n";
    professor1.showDetails();

    cout << "\n--- Staff Information ---\n";
    staff1.showDetails();

    cout << "\n--- Course Details ---\n";
    course1.showCourseDetails();

    return 0;
}
