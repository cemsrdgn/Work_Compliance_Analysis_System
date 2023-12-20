//
// Created by cemsr on 15.12.2023.
//

#include "EducationInformation.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

EducationInformation::EducationInformation(
        string highSchool,
        University university)
{
    this->HighSchool=highSchool;
    this->uni=university;
}

string EducationInformation::getHighSchool(){
    return this->HighSchool;
}
string EducationInformation::getUniversityName(){
    return this->uni.UniversityName;
}
string EducationInformation::getFaculty(){
    return this->uni.Faculty;
}
string EducationInformation::getDepartment(){
    return this->uni.Department;
}
int EducationInformation::getStartDate() {
    return this->uni.StartDate;
}
int EducationInformation::getFinishDate() {
    return this->uni.FinishDate;
}
string EducationInformation::getEducationLanguage(){
    return this->uni.EducationLanguage;
}
string EducationInformation::getEducationType(){
    return this->uni.EducationType;
}
string EducationInformation::getDoubleMajor(){
    return this->uni.DoubleMajor;
}
string EducationInformation::getMinor(){
    return this->uni.Minors;
}
float EducationInformation::getGPA(){
    return this->uni.GPA;
}
void EducationInformation::addEducationInformation(string school, University univ) {
    EducationInformation newedu(school,univ);
    education.push_back(newedu);
}
void EducationInformation::display() {
    cout << "Education Information " << endl;
    for (size_t i = 0; i < education.size(); i++) {
        cout << i + 1 << " High school " << education[i].getHighSchool()
             << " University Name " << education[i].getUniversityName()
             << " Faculty " << education[i].getFaculty()
             << " Department " << education[i].getDepartment()
             << " Start time " << education[i].getStartDate()
             << " Finish time " << education[i].getFinishDate()
             << " Education language" << education[i].getEducationLanguage()
             << " Education type" << education[i].getEducationType()
             << " Double Major " << education[i].getDoubleMajor()
             << " Minor" << education[i].getMinor()
             << " GPA" << education[i].getGPA() << endl;
    }
}

int EducationInformation::calculateDate() {
    return this->uni.FinishDate-this->uni.StartDate;
}