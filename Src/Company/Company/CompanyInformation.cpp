//
// Created by cemsr on 20.12.2023.
//

#include "CompanyInformation.h"
#include <string>
#include <vector>

using namespace std;

CompanyInformation::CompanyInformation(string companyname, string number, string email, string city,string taxnumber, string taxoffficecity){
    this->CompanyName=companyname;
    this->CompanyPhoneNumber=number;
    this->CompanyEmail=email;
    this->CompanyCity=city;
    this->CompanyTaxNumber=taxnumber;
    this->CompanyTaxOfficeCity=taxoffficecity;
}

string CompanyInformation::getCompanyName() {
    return this->CompanyName;
}
string CompanyInformation::getCompanyPhoneNumber() {
    return this->CompanyPhoneNumber;
}
string CompanyInformation::getCompanyEmail() {
    return this->CompanyEmail;
}
string CompanyInformation::getCompanyCity() {
    return this->CompanyCity;
}
string CompanyInformation::getCompanyTaxNumber() {
    return this->CompanyTaxNumber;
}
string CompanyInformation::getCompanyTaxOfficeCity() {
    return this->CompanyTaxOfficeCity;
}
