//
// Created by cemsr on 20.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANY_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANY_H

#include <string>
using namespace std;

class Company {

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
    MenuMethods menuMethods;

    static vector<Company> companies;

    static int nextCompanyId;

    //Default Constructor
    Company();

    //Parametrized Constructor
    Company(int companyId, string companyName, string number, string email, string city, string taxNumber, string taxOffficecity);

    void createCompanyUserName();
    void displayCompanyUserName();

    void createCompanyPassword();
    void displayCompanyPassword();

    void displayCompanyProfileInformation();
    void updateCompanyProfileInformation();

    string getCompanyUserName();
    string getCompanyName();
    string getCompanyPhoneNumber();
    string getCompanyEmail();
    string getCompanyCity();
    string getCompanyTaxNumber();
    string getCompanyTaxOfficeCity();
    string getCompanyPassword();

    void setCompanyUserName(const string &companyUserName);
    void setCompanyPassword(const string &companyPassword);
    void setCompanyName(const string &companyName);
    void setCompanyPhoneNumber(const string &companyPhoneNumber);
    void setCompanyEmail(const string &companyEmail);
    void setCompanyCity(const string &companyCity);
    void setCompanyTaxNumber(const string &companyTaxNumber);
    void setCompanyTaxOfficeCity(const string &companyTaxOfficeCity);
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMPANY_H
