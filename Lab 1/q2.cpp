#include <iostream>
using namespace std;

int main(){
    float arr[20];
    float sum = 0;
    for (int i = 0; i < 20; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum;
}