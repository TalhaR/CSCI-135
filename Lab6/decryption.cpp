/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6D
*/

// This program 
// undoes all the work
// that the other cipher programs did
// I hated this assignment
// it wasn't fun
// I hated this assignment
// it wasn't fun
// I hated this assignment
// it wasn't fun
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char&, int);
string encryptVigenere(string, string);
string encryptCaesar(string, int);
string decryptCaesar(string, int);
string decryptVigenere(string, string);
int main(){
    string text;
    string keyword;
    int cshift;

    cout << "Plaintext : ";
    getline(cin, text);

    cout << "= Caesar =\n";
    cout << "Enter shift: ";
    cin >> cshift;
    cout << "Ciphertext: " << encryptCaesar(text, cshift);
    cout << "Decrypted: " << decryptCaesar(text, cshift);
    cout << "\n";

    cout << "= Vigenere =\n";
    cout << "Enter keyword: ";
    cin >> keyword;
    cout << "Ciphertext: " << encryptVigenere(text, keyword); 
    cout << "Decrypted: " << decryptVigenere(text, keyword);
}

char shiftChar(char& c, int shift){
    if ((c <= 'Z') && (c >= 'A')) {
        int dif = (int)c - 'A';

        if (dif + shift > 25){
            return (char)(dif - 26 + 'A' + shift); 
        } else {
            return c + shift;
        }
    } 
    if ((c <= 'z') && (c >= 'a')) {
        int dif = (int)c - 'a';

        if (dif + shift > 25){
            return (char)(dif - 26 + 'a' + shift); 
        } else {
            return c + shift;
        }
    } 
}

string encryptVigenere(string text, string keyword){
    string output = "";
    int shift;
    int numOtherChars = 0;

    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            shift = keyword[(i - numOtherChars) % keyword.size()] - 'a';
            output += shiftChar(text[i], shift);
        } else {
            output += text[i];
            numOtherChars += 1;
        }
    }
    return output;
}
string encryptCaesar(string plaintext, int rshift){
    for (auto& x : plaintext){
        if (isalpha(x)){
            x = shiftChar(x, rshift);
        }
    }
    return plaintext;
}

string decryptCaesar(string text, int shift){
    for (auto& x : text){
        if (isalpha(x)){
            x = shiftChar(x, 26 - shift);
        }
    }
    return text;
}   
string decryptVigenere(string text, string keyword){
    string output = "";
    int shift;
    int numOtherChars = 0;

    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            shift = 26 - (keyword[(i - numOtherChars) % keyword.size()] - 'a');
            output += shiftChar(text[i], shift);
        } else {
            output += text[i];
            numOtherChars += 1;
        }
    }
    return output;
}