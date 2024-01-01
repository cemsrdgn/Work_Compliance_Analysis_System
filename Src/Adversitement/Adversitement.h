//
// Created by USER on 21.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H

#include <string>
#include <vector>

using namespace std;

struct Adversitements {
    int NumberofQuotas;
    string AdTitle;
    string CompanyDescription;
    int Salary;
    string City;
    string ApplicationDeadline;
};

class Adversitement {
private:

    //Ads information
    string AdTitle;
    string CompanyDescription;
    int Salary;
    string City;
    string ApplicationDeadline;

    //Ads attributes
    int AdId;
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
    //Default Constructor
    Adversitement();

    //Parameterized Constructor
    Adversitement(string adTitle,
                  string companyDescription,
                  int salary,
                  string city,
                  string applicationDeadline,
                  int adId,
                  string sector,
                  string position,
                  string workPreference,
                  string workType,
                  string experience,
                  string positionLevel,
                  string educationLevel,
                  string language,
                  string militaryService
    );

    //Database for ads. Ad is storing here.
    static vector<Adversitement> adversitement;

    //AdId increase
    static int nextAdId;

    //Destructor
    ~Adversitement();

    void AddAdversitement(Adversitements add, string sector, string position, string workpreference, string worktype,
                          string experience, string positionlevel, string educationlevel, string language,
                          string military);

    void display() const;

    void printMenu();

    static void displayAllAdversitements();


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
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_ADVERSITEMENT_H
