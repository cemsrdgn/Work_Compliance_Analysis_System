//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
#include <string>
#include <vector>
using namespace std;


class Projects {
public:
    Project();  // Default constructor
    Project(const string& name, const string& description, const string& startDate, const string& endDate);  // Parametrized constructor
    ~Project();  // Destructor

    void display() const;
    void update(const string& name, const string& description, const string& startDate, const string& endDate);

    static void addProject(const string& name, const string& description, const string& startDate, const string& endDate);
    static void displayAllProjects();
    static vector<Project> projects;  // Static vector to store project instances

private:
    string name;
    string description;
    string startDate;
    string endDate;
};

#endif  // PROJECTS_H


};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_PROJECTS_H
