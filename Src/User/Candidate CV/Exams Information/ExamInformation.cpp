#include "ExamInformation.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


ExamInformation::ExamInformation(int ıd,float rank,float point)
{
    this->ID=ıd;
    this->ExamRank=rank;
    this->ExamPoint=point;
}
ExamInformation::ExamInformation(int ıd,float point)
{
    this->ID=ıd;
    this->ExamPoint=point;
}
ExamInformation::ExamInformation() {}
void ExamInformation:: addExamRating(int ıd,float examrank,float exampoint){
    ExamInformation newgradute(ıd,examrank,exampoint);
    graduates.push_back(newgradute);
}
void ExamInformation::addExamRating(int ıd,float exampoint) {
    ExamInformation newgradute(ıd,exampoint);
    graduates.push_back(newgradute);
}

float ExamInformation::getExamRank(){
    return this->ExamRank;
}

float ExamInformation::getExamPoint(){
    return this->ExamPoint;
}
void ExamInformation::displayGraduate(){
    for (size_t i = 0; i < graduates.size(); i++) {
        cout << i + 1 << "Exam Point: " << graduates[i].getExamPoint() << endl;
    }
}
void ExamInformation::displayYksGraduate(){
    for (size_t i = 0; i < graduates.size(); i++) {
        cout << i + 1 << "YKS Exam point: "  << graduates[i].getExamPoint() << endl;
        cout << "YKS Exam Rank: " << graduates[i].getExamRank() << endl;
    }
}