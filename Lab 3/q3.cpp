#include <iostream>
using namespace std;

class Glass{
    public:
        int LiquidLevel = 200;
        void Drink(int ml){
            LiquidLevel = LiquidLevel - ml;
        }
        void Refill(){
            if (LiquidLevel <= 100)
            {
                LiquidLevel = 200;
                cout << "Glass refilled" << endl;
            }
        }
};

int main(){
    Glass glass;
    int ml = 0;
    while (ml != -1)
    {
        cout << "Enter milliliters drank (-1 to exit): ";
        cin >> ml;
        glass.Drink(ml);
        glass.Refill();
    }
    cout << "Exiting...";
}