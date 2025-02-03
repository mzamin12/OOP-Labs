// Write a program that can resize a single dimension int array if the elements exceed the total size.
// Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
// the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
// the elements present in the array.

#include <iostream>
using namespace std;

int main(){
    int max_size = 5, count = 0;
    int num = 0;
    int *arr = new int[max_size];
    while (num != -1)
    {
        cout << "Enter -1 to exit: " ;
        cin >> num;
        if (num != -1 && count < max_size)
        {
            arr[count] = num;
            count++;
        }
        else if (count > max_size)
        {
            int *newArr = new int[2*max_size];
            max_size = max_size * 2;
            for (int i = 0; i < count; i++)
            {
                newArr[i] = arr[i]; 
            }
            delete[] arr;
            arr = newArr;             
        }  
    }
    int *newArr = new int[count];
    for (int i = 0; i < count; i++)
    {
        newArr[i] = arr[i];
    }         
    delete[] arr;
    arr = newArr;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}