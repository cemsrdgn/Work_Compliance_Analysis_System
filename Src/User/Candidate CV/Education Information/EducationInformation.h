//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H

#include <string>
#include <vector>
#include "Candidate/User.h"

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

class EducationInformation : public User{
private:
    string HighSchool;
    float HighSchoolPoint;
    bool isErasmus;
    University uni;
    vector<EducationInformation> education;
public:

    EducationInformation(int id, string highschool, float highSchoolPoint, University university,bool iserasmus);
    EducationInformation(string highschool, float highSchoolPoint, University university,bool iserasmus);
    EducationInformation();
    bool getIsErasmus();
    bool serIsErasmus(bool erasmus);
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
    float getHighSchoolPoint();
    void addEducationInformation(int id,string school,float highSchoolPoint,University univ,bool erasmus);
    void display() override;
};
#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EDUCATIONINFORMATION_H
