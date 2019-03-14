/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6B
*/

// This program asks the user for a string
// then shifts every character by 5 values
// for instance, all A's become F's
// after shifting all the values it will 
// print it out
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char, int);
string encryptCaesar(string, int);

int main(){
    string s;
    int a;
    cout << "Enter plaintext : ";
    getline(cin, s);
    cout << "Enter shift\t: ";
    cin >> a;

    cout << "Ciphertext\t: " << encryptCaesar(s, a) << "\n";
}

char shiftChar(char c, int rshift){
    if ((c <= 'Z') && (c >= 'A')) {
        int dif = (int)c - 65;

        if (dif + rshift > 25){
            return (char)(dif - 26 + 65 + rshift); 
        } else {
            return c + rshift;
        }
    } 
    if ((c <= 'z') && (c >= 'a')) {
        int dif = (int)c - 97;

        if (dif + rshift > 25){
            return (char)(dif - 26 + 97 + rshift); 
        } else {
            return c + rshift;
        }
    }
}

string encryptCaesar(string plaintext, int rshift){
    for (auto& x : plaintext){
        if (isalpha(x)){
            x = shiftChar(x, rshift);
        }
    }
    return plaintext;
}