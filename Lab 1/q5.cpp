#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    cout << fixed << setprecision(2);
    string name; 
    int no_adult, no_child;
    float adult_prize, child_prize, gross, total, donate;
    cout << "Enter movie name: ";
    cin >> name;
    cout << "Enter adult ticket prize: ";
    cin >> adult_prize;
    cout << "Enter child ticket prize: ";
    cin >> child_prize;
    cout << "Enter number of adult tickets: ";
    cin >> no_adult;
    cout << "Enter number child tickets: ";
    cin >> no_child;
    cout << "Enter gross amount: ";
    cin >> gross;
    total = no_adult*adult_prize + no_child*child_prize;
    donate = total*(gross/100);
    cout << "****************************************************************" << endl;
    cout << "Movie Name:............................ " << name << endl;
    cout << "Number of Tickets Sold:................." << no_adult+no_child << endl;
    cout << "Gross Amount:..........................$" << total << endl;
    cout << "Percentage of Gross Amount Donated:....." << gross << "%" << endl;
    cout << "Amount Donated:........................$" << donate << endl;
    cout << "Net Sale:..............................$" << total - donate << endl;
}