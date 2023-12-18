//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H

#include <string>
#include <vector>
using namespace std;

struct University{
    string UniversityName;
    string Faculty;
    string Department;
    int StartDate;
    int FinishDate;
    string EducationLanguage;
    string EducationType;
    string DoubleMajor;
    string Minors;
    float GPA;
};

class EducationInformation {
private:
    string HighSchool;
    University uni;
    vector<EducationInformation> education;
public:
    EducationInformation(string highschool,University university);
    string getHighSchool();
    string getUniversityName();
    string getFaculty();
    string getDepartment();
    int getStartDate();
    int getFinishDate();
    int calculateDate();
    string getEducationLanguage();
    string getEducationType();
    string getDoubleMajor();
    string getMinor();
    float getGPA();
    void addEducationInformation(string school,University univ);
    void display();
};
#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H
