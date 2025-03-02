#include <iostream>
#include <windows.h>
using namespace std;

class Blend {
public:
    void blendJuice() {
        for (int i = 1; i <= 5; i++) {
            cout << "Blending your juice... (" << i << " seconds passed)" << endl;
            Sleep(1000);
            system("cls");
        }
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        for (int i = 1; i <= 5; i++) {
            cout << "Grinding your ingredients... (" << i << " seconds passed)" << endl;
            Sleep(1000);
            system("cls");
        }
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
    Blend b;
    Grind g;

public:
    void makeJuice() {
        cout << "Starting the juice-making process..." << endl;
        b.blendJuice();
        g.grindJuice();
        cout << "Your fresh juice is now ready to enjoy!" << endl;
    }
};

int main() {
    JuiceMaker JM;
    JM.makeJuice();
    return 0;
}
