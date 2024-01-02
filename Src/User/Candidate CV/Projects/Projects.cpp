//
// Created by cemsr on 15.12.2023.
//
#include "Projects.h"
#include <iostream>
using namespace std;

// Static vector definition
vector<Project> Project::projects;

// Default constructor
Project::Project(string name,string description,string startdate,string enddate) {
    this->Name = name;
    this->Description = description;

}

// Parametrized constructor
/*Project::Project(const string& name, const string& description, const string& startDate, const string& endDate)
        : Name(name), Description(description), StartDate(startDate), EndDate(endDate) {}*/

// Destructor
Project::~Project() {
}

// Display function
void Project::display() const {
    cout << "Project Name: " << Name << endl;
    cout << "Description: " << Description << endl;
    cout << "Start Date: " << StartDate << endl;
    cout << "End Date: " << EndDate << endl;
}

// Update function
void Project::update(const string& name, const string& description, const string& startDate, const string& endDate) {
    this->Name = name;
    this->Description = description;
    this->StartDate = startDate;
    this->EndDate = endDate;
}

// Add new Project to the static vector
void Project::addProject(const string& name, const string& description, const string& startDate, const string& endDate) {
    Project newProject(name, description, startDate, endDate);
    projects.push_back(newProject);
}

// Static function to display all projects
void Project::displayAllProjects() {
    for (size_t i = 0; i < projects.size(); i++) {
        projects[i].display();
        cout << endl;
    }
}
string Project::getName(){
    return this->Name;
}
string Project::getDescription() {
    return this->Description;
}
string Project::getStartDate(){
    return this->StartDate;
}
string Project::getEndDate(){
    return this->EndDate;
}