//
// Created by cemsr on 15.12.2023.
//
#include "Hobie.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Hobie::Hobie() {}

void Hobie::display(){
    cout << "Your Hobbies:" << endl;
    for (int i = 0; i < hobie.size(); ++i) {
        cout << hobie[i].Hobies << endl;
    }
}
Hobie::Hobie(int id,string hobies){
    this->ID=id;
    this->Hobies=hobies;

}

void Hobie::add(int id,string hobies){
    Hobie newhobi(id,hobies);
    hobie.push_back(newhobi);
}
void Hobie::remove(int id,string hobies){
    Hobie newhobi(id,hobies);
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


const string &Hobie::getHobies() const {
    return Hobies;
}

void Hobie::setHobies(const string &hobies) {
    Hobies = hobies;
};

