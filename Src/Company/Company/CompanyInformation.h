//
// Created by cemsr on 20.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANYINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANYINFORMATION_H

#include <string>
using namespace std;

class CompanyInformation {

private:

    string CompanyUserName; //Biz oluşturacağız
    string CompanyPassword; //Register işleminden sonra şifre oluşturulacak

    string CompanyName;
    string CompanyPhoneNumber;
    string CompanyEmail;
    string CompanyCity;
    string CompanyTaxNumber;
    string CompanyTaxOfficeCity;

protected:
    int CompanyId;

public:

    //Default Constructor
    CompanyInformation(string companyname, string number, string email, string city,string taxnumber, string taxoffficecity);
    string getCompanyName();
    string getCompanyPhoneNumber();
    string getCompanyEmail();
    string getCompanyCity();
    string getCompanyTaxNumber();
    string getCompanyTaxOfficeCity();
    void createCompanyUserName();
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANYINFORMATION_H
