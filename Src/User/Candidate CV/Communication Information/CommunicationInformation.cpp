//
// Created by cemsr on 15.12.2023.
//


#include "CommunicationInformation.h"
#include <iostream>

// Static vector definition
vector<CommunicationInformation> CommunicationInformation::infos;

// Default constructor
CommunicationInformation::CommunicationInformation() : email(""), phone(""), address("") {}

// Parametrized constructor
CommunicationInformation::CommunicationInformation( string email,string phone,string address)
         {   this->email =email;
             this->phone =email;
             this->address =email;
         }

// Destructor
CommunicationInformation::~CommunicationInformation() {}

// Getter implementations
string CommunicationInformation::getEmail(){
    return  this->email;
}

string CommunicationInformation::getPhone(){
    return  this->phone;
}

string CommunicationInformation::getAddress(){
    return this->address;
}

// Display function
void CommunicationInformation::display(){
    cout << "Email: " << getEmail() << endl;
    cout << "Phone: " << getPhone() << endl;
    cout << "Address: " << getAddress() << endl;
}

// Update function
void CommunicationInformation::update(const string& email, const string& phone, const string& address) {
    this->email = email;
    this->phone = phone;
    this->address = address;
}

// Add new information to the static vector
void CommunicationInformation::addInfo(const string& email, const string& phone, const string& address) {
    CommunicationInformation newInfo(email, phone, address);
    infos.push_back(newInfo);
}

// Static function to display all information
void CommunicationInformation::displayAllInfo() {
    for (size_t i = 0; i < infos.size(); i++) {
        infos[i].display();
        cout << endl;
    }
}

void CommunicationInformation::addCommuni(int i, string basicString, string basicString1, string basicString2) {

}

void CommunicationInformation::addReference(int i, string basicString, string basicString1, string basicString2) {

}

