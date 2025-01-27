#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double weight_kg, weight_lb;
    cout << "Enter weight in kilograms: ";
    cin >> weight_kg;
    weight_lb = weight_kg*2.2;
    cout << fixed << setprecision(2);
    cout << "Weight in Kgs: " << weight_kg << endl;
    cout << "Weight in Lbs: " << weight_lb <<  endl;
}
