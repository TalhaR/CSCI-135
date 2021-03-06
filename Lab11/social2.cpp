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
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};

Network::Network() : numUsers(0){}

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
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                    "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
