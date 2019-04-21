/*
	Author: Talha Rahman
	Course: CSCI-136
	Instructor: Minh Nguyen
	Assignment: Lab 11
*/
// This program acts like a network and you can add 
// users to the network
#include <iostream>
#include <string>
//#include "profile.h"
//#include "network.h"
using namespace std;

class Profile{
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn) : username(usrn), displayname(dspn) {}

Profile::Profile() : username(""), displayname(""){}

string Profile::getUsername() {
    return this->username;
}
string Profile::getFullName() {
    return this->displayname + " (@" + this->username + ")";
}
void Profile::setDisplayName(string dspn){
    this->displayname = dspn;
}

class Network {
private:
    static const int MAX_USERS = 20;// max number of user profiles
    int numUsers;                   // number of registered users
    Profile profiles[MAX_USERS];    // user profiles array:
                                    // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn) {
        for (int i = 0; i < MAX_USERS; i++){
            if (profiles[i].getUsername() == usrn) return i;
        }
        return -1;
    }
    bool following[MAX_USERS][MAX_USERS]; // friendship matrix;
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2){
        if ((findID(usrn1) == -1) || (findID(usrn2) == -1)) return false;
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }

    void printDot(){
        cout << "digraph {\n";
        for (int i = 0; i < numUsers; i++) {
            cout << "  \"@" + profiles[i].getUsername() + "\"\n";
        }

        for (int i = 0; i < numUsers; i++) {
            for (int j = 0; j < numUsers; j++){
                if (following[i][j]){
                    cout << "  \"@" + profiles[i].getUsername() + "\" -> ";
                    cout << "  \"@" + profiles[j].getUsername() + "\"\n";
                }
            }
        }
        cout << "}";
    }
};

Network::Network() : numUsers(0){
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn){
    if(numUsers == MAX_USERS) return false;
    if(usrn.empty()) return false;
    for (char& x : usrn){
        if (!isalnum(x)) return false;
    }
    for(Profile& x : profiles){
        if (x.getUsername() == usrn) return false;
    }
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
