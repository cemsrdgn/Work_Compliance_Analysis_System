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
           bool disabilitySituation,
           bool relativeOfMartyr,
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
           DisabilitySituation{disabilitySituation},
           RelativeOfMartyr{relativeOfMartyr},
           WorkingStatus{workingStatus},
           Password(" "){

    cout << "Parameterized Constructor Called." << endl;
}

vector<User> User::users;
int User::nextId = 1;

void User::displayCandidateInformation() const {

    cout << "ID: " << ID << "\n"
         << "First Name: " << FirstName << "\n"
         << "Last Name: " << LastName << "\n"
         << "Gender: " << Gender << "\n"
         << "Date of Birth:";
    DateOfBirth.displayDate();
    cout << "Nationality: " << Nationality << "\n"
         << "Identity Number: " << IdentityNumber << "\n"
         << "Disability Situation: " << (DisabilitySituation ? "Yes" : "No") << "\n"
         << "Relative of Martyr: " << (RelativeOfMartyr ? "Yes" : "No") << "\n"
         << "Military Service: " << (MilitaryService ? "Yes" : "No") << "\n"
         << "Working Status: " << (WorkingStatus ? "Yes" : "No") << endl;
}

void User::displayAllCandidates() {
    cout << "Users in the database:" << endl;
    for (const auto& user : users) {
        user.displayCandidateInformation();
        cout << "-------------------------" << endl;
    }
}


void User::createCandidateUserName() { //Türkçe karakterler için modifiye edilmesi gerekiyor.

    string firstName,lastName;

    firstName = FirstName;
    lastName = LastName;

    setUserName(firstName+"."+lastName);
}

void User::displayCandidateUserName() {

    cout << "Your username:" << UserName << endl;
}

void User::createCandidatePassword() {

    string passwordInFunction;

    cout << "Please create your password (Between 6 and 10 characters):" << endl;
    while(true){
        cout << ">>";
        cin >> passwordInFunction;
        if(passwordInFunction.length()<=10 && passwordInFunction.length()>=6){
            setPassword(passwordInFunction);
            break;
        }
        cout << "Wrong password format. Please try different password!" <<endl;
    }
}

void User::displayCandidatePassword() {

    cout << "Your Password:" << Password << endl;
}

void User::updateCandidateProfileInformation() {

    string firstname,lastname,gender,nationality,identitynumber;
    int birthday,birthmonth,birthyear;
    bool disability,martyr,military,working;

    cout << "Updating profile information:" << endl;

    cout << "Your new first name:";
    cin  >> firstname;
    setFirstName(firstname);

    cout << "Your new last name:";
    cin  >> lastname;
    setLastName(lastname);

    cout << "Your new gender:";
    cin  >> gender;
    setGender(gender);

    cout << "Your new birth day:" << endl;
    cin  >> birthday;
    cout << "Your new birth month:" << endl;
    cin  >> birthmonth;
    cout << "Your new birth year:" << endl;
    cin  >> birthyear;
    DateOfBirth.updateDate(birthday,birthmonth,birthyear);

    cout << "Your new nationality:";
    cin  >> nationality;
    setNationality(nationality);

    cout << "Your new identity number:";
    cin  >> identitynumber;
    setIdentityNumber(identitynumber);

    cout << "Your new disability situation (1 for Yes, 0 for No):";
    cin  >> disability;
    setDisabilitySituation(disability);

    cout << "Your new relative of martyr situation(1 for Yes, 0 for No):";
    cin  >> martyr;
    setRelativeOfMartyr(martyr);

    cout << "Your new military service situation(1 for Yes, 0 for No):";
    cin  >> military;
    setMilitaryService(military);

    cout << "Your new working status(1 for Yes, 0 for No):";
    cin  >> working;
    setWorkingStatus(working);

    createCandidateUserName();

    cout << "Do you want to change your password? (1 for Yes, 0 for No):\n" << endl;
    while(true) {
        int control;
        control = menuMethods.getUserInputWithControl();
        cin >> control;
        if (control == 1) {
            createCandidatePassword();
            break;
        } else if (control == 0) {
            cout << "Your password remains the same." << endl;
            break;
        }
    }

    cout <<"Your profile information has been successfully updated." << endl;

    displayCandidateUserName();
    displayCandidatePassword();
}


//Destructor
User::~User(){
    cout << "Destructor Called." << endl;
}

void User::setUserName(const string &userName) {User::UserName = userName;}
void User::setPassword(const string &password) {Password = password;}
void User::setFirstName(const string &firstName) {FirstName = firstName;}
void User::setLastName(const string &lastName) {LastName = lastName;}
void User::setGender(const string &gender) {Gender = gender;}
void User::setNationality(const string &nationality) {Nationality = nationality;}
void User::setIdentityNumber(const string &identityNumber) {IdentityNumber = identityNumber;}
void User::setDisabilitySituation(bool disabilitySituation) {DisabilitySituation = disabilitySituation;}
void User::setRelativeOfMartyr(bool relativeOfMartyr) {RelativeOfMartyr = relativeOfMartyr;}
void User::setMilitaryService(bool militaryService) {MilitaryService = militaryService;}
void User::setWorkingStatus(bool workingStatus) {WorkingStatus = workingStatus;}

const string &User::getUserName() const {
    return UserName;
}

const string &User::getPassword() const {
    return Password;
}



const string &User::getLastName() const {
    return LastName;
}
int User::getID(){
    return this->ID;
}
void User::display() {
    cout << "hi" << endl;
}

const string &User::getFirstName() const {
    return FirstName;
}

