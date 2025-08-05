// FileEncryptor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string caesarCipher(const string& text, int shift, bool encrypt) {
    string result;
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            if (encrypt)
                result += (ch - base + shift) % 26 + base;
            else
                result += (ch - base - shift + 26) % 26 + base;
        }
        else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string filename, line, content;
    int choice, shift;

    cout << "=== File Encryption/Decryption Tool ===\n";
    cout << "Enter the filename (e.g., message.txt): ";
    getline(cin, filename);

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: File not found.\n";
        return 1;
    }

    while (getline(inFile, line)) {
        content += line + '\n';
    }
    inFile.close();

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;
    if (choice != 1 && choice != 2) {
        cerr << "Invalid choice.\n";
        return 1;
    }

    cout << "Enter Caesar Cipher shift value: ";
    cin >> shift;

    string result = caesarCipher(content, shift, choice == 1);

    string outputFilename;
    if (choice == 1)
        outputFilename = "output_encrypted.txt";
    else
        outputFilename = "output_decrypted.txt";

    ofstream outFile(outputFilename);
    outFile << result;
    outFile.close();

    cout << "Operation complete. Output saved to: " << outputFilename << endl;

    return 0;
}

