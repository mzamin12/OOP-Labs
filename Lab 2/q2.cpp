#include<iostream>
using namespace std;

void* sum (void* arr, int size){
    int sum = 0;
    int *ptr = (int*)arr;
    for (int i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }
    void* out = (void*)&sum;
    return (void*)out;
}

int main(){
    int size = 6;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }
    
    void* out =sum((void*)arr, size);
    cout<< "Sum: " <<*(int*)out;
}
        cin >> arr[i];
    }
    
	void* out =sum((void*)&arr, size);
	cout<< "Sum: " <<*(int*)out;
}
