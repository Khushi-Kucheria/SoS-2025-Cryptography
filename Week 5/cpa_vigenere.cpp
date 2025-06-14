#include <iostream>
#include <string>
using namespace std;

// Vigenère Encryption
string vigenereEncrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyLen = key.length();
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char p = toupper(plaintext[i]);
        char k = toupper(key[i % keyLen]);
        if (isalpha(p)) {
            char c = (p - 'A' + (k - 'A')) % 26 + 'A';
            ciphertext += c;
        } else {
            ciphertext += p;
        }
    }
    return ciphertext;
}

// Perform Chosen-Plaintext Attack
string recoverKeyFromAttack(string plaintext, string ciphertext) {
    string recoveredKey = "";
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        if (isalpha(ciphertext[i]) && isalpha(plaintext[i])) {
            char p = toupper(plaintext[i]);
            char c = toupper(ciphertext[i]);
            char k = (c - p + 26) % 26 + 'A';
            recoveredKey += k;
        }
    }
    return recoveredKey;
}

int main() {
    // Step 1: Choose known plaintext
    string chosenPlaintext = "AAAAAAAAAAAA"; // Repeating 'A' reveals key directly

    // Step 2: Encrypt with secret key
    string realKey = "KEY";
    string ciphertext = vigenereEncrypt(chosenPlaintext, realKey);

    cout << "Chosen Plaintext: " << chosenPlaintext << endl;
    cout << "Ciphertext:       " << ciphertext << endl;

    // Step 3: Recover the key using chosen plaintext attack
    string recovered = recoverKeyFromAttack(chosenPlaintext, ciphertext);
    cout << "Recovered Key (first part): " << recovered << endl;

    // Step 4: Guess key length
    cout << "Guessed key length: ";
    for (size_t len = 1; len <= recovered.length() / 2; ++len) {
        if (recovered.substr(0, len) == recovered.substr(len, len)) {
            cout << len << " (repeating pattern detected: " << recovered.substr(0, len) << ")" << endl;
            break;
        }
    }

    return 0;
}
