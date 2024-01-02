//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
#include <string>
#include <vector>
using namespace std;

class Project {
public:
    Project();  // Default constructor
    //Project(const string& name, const string& description, const string& startDate, const string& endDate);  // Parametrized constructor
    ~Project();  // Destructor
    Project(string name,string description,string startdate=" ",string enddate=" ");
    void display() const;
    void update(const string& name, const string& description, const string& startDate, const string& endDate);

    static void addProject(const string& name, const string& description, const string& startDate, const string& endDate);
    static void displayAllProjects();
    static vector<Project> projects;  // Static vector to store project instances
    string getName();
    string getDescription();
    string getStartDate();
    string getEndDate();
private:
    string Name;
    string Description;
    string StartDate;
    string EndDate;
};





#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
