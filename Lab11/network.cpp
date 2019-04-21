#include "network.h"
#include <string>
using std::string;

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