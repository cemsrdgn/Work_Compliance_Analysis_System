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
    string ExamRank;
    string ExamPoint;
public:

    ExamInformation(int id,string examrank,string exampoint);
    ExamInformation(int id,string exampoint);
    void addExamRating(int id,string examrank,string exampoint);
    void addExamRating(int id,string point);
    string getExamRank();
    string getExamPoint();
    void displayGraduate();
    void displayYksGraduate();
    void selectExam();
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
