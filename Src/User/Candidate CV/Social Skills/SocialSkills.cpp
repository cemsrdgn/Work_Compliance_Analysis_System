//
// Created by cemsr on 15.12.2023.
//
#include "SocialSkills.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void SocialFactors::display(){

}
SocialFactors::SocialFactors(int id,string socialfactors=" ",string volunteerwork=" ") {

    this->ID=id;
    this->SocialFactor=socialfactors;
    this->volunteerwork=volunteerwork;

}

void SocialFactors::add(int id,string socialfactors=" ",string volunteerwork=" "){
    SocialFactors newsocial(id,socialfactors,volunteerwork);
    Social.push_back(newsocial);
}

void SocialFactors::remove(int id,string socialfactors=" ",string volunteerwork=" ") {
    SocialFactors newsocial(id,socialfactors,volunteerwork);
    Social.pop_back();
}

void SocialFactors::update() {

    string newSocial;
    cout << "Enter your social factors:";
    getline(cin,newSocial);
    setSocialfactors(newSocial);
}
void SocialFactors::setSocialfactors(const std::string &socialfactors) {
    SocialFactors::SocialFactor = SocialFactor;
}

const vector<SocialFactors> &SocialFactors::getSocial() const {
    return Social;
}

void SocialFactors::setSocialFactor(const string &socialFactor) {
    SocialFactor = socialFactor;
}

void SocialFactors::setSocial(const vector<SocialFactors> &social) {
    Social = social;
}
