//
// Created by cemsr on 15.12.2023.
//
#include "Hobies.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Hobie::display(){

}
Hobie::Hobie(int id,int relatedsports,string hobies){
    this->ID=id;
    this->RelatedSports=relatedsports;
    this->Hobies=hobies;

}

void Hobie::add(int id,int relatedsports,string hobies){
    Hobie newhobi(id,relatedsports,hobies);
    hobie.push_back(newhobi);
}
void Hobie::remove(int id,int relatedsports,string hobies){
    Hobie newhobi(id,relatedsports,hobies);
    hobie.pop_back();
}

void Hobie::update() {

    string newHobie;
    cout << "Enter your new hobie:";
    getline(cin,newHobie);
    setHobies(newHobie);
}
void Hobie::setHobie(const vector<Hobie> &hobie) {
    Hobie::hobie = hobie;
}

int Hobie::getRelatedsports() const {
    return RelatedSports;
}

void Hobie::setRelatedsports(int relatedsports) {
    Hobie::RelatedSports = relatedsports;
}

const string &Hobie::getHobies() const {
    return Hobies;
};

