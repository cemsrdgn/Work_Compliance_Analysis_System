//
// Created by USER on 21.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H

#include <string>
#include <vector>

using namespace std;

struct Adversitements{
    int NumberofQuotas;
    string AdTitle;
    string CompanyDescription;
    int Salary;
    string City;
    string ApplicationDeadline;
};

class Adversitement {
private:
    vector<Adversitement>adversitement;
    Adversitements adversitements;
    string Sector;
    string Position;
    string WorkPreference;
    string WorkType;
    string Experience;
    string PositionLevel;
    string EducationLevel;
    string Language;
    string MilitaryService;
public:
    Adversitement(Adversitements add,string sector,string position,string workpreference,string worktype,
                  string experience,string positionlevel,string educationlevel,string language,string military);
    int getNumberofQuotas();
    string getAdTitle();
    string getCompanyDescription();
    int getSalary();
    string getCity();
    string getApplicationDeadline();
    string getSector();
    string getPosition();
    string getWorkPreference();
    string getWorkType();
    string getExperience();
    string getPositionLevel();
    string getEducationLevel();
    string getLanguage();
    string getMilitaryService();
    void AddAdversitement(Adversitements add,string sector,string position,string workpreference,string worktype,
                          string experience,string positionlevel,string educationlevel,string language,string military);
    void display();
    void printMenu();
    void displayPosition();
    void displayEducation();


};



#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H
