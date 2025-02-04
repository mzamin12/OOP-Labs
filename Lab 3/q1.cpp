#include <iostream>
using namespace std;

class User
{
public:
    string name;
    int age;
};

int main(){
    User user;
    user.name = "Zamin";
    user.age = 19;
    cout << "My name is " << user.name << " and I'm " << user.age << " years old.";
}