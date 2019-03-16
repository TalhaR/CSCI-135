/*
Author: Talha Rahman
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2
*/

// This program reads a file called "dna.txt"
// then converts the DNA strands to RNA strands
// and prints it out to screen
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void capitalize(string&); // capitalizes all inputs
void replace(string&, char, char); // replaces characters in a string 
void readFile(const string&);
const string transcription(string&); // uses replace method to convert from DNA to RNA

// TODO
string translation(ifstream& infile, const string& strand){
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
        while (infile >> mrna >> codon){
            for (auto& x : aminos){
                if ((x == mrna) && (codon != "Stop")){
                    result += codon;
                    result += "-";
                }
            }
        }
        result.pop_back();
        return result;
    } else {
        cerr << "The file 'codons.tsv' cannot be read\n";
        exit(2);
    }
}

int main(){
    readFile("dna2.txt");
    
}

void readFile(const string& filePath){
    ifstream infile(filePath);
    ifstream codonsFile("codons.tsv");
    string strand;

    if(infile.good()){
        while (getline(infile, strand)){
            capitalize(strand);
            cout << transcription(strand) << "\n\n";
            cout << translation(codonsFile, strand);
        }
    } else {
        cerr << "The file " << filePath << " cannot be read\n";
        exit(1);
    }
}

const string transcription(string& strand){
    replace(strand, 'A', 'U');
    replace(strand, 'T', 'A');
    replace(strand, 'C', 'X'); // need to move this to temp value 
    replace(strand, 'G', 'C');
    replace(strand, 'X', 'G');
    return strand;
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
