#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptString(const string& inputString) {
    string encryptedText = "";
    for (size_t i = 0; i < inputString.length(); ++i) {
        char encryptedChar = inputString[i] + (i + 1);
        encryptedText += encryptedChar;
    }
    return encryptedText;
}

string decryptString(const string& encryptedText) {
    string decryptedText = "";
    for (size_t i = 0; i < encryptedText.length(); ++i) {
        char decryptedChar = encryptedText[i] - (i + 1);
        decryptedText += decryptedChar;
    }
    return decryptedText;
}

void saveEncryptedTextToFile(const string& encryptedText, const string& filename = "encrypted_text.txt") {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << encryptedText;
        outFile.close();
        cout << "Encrypted text inserted in file" << endl;
    } else {
        cout << "Failed to open file for writing!" << endl;
    }
}

string readEncryptedTextFromFile(const string& filename = "encrypted_text.txt") {
    ifstream inFile(filename);
    string encryptedText = "";
    if (inFile.is_open()) {
        getline(inFile, encryptedText);
        inFile.close();
    } else {
        cout << "Failed to open file for reading!" << endl;
    }
    return encryptedText;
}

int main() {
    string inputString;
    cout << "Enter String = ";
    getline(cin, inputString);

    cout << "Normal Text:= " << inputString << endl;

    string encryptedText = encryptString(inputString);

    saveEncryptedTextToFile(encryptedText);

    cout << "Encrypted text: " << encryptedText << endl;

    string encryptedTextFromFile = readEncryptedTextFromFile();

    string decryptedText = decryptString(encryptedTextFromFile);

    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decryptedText << endl;

    return 0;
}
