/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 6C
*/

// This program asks the user for a string
// then encrypts it using the vignere cipher encyption technique
// and then prints out the encrypted string
// I hated this assignment
// it wasn't fun
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftChar(char&, int&);
string encryptVigenere(string, string);

int main(){
    string text;
    string keyword;

    cout << "Input: ";
    getline(cin, text);

    cout << "Keyword: ";
    cin >> keyword;

    cout << encryptVigenere(text, keyword);
}

char shiftChar(char& c, int& shift){
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