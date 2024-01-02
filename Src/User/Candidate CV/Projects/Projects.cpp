//
// Created by cemsr on 15.12.2023.
//
#include "Projects.h"
#include <iostream>
using namespace std;

// Static vector definition
vector<Project> Project::projects;

// Default constructor
Project::Project() : name(""), description(""), startDate(""), endDate("") {}

// Parametrized constructor
Project::Project(const string& name, const string& description, const string& startDate, const string& endDate)
        : name(name), description(description), startDate(startDate), endDate(endDate) {}

// Destructor
Project::~Project() {
}

// Display function
void Project::display() const {
    cout << "Project Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << endDate << endl;
}

// Update function
void Project::update(const string& name, const string& description, const string& startDate, const string& endDate) {
    this->name = name;
    this->description = description;
    this->startDate = startDate;
    this->endDate = endDate;
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
