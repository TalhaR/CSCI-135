#include "profile.h"
#include <string>
using std::string;

Profile::Profile(string usrn, string dspn) : username(usrn), displayname(dspn) {};

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