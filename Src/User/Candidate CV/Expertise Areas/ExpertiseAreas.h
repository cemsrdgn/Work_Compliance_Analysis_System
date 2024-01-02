//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXPERTISEAREAS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXPERTISEAREAS_H

#include <string>
#include <vector>
using namespace std;

class ExpertiseArea {
public:
    ExpertiseArea();  // Default constructor
    ExpertiseArea(const string& areaName, const string& description);  // Parametrized constructor
    ~ExpertiseArea();  // Destructor

    void display() const;
    void update(const string& areaName, const string& description);

    static void addArea(const string& areaName, const string& description);
    static void displayAllAreas();

private:
    string areaName;
    string description;
    static vector<ExpertiseArea> areas;  // Static vector to store expertise area instances
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXPERTISEAREAS_H
