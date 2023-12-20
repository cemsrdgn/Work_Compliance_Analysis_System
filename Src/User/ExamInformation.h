//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ExamInformation {
private:
    vector<ExamInformation>graduates;
    string ExamRank;
    string ExamPoint;
public:

    ExamInformation(string examrank,string exampoint);
    ExamInformation(string exampoint);
    void addExamRating(string examrank,string exampoint);
    void addExamRating(string point);
    string getExamRank();
    string getExamPoint();
    void displayGraduate();
    void displayYksGraduate();
    void selectExam();
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_EXAMINFORMATION_H
