#include <iostream>
using namespace std;

int main(){
    int size, sum = 0;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }
    int *ptr = arr;
    for (int i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }
    
    cout << "Sum: " << sum;
}