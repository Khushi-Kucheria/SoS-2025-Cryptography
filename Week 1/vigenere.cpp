#include<iostream>
#include<string>
#include <cctype>
using namespace std;

void encryption(string plaintext,string keyword){
    for(int i=0; i < plaintext.length(); i++){
        plaintext[i] = toupper(plaintext[i]);
    }
    for(int i=0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    string ciphertext = "";

    for (int i=0; i < plaintext.length(); i++){
        if (isalpha(plaintext[i])){
            char p_index = plaintext[i] - 'A';
            char k_index= keyword[i%keyword.length()] - 'A';
            ciphertext += (p_index + k_index)%26 + 'A';
        }
        else {
            ciphertext += plaintext[i];
        }
    }
    cout<<ciphertext;
}

void decryption(string ciphertext,string keyword){
    for(int i=0; i < ciphertext.length(); i++){
        ciphertext[i] = toupper(ciphertext[i]);
    }
    for(int i=0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    string plaintext = "";

    for (int i=0; i < ciphertext.length(); i++){
        if (isalpha(ciphertext[i])){
            char c_index = ciphertext[i] - 'A';
            char k_index= keyword[i%keyword.length()] - 'A';
            plaintext += (c_index - k_index +26 ) % 26 + 'A';
        }
        else {
            plaintext += ciphertext[i];
        }
    }
    cout<<plaintext;
}


int main(){
    string text;
    string keyword;
    char choice;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift key: ";
    getline(cin, keyword);
    cout << "What do you want to do? E/D :";
    cin>>choice;
    if(choice == 'E'){
        encryption(text,keyword);
    }
    else if(choice == 'D'){
        decryption(text,keyword);
    }
    else{
        cout<<"Enter Valid Choice !";
    }
    
   return 0; 
}
