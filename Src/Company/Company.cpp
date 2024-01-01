//
// Created by cemsr on 20.12.2023.
//

#include "Company.h"
#include <string>
#include <utility>
#include <vector>

using namespace std;

Company::Company() {
    cout << "default company constructor called "<< endl;
}

Company::Company(int companyId,string companyName, string number, string email, string city, string taxNumber, string taxOfficeCity){
    this->CompanyId=companyId;
    this->CompanyName=move(companyName);
    this->CompanyPhoneNumber=move(number);
    this->CompanyEmail=move(email);
    this->CompanyCity=move(city);
    this->CompanyTaxNumber=move(taxNumber);
    this->CompanyTaxOfficeCity=move(taxOfficeCity);
}

vector<Company> Company::companies;
int Company::nextCompanyId = 1;


void Company::displayCompanyProfileInformation() {

    cout << "ID:" << CompanyId << "\n"
         << "Username:" << getCompanyUserName() << "\n"
         << "Name:" << getCompanyName() << "\n"
         << "Phone Number:" << getCompanyPhoneNumber() << "\n"
         << "mail Address:" << getCompanyEmail() << "\n"
         << "City Where Located:" << getCompanyCity() << "\n"
         << "Tax Number:" << getCompanyTaxNumber() << "\n"
         << "Tax Office City:" << getCompanyTaxOfficeCity() << endl;
}

void Company::updateCompanyProfileInformation() {

    string companyName, phoneNumber, email, city, taxNumber, taxOfficeCity;

    cout << "Updating company profile information:" << endl;
    cin.ignore();
    cout << "Your new company name:";
    getline(cin,companyName);
    setCompanyName(companyName);

    cout << "Your new company phone number:";
    getline(cin,phoneNumber);
    setCompanyPhoneNumber(phoneNumber);

    cout << "Your new company email address:";
    getline(cin,email);
    setCompanyEmail(email);

    cout << "New city where your company located:";
    getline(cin,city);
    setCompanyCity(city);

    cout << "Your new tax number:";
    getline(cin,taxNumber);
    setCompanyTaxNumber(taxNumber);

    cout << "Your new tax office city located:";
    getline(cin,taxOfficeCity);
    setCompanyTaxOfficeCity(taxOfficeCity);

    createCompanyUserName();

    cout << "Do you want to change your password? (1 for Yes, 0 for No):\n" << endl;
    while(true) {
        int control;
        control = menuMethods.getUserInputWithControl();
        cin >> control;
        if (control == 1) {
            createCompanyPassword();
            break;
        } else if (control == 0) {
            cout << "Your password remains the same." << endl;
            break;
        }
    }

    cout <<"Your profile information has been successfully updated." << endl;

    displayCompanyUserName();
    displayCompanyPassword();
}

void Company::createCompanyUserName() {

    string companyName,lastName;

    companyName = getCompanyName();
    lastName = "company";

    setCompanyUserName(companyName+"."+lastName);
}

void Company::displayCompanyUserName() {

    cout << "Your Company's username:" << getCompanyUserName() << endl;
}

void Company::createCompanyPassword() {

    string passwordInFunction;
    cout << "Please create your password (Between 6 and 10 characters):" << endl;
    while(true){
        cout << ">>";
        cin >> passwordInFunction;
        if(passwordInFunction.length()<=10 && passwordInFunction.length()>=6){
            setCompanyPassword(passwordInFunction);
            break;
        }
        cout << "Wrong password format. Please try different password!" <<endl;
    }
}

void Company::displayCompanyPassword() {

    cout << "Your Company's password:" << getCompanyPassword() << endl;
}


string Company::getCompanyName() {
    return this->CompanyName;
}
string Company::getCompanyPhoneNumber() {
    return this->CompanyPhoneNumber;
}
string Company::getCompanyEmail() {
    return this->CompanyEmail;
}
string Company::getCompanyCity() {
    return this->CompanyCity;
}
string Company::getCompanyTaxNumber() {
    return this->CompanyTaxNumber;
}
string Company::getCompanyTaxOfficeCity() {
    return this->CompanyTaxOfficeCity;
}
string Company::getCompanyUserName() {
    return this->CompanyUserName;
}
string Company::getCompanyPassword(){
    return CompanyPassword;
}

void Company::setCompanyUserName(const string &companyUserName) {
    CompanyUserName = companyUserName;
}

void Company::setCompanyPassword(const string &companyPassword) {
    CompanyPassword = companyPassword;
}

void Company::setCompanyName(const string &companyName) {
    CompanyName = companyName;
}

void Company::setCompanyPhoneNumber(const string &companyPhoneNumber) {
    CompanyPhoneNumber = companyPhoneNumber;
}

void Company::setCompanyEmail(const string &companyEmail) {
    CompanyEmail = companyEmail;
}

void Company::setCompanyCity(const string &companyCity) {
    CompanyCity = companyCity;
}

void Company::setCompanyTaxNumber(const string &companyTaxNumber) {
    CompanyTaxNumber = companyTaxNumber;
}

void Company::setCompanyTaxOfficeCity(const string &companyTaxOfficeCity) {
    CompanyTaxOfficeCity = companyTaxOfficeCity;
}




