//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
//
#include <string>
#include <vector>
#include <iostream>
#include "Candidate/User.h"

using namespace std;

class ExamInformation : public User {
private:
    vector<ExamInformation>graduates;
    float ExamRank;
    float ExamPoint;
public:

    ExamInformation(int id,float examrank,float exampoint);
    ExamInformation(int id,float exampoint);
    void addExamRating(int id,float examrank,float exampoint);
    void addExamRating(int id,float point);
    float getExamRank();
    float getExamPoint();
    void displayGraduate();
    void displayYksGraduate();
    void selectExam();
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
