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
#include <algorithm>
using namespace std;

void capitalize(string&);
void readFile(const string&);
const string transcription(string&);

// TODO
void translation(const string& strand){
    ifstream infile("codons.tsv");
    string mrna;
    string codon;


    if(infile.good()){
        while (infile >> mrna >> codon){
            if (true){
                cout << codon << "\n";
            }
        }
    } else {
        cerr << "The file 'codons.tsv' cannot be read\n";
        exit(2);
    }
}


int main(){
    readFile("dna.txt");

}

void capitalize(string& strand){
    for (int i = 0; i < strand.size(); i++){
        strand[i] = toupper(strand[i]);
    }
}

void readFile(const string& filePath){
    ifstream infile(filePath);
    string strand;

    if(infile.good()){
        while (getline(infile, strand)){
            capitalize(strand);
            cout << transcription(strand) << "\n";
            //translation(strand);
        }
    } else {
        cerr << "The file " << filePath << " cannot be read\n";
        exit(1);
    }
}

const string transcription(string& strand){
    replace(strand.begin(), strand.end(), 'A', 'U');
    replace(strand.begin(), strand.end(), 'T', 'A');
    replace(strand.begin(), strand.end(), 'C', 'X');
    replace(strand.begin(), strand.end(), 'G', 'C');
    replace(strand.begin(), strand.end(), 'X', 'G');
    return strand;
}
