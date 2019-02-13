/*
Author: Talha Rahman
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab 3D
*/

// This program asks the user for two dates (one earlier than the other)
// It then reports the west basin elevation for all the days in that interval
// in reverse chronological order
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    string earlierDate;
    string laterDate;

    cout << "Enter earlier date: ";
    cin >> earlierDate; 
    cout << "Enter later date: ";
    cin >> laterDate; 

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr << "File cannot be opened for reading.\n";
        exit(1); // exit if failed to open file
    }

    string junk; // used to store & ignore header of file
    getline(fin, junk);

    string date;
    vector<string> dates;
    vector<double> elevations;

    double eastSt, eastEl, westSt, westEl;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // skips the end of line and remaining collumns 

        if ((date >= earlierDate) && (date <= laterDate)){
            dates.push_back(date);
            elevations.push_back(westEl);
        }
    }

    for (int i = dates.size()-1; i >= 0; i--){
        cout << dates[i] << " " << elevations[i] << " ft\n";
    }

    fin.close();
}