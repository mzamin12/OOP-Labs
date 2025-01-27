#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    cout << fixed << setprecision(2);
    string name;
    float test1, test2, test3, test4, test5;
    cin >> name >> test1 >> test2 >> test3 >> test4 >> test5;
    cout << "Students Name: " << name << endl;
    cout << "Test Scores: " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5 << endl;
    cout << "Average test scores: " << (test1+test2+test3+test4+test5)/5;
}