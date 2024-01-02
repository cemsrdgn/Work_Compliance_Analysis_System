//
// Created by cemsr on 15.12.2023.
//
#include <iostream>
#include <string>
#include <vector>
#include "WorkConditions.h"

//Default Constructor
WorkConditions::WorkConditions(){}


//Parameterized Constructor
WorkConditions::WorkConditions(int id,
                               int salaryException,
                               string desiredPosition,
                               string desiredCityToWork,
                               bool travelCapability)
{
    this->SalaryException=salaryException;
    this->DesiredPosition=move(desiredPosition);
    this->DesiredCityToWork=move(desiredCityToWork);
    this->TravelCapability=travelCapability;
}


void WorkConditions::add(int id, int salaryException, string desiredPosition, string desiredCityToWork,bool travelCapability){

    WorkConditions newCond(id,salaryException,desiredCityToWork,desiredCityToWork,travelCapability);
    workConditions.push_back(newCond);

}

void WorkConditions::display() {

    for (auto & workCondition : workConditions) {
        cout  << " Id:" << ID << endl;
        cout  << " Salary Exception:" << workCondition.getSalaryException() << endl;
        cout  << " Desired Position " << workCondition.getDesiredPosition() << endl;
        cout  << " Desired City To Work " << workCondition.getDesiredCityToWork() << endl;
        cout  << " Travel Capability " << workCondition.getTravelCapability() << endl;
    }
}


int WorkConditions::getSalaryException() const {return this->SalaryException;}
string WorkConditions::getDesiredPosition() const {return this->DesiredPosition;}
string WorkConditions::getDesiredCityToWork()const {return this->DesiredCityToWork;}
bool WorkConditions::getTravelCapability() const {return this->TravelCapability;}