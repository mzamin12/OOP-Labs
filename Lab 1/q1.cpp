#include <iostream>
using namespace std;

int main(){
    float arr[20];
    float max;
    max = 0;
    float max2;
    max2 = 0;
    for (int i = 0; i < 20; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
        if (arr[i] >= max)
        {
            max = arr[i];
        }    
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }
    }
    cout << max2;
}