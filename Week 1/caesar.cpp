#include<iostream>
#include<string>
#include <cctype>
using namespace std;

void encryption(string plaintext,int key){
    string ciphertext ="";
    for (char c : plaintext){
        if(isupper(c)){
            ciphertext +=char((c-'A'+key)%26 + 'A');
        }
        else if(islower(c)){
            ciphertext +=char((c-'a'+key)%26 + 'a');
        }
        else{
            ciphertext += c;
        }        
    }
    cout<<ciphertext;
}

int main(){
    std::string text;
    int key;
    char choice;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift key: ";
    cin >> key;
    cout << "What do you want to do? E/D :";
    cin>>choice;
    if(choice == 'E'){
        encryption(text,key);
    }
    else if(choice == 'D'){
        encryption(text,-key);
    }
    else{
        cout<<"Enter Valid Choice !";
    }
    
   return 0; 
}