//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKCONDITIONS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKCONDITIONS_H


#include <string>
#include <utility>
#include <vector>
#include "Candidate/User.h"

#include <string>
#include <vector>
#include "Candidate/User.h"

class WorkConditions : public User {

private:

    int SalaryException;
    string DesiredPosition;
    string DesiredCityToWork;
    bool TravelCapability;

    vector<WorkConditions> workConditions;

public:
    //Default Constructor
    WorkConditions();

    //Parameterized Constructor
    WorkConditions(int id,
                   int salaryException,
                   string desiredPosition,
                   string desiredCityToWork,
                   bool travelCapability);


    void display() override;

    void add(int id, int salaryException, string desiredPosition, string desiredCityToWork, bool travelCapability);



    int getSalaryException() const;
    string getDesiredPosition() const;
    string getDesiredCityToWork() const;
    bool getTravelCapability() const;

};

#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_WORKCONDITIONS_H