//
// Created by cemsr on 16.12.2023.
//

#include "Candidate/User.h"
#include <string>
#include <iostream>
#include <utility>

using namespace std;

User::User(){
    cout << "Default Constructor Called." << endl;
}

User::User(int id) {
    this->ID=id;
}

User::User(int id,
           string firstName,
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
           ID{id},
           FirstName{move(firstName)},
           LastName{move(lastName)},
           Gender{move(gender)},
           DateOfBirth(birthDay,birthMonth,birthYear),
           Nationality{move(nationality)},
           IdentityNumber{move(identityNumber)},
           MilitaryService{militaryService},
           WorkingStatus{workingStatus},
           Password(" "){

    cout << "Parameterized Constructor Called." << endl;
}

vector<User> User::users;
int User::nextId = 1;

void User::displayUserInformation() const{

    cout << "Your Personal Informations:" << endl;

    cout << "ID: " << ID << "\n"
         << "First Name: " << FirstName << "\n"
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

void User::createPassword() {

    string passwordInFunction;

    cout << "Lütfen 4-10 sayıdan oluşucak şifrenizi giriniz: ";
    cin >> passwordInFunction;
    setPassword(passwordInFunction);
}

void User::displayUserPassword() {

    cout << "Your Password:" << Password << endl;
}

//Destructor
User::~User(){
    cout << "Destructor Called." << endl;
}

void User::displayUsers() {
    cout << "Users in the database:" << endl;
    for (const auto& user : users) {
        user.displayUserInformation();
        cout << "-------------------------" << endl;
    }
}

void User::setPassword(const string &password) {
    Password = password;
}
int User::getID(){
    return this->ID;
}
void User::display() {
    cout << "hi" << endl;
}

