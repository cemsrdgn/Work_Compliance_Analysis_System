//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKEXPERIENCE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKEXPERIENCE_H

#include <string>
#include <vector>
#include "Candidate/User.h"
using namespace std;

struct Experience{
    string CompanyName;
    string Position;
    string WorkType;
    string City;
    string CompanyWorkingArea;
    int StartDate;
    int FinishDate;
};

class WorkExperience :public User{
private:
    Experience experience;
    vector<WorkExperience>exper;
public:
    WorkExperience(int id,Experience experience1);
    string getCompanyName();
    string getPosition();
    string getWorkType();
    string getCity();
    string getCompanyWorkingArea();
    int getStartDate();
    int getFinishDate();
    int CalculateWorkTime(int s1,int s2);
    void addExperience(int id,Experience experience1);
    void display() override;
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKEXPERIENCE_H
