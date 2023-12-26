//
// Created by cemsr on 15.12.2023.
//

#include "EducationInformation.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

EducationInformation::EducationInformation(
        int id,
        string highSchool,
        University university)
{
    this->ID=id;
    this->HighSchool=highSchool;
    this->uni=university;
}
EducationInformation::EducationInformation(){}

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
void EducationInformation::addEducationInformation(int id,string school, University univ) {
    EducationInformation newEdu(id,school,univ);
    education.push_back(newEdu);
}
void EducationInformation::display() {
    cout << "Education Information " << endl;
    for (size_t i = 0; i < education.size(); i++) {
        cout << i + 1 << " High school " << education[i].getHighSchool() << endl;
        cout << " University Name " << education[i].getUniversityName() << endl;
        cout << " Faculty " << education[i].getFaculty() << endl;
        cout << " Department " << education[i].getDepartment() << endl;
        cout << " Start time " << education[i].getStartDate() << endl;
        cout << " Finish time " << education[i].getFinishDate() << endl;
        cout << " Education language" << education[i].getEducationLanguage() << endl;
        cout << " Education type" << education[i].getEducationType() << endl;
        cout << " Double Major " << education[i].getDoubleMajor() << endl;
        cout << " Minor" << education[i].getMinor() << endl;
        cout << " GPA" << education[i].getGPA() << endl;
    }
}

int EducationInformation::calculateDate() {
    return this->uni.FinishDate-this->uni.StartDate;
}