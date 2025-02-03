#include <iostream>
using namespace std;

struct person
{
    int id;
    string name;
};

int main(){
    int N;
    cout << "Enter number of people: ";
    cin >> N;
    person p[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Person " << i+1 << " id"  << ": ";
        cin >> p[i].id;
        cout << "Person " << i+1 << " name"  << ": ";
        cin >> p[i].name;
    }
    cout << endl;

    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            if (p[j].id > p[j+1].id)
            {
                person temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;  
            }            
        }        
    }
    for (int i = 0; i < N; i++)
    {
        cout << "ID: " << p[i].id << "  Name: " << p[i].name << endl;
    }
    cout << endl;

    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            if (p[j].name[0] > p[j+1].name[0])
            {
                person temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;  
            }            
        }        
    }
    for (int i = 0; i < N; i++)
    {
        cout << "ID: " << p[i].id << "  Name: " << p[i].name << endl;
    }
    
} 