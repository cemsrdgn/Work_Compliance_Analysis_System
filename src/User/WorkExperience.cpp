//
// Created by cemsr on 15.12.2023.
//

#include "WorkExperience.h"
#include <iostream>
#include <string>

using namespace std;

WorkExperience::WorkExperience(Experience experience1){
    this->experience=experience1;
}

string WorkExperience::getCompanyName() {
    return this->experience.CompanyName;
}
string WorkExperience::getPosition() {
    return this->experience.Position;
}
string WorkExperience::getWorkType() {
    return this->experience.WorkType;
}
string WorkExperience::getCity() {
    return this->experience.City;
}
string WorkExperience::getCompanyWorkingArea() {
    return this->experience.CompanyWorkingArea;
}
int WorkExperience::getStartDate() {
    return this->experience.StartDate;
}
int WorkExperience::getFinishDate() {
    return this->experience.FinishDate;
}
int WorkExperience::CalculateWorkTime(int s1, int s2) {
    s1=this->experience.StartDate;
    s2=this->experience.FinishDate;
    return s2-s1;
}
void WorkExperience::addExperience(Experience experience1) {
    WorkExperience newwork(experience1);
    exper.push_back(newwork);
}
void WorkExperience::display() {

    for (size_t i = 0; i < exper.size(); i++) {
        cout  << " Company Name " << exper[i].getCompanyName() << endl;
        cout  << " Work Position " << exper[i].getPosition() << endl;
        cout  << " Part-time or Full " << exper[i].getWorkType() << endl;
        cout  << " City " << exper[i].getCity() << endl;
        cout  << " Work Area " << exper[i].getCompanyWorkingArea() << endl;
        cout  << " Work time " << exper[i].CalculateWorkTime(exper[i].getStartDate(),exper[i].getFinishDate()) << endl;
    }
}