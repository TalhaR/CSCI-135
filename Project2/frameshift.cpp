/*
Author: Talha Rahman
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2
*/

// This program reads a file called "frameshift_mutations.txt"
// and then prints out the translation->translation of that stuff
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void capitalize(string&); // capitalizes all inputs
void replace(string&, char, char); // replaces characters in a string 
void readFile(const string&);
void transcription(string&); // uses replace method to convert from DNA to RNA
string readCodons(ifstream&, string&); // reads the codons.tsv file and returns a codon
string translation(ifstream&, string&); // uses the readcodons method to make a string
int hamming(const string&, const string&);
void filter(string&);

int main(){
    readFile("frameshift_mutations.txt");
    //readFile("test2.txt");
}

void filter(string& s){
    if(s.find("AUG") == string::npos){
        s = "";
    } else {
        s = s.substr(s.find("AUG"));
    }
}

void readFile(const string& filePath){
    ifstream infile(filePath);
    ifstream codonsFile("codons.tsv");
    string strand;

    if(infile.good()){
        while (getline(infile, strand)){
            capitalize(strand);
            transcription(strand);
            filter(strand);
            if (!strand.empty()){
                strand = translation(codonsFile, strand);
            }
            if (strand.back() == '-'){
                strand.pop_back();
            }
            cout << strand << "\n";
        }
    } else {
        cerr << "The file " << filePath << " cannot be read\n";
        exit(1);
    }
}
int hamming(const string& a, const string& b){
    int count = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]){
            count++;
        }
    }
    return count;
}

string translation(ifstream& infile, string& strand){
    string mrna, codon;
    infile.clear();
    infile.seekg(0);

    vector<string> aminos;
    string temp = "";
    string result = "";

    for (auto& x : strand){
        temp += x;
        if (temp.size() == 3){
            aminos.push_back(temp);
            temp.clear();
        }
    }

    if(infile.good()){
        for (auto& x : aminos){
            string c = readCodons(infile, x);
            if (c == "Stop"){
                result.pop_back();
                return result;
            } 
            result += c;
            result += "-";
            
            if (result.substr(0,3) != "Met"){
                result.clear();
            }
        }
    } else {
        cerr << "The file 'codons.tsv' cannot be read\n";
        exit(2);
    }
}

string readCodons(ifstream& infile, string& amino){
    string mrna, codon;
    infile.clear();
    infile.seekg(0);

    while(infile >> mrna >> codon){
        if (amino == mrna){
            return codon;
        }
    }
}

void transcription(string& strand){
    replace(strand, 'A', 'U');
    replace(strand, 'T', 'A');
    replace(strand, 'C', 'X'); // need to move this to temp value 
    replace(strand, 'G', 'C');
    replace(strand, 'X', 'G');
}

void replace(string& str, char a, char b){
    for(auto& x : str){
        if (x == a){
            x = b;
        }
    }
}

void capitalize(string& strand){
    for (int i = 0; i < strand.size(); i++){
        strand[i] = toupper(strand[i]);
    }
}