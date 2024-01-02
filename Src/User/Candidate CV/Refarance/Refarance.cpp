//
// Created by 90554 on 2.01.2024.
//
#include "Refarance.h"
#include <iostream>

// Static vector definition
vector<Reference> Reference::references;

// Default constructor
Reference::Reference() : name(""), position(""), phoneNumber("") {}

// Parametrized constructor
Reference::Reference(const string& name, const string& position, const string& phoneNumber)
        : name(name), position(position), phoneNumber(phoneNumber) {}

// Destructor
Reference::~Reference() {}

// Getter implementations
string Reference::getName() const {
    return name;
}

string Reference::getPosition() const {
    return position;
}

string Reference::getPhoneNumber() const {
    return phoneNumber;
}

// Display function
void Reference::display() const {
    cout << "Name: " << getName() << endl;
    cout << "Position: " << getPosition() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
}

// Update function
void Reference::update(const string& name, const string& position, const string& phoneNumber) {
    this->name = name;
    this->position = position;
    this->phoneNumber = phoneNumber;
}

// Add new reference to the static vector
void Reference::addReference(const string& name, const string& position, const string& phoneNumber) {
    Reference newReference(name, position, phoneNumber);
    references.push_back(newReference);
}

// Static function to display all references
void Reference::displayAllReferences() {
    for (size_t i = 0; i < references.size(); i++) {
        references[i].display();
        cout << endl;
    }
}
