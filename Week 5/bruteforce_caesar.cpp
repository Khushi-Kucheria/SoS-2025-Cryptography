#include <iostream>
#include <string>
using namespace std;

// Decrypt Caesar cipher with given shift
string caesarDecrypt(string ciphertext, int shift) {
    string decrypted = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            decrypted += (char)(((c - base - shift + 26) % 26) + base);
        } else {
            decrypted += c;
        }
    }
    return decrypted;
}

int main() {
    string ciphertext = "Wklv lv d vhfuhw"; // "This is a secret" with key 3

    cout << "Brute Force Caesar Attack:\n";
    for (int key = 1; key < 26; ++key) {
        string decrypted = caesarDecrypt(ciphertext, key);
        cout << "Key " << (key < 10 ? " " : "") << key << ": " << decrypted << endl;
    }

    return 0;
}
