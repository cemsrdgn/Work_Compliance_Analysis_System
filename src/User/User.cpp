//
// Created by cemsr on 16.12.2023.
//

#include "User.h"
#include <string>
#include <iostream>
#include <utility>

using namespace std;

User::User(){
    cout << "Default Constructor Called." << endl;
}

User::User(string firstName,
           string lastName,
           string gender,
           int birthDay,
           int birthMonth,
           int birthYear,
           string nationality,
           string identityNumber,
           bool militaryService,
           bool workingStatus)
           :
           FirstName{move(firstName)},
           LastName{move(lastName)},
           Gender{move(gender)},
           DateOfBirth(birthDay,birthMonth,birthYear),
           Nationality{move(nationality)},
           IdentityNumber{move(identityNumber)},
           MilitaryService{militaryService},
           WorkingStatus{workingStatus}{
    /*
    this->FirstName = move(firstName);
    this->LastName = move(lastName);
    this->Gender = move(gender);
    this->DateOfBirth = move(dateOfBirth);
    this->Nationality = move(nationality);
    this->IdentityNumber = move(identityNumber);
    this->MilitaryService = militaryService;
    this->WorkingStatus = workingStatus;
     */

    cout << "Parameterized Constructor Called." << endl;
}

void User::displayUserInformation(){

    cout << "Your Personal Informations:" << endl;

    cout << "First Name: " << FirstName << "\n"
         << "Last Name: " << LastName << "\n"
         << "Gender: " << Gender << "\n"
         << "Date of Birth:";
    DateOfBirth.displayDate();
    cout << "Nationality: " << Nationality << "\n"
         << "Identity Number: " << IdentityNumber << "\n"
         << "Military Service: " << (MilitaryService ? "Yes" : "No") << "\n"
         << "Working Status: " << (WorkingStatus ? "Yes" : "No") << endl;
}

void User::createUserName() { //Türkçe karakterler için modifiye edilmesi gerekiyor.

    string firstName,lastName;

    firstName = FirstName;
    lastName = LastName;

    userName = firstName+"."+lastName;
}

void User::displayUserName(){

    cout << "Your username:" << userName << endl;
}


//Destructor
User::~User(){
    cout << "Destructor Called." << endl;
}