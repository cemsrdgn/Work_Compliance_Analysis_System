//
// Created by cemsr on 15.12.2023.
//

#include "ExpertiseAreas.h"
#include <iostream>
using namespace std;

// Static vector definition
vector<ExpertiseArea> ExpertiseArea::areas;

// Default constructor
ExpertiseArea::ExpertiseArea() : areaName(""), description("") {}

// Parametrized constructor
ExpertiseArea::ExpertiseArea(const string& areaName, const string& description)
        : areaName(areaName), description(description) {}

// Destructor
ExpertiseArea::~ExpertiseArea() {
}

// Display function
void ExpertiseArea::display() const {
    cout << "Area Name: " << areaName << endl;
    cout << "Description: " << description << endl;
}

// Update function
void ExpertiseArea::update(const string& areaName, const string& description) {
    this->areaName = areaName;
    this->description = description;
}

// Add new ExpertiseArea to the static vector
void ExpertiseArea::addArea(const string& areaName, const string& description) {
    ExpertiseArea newArea(areaName, description);
    areas.push_back(newArea);
}

// Static function to display all areas
void ExpertiseArea::displayAllAreas() {
    for (size_t i = 0; i < areas.size(); i++) {
        areas[i].display();
        cout << endl;
    }
}

