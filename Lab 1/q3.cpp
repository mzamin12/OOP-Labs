#include <iostream>
#include <string>
using namespace std;

int main(){
    int id, unit;
    float total, sur;
    string name;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your unit: ";
    cin >> unit;
    cout << "Customer ID: " << id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << unit << endl;
    if (unit < 199)
    {
        total = unit*16.20;
        cout << "Amount Charges @Rs. 16.20 per unit: " << total << endl;
    }
    else if (unit < 300)
    {
        total = unit*20.10;
        cout << "Amount Charges @Rs. 20.10 per unit: " << total << endl;
    }
    else if (unit < 500)
    {
        total = unit*27.10;
        cout << "Amount Charges @Rs. 27.10 per unit: " << total << endl;
    }
    else
    {
        total = unit*35.90;
        cout << "Amount Charges @Rs. 35.90 per unit: " << total << endl;
    }
    if (total > 18000)
    {
        sur = total*0.15;
        cout << "Surcharge Amount: " << sur << endl;
    }
    cout << "Net Amount Paid by the Customer: " << total+sur << endl;
}