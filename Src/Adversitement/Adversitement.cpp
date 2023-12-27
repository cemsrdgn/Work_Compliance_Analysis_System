//
// Created by USER on 21.12.2023.
//

#include "Adversitement.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Adversitement::Adversitement(Adversitements add,string sector,string position,string workpreference,string worktype,
                             string experience,string positionlevel,string educationlevel,string language,string military) {
    this->adversitements=add;
    this->Sector=sector;
    this->Position=position;
    this->WorkPreference=workpreference;
    this->WorkType=worktype;
    this->Experience=experience;
    this->PositionLevel=positionlevel;
    this->EducationLevel=educationlevel;
    this->Language=language;
    this->MilitaryService=military;
}
int Adversitement::getNumberofQuotas(){
    return this-> adversitements.NumberofQuotas;
}
string Adversitement::getAdTitle(){
    return this-> adversitements.AdTitle;
}
string Adversitement::getCompanyDescription(){
    return this-> adversitements.CompanyDescription;
}
int Adversitement::getSalary(){
    return this-> adversitements.Salary;
}
string Adversitement::getCity(){
    return this-> adversitements.City;
}
string Adversitement::getApplicationDeadline(){
    return this-> adversitements.ApplicationDeadline;
}

void Adversitement::AddAdversitement (Adversitements add,string sector,string position,string workpreference,string worktype,
                                      string experience,string positionlevel,string educationlevel,string language,string military){
    Adversitement newAdvetsitement(add,sector, position, workpreference, worktype,experience, positionlevel,
                                   educationlevel, language, military);
    adversitement.push_back(newAdvetsitement);
}
/*void  Adversitement::displayPosition(){
    cout << "Enter Position Level: " << endl;
    cout << "1-Senior Executive" << endl;
    cout << "2-Middle Manager" << endl;
    cout << "3-Management Candidate" << endl;
    cout << "4-Expert" << endl;
    cout << "5-Beginner" << endl;
    cout << "6-Freelancer" << endl;
    cout << "7-Freelancer" << endl;
    cout << "8-Workers and Blue Collar" << endl;
    cout << "9-Intern" << endl;
}*/

string Adversitement::getPosition(){
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Position:" << endl;
        cout << "a) Customer Representative" << endl;
        cout << "b) Sales Representative" << endl;
        cout << "c) Software specialist" << endl;
        cout << "d) Accounting staff" << endl;
        cout << "e) Software developing expert" << endl;
        cout << "f) Store manager" << endl;
        cout << "Select Position (a-f): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->Position = "Customer Representative";
                validChoice = true;
                break;
            case 'b':
                this->Position = "Sales Representative";
                validChoice = true;
                break;
            case 'c':
                this->Position = "Software specialist";
                validChoice = true;
                break;
            case 'd':
                this->Position = "Accounting staff";
                validChoice = true;
                break;
            case 'e':
                this->Position = "Software developing expert";
                validChoice = true;
                break;
            case 'f':
                this->Position = "Store manager";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->Position;
}

string Adversitement::getSector(){
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Sector:" << endl;
        cout << "a) Technology and Software " << endl;
        cout << "b) Finance and Banking" << endl;
        cout << "c) Retail and Sales " << endl;
        cout << "d) Media and Entertainment" << endl;
        cout << "e) Agriculture and Farming" << endl;
        cout << "f) Automotive" << endl;
        cout << "g) Tourism and Accommodation" << endl;
        cout << "h) Civil Engineering" << endl;
        cout << "i) Electric Engineering" << endl;
        cout << "j) Energy and Renewable Resources" << endl;
        cout << "k) Service Sector (Consulting, Cleaning, Transportation)" << endl;
        cout << "l) Fashion and Clothing" << endl;
        cout << "m) Logistics and Distribution " << endl;
        cout << "n) Textile " << endl;
        cout << "Select Sector (a-n): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->Sector = "Technology and Software";
                validChoice = true;
                break;
            case 'b':
                this->Sector = "Finance and Banking";
                validChoice = true;
                break;
            case 'c':
                this->Sector = "Retail and Sales";
                validChoice = true;
                break;
            case 'd':
                this->Sector = "Media and Entertainment";
                validChoice = true;
                break;
            case 'e':
                this->Sector = "Agriculture and Farming";
                validChoice = true;
                break;
            case 'f':
                this->Sector = "Automotive";
                validChoice = true;
                break;
            case 'g':
                this->Sector = "Tourism and Accommodation";
                validChoice = true;
                break;
            case 'h':
                this->Sector = "Civil Engineering";
                validChoice = true;
                break;
            case 'i':
                this->Sector = "Electric Engineering";
                validChoice = true;
                break;
            case 'j':
                this->Sector = "Energy and Renewable Resources";
                validChoice = true;
                break;
            case 'k':
                this->Sector = "Service Sector (Consulting, Cleaning, Transportation)";
                validChoice = true;
                break;
            case 'l':
                this->Sector = "Fashion and Clothing";
                validChoice = true;
                break;
            case 'm':
                this->Sector = "Logistics and Distribution";
                validChoice = true;
                break;
            case 'n':
                this->Sector = "Textile";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->Sector;
}

string Adversitement::getWorkPreference() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Work Preference:" << endl;
        cout << "a) Remote/Remote" << endl;
        cout << "b) At the workplace" << endl;
        cout << "c) Hybrid" << endl;
        cout << "Select Preference (a-c): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->WorkPreference = "Remote/Remote";
                validChoice = true;
                break;
            case 'b':
                this->WorkPreference = "At the workplace";
                validChoice = true;
                break;
            case 'c':
                this->WorkPreference = "Hybrid";
                validChoice = true;
                break;

            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->WorkPreference;
}

string Adversitement::getWorkType() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Work Type:" << endl;
        cout << "a) Permanent / Full time" << endl;
        cout << "b) Periodic / Project based" << endl;
        cout << "c) Intern" << endl;
        cout << "d) Part time" << endl;
        cout << "e) Free Time" << endl;
        cout << "f) Consultancy" << endl;
        cout << "Select Type (a-f): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->WorkType = "Permanent / Full time";
                validChoice = true;
                break;
            case 'b':
                this->WorkType = "Periodic / Project based";
                validChoice = true;
                break;
            case 'c':
                this->WorkType = "Intern";
                validChoice = true;
                break;
            case 'd':
                this->WorkType = "Part time";
                validChoice = true;
                break;
            case 'e':
                this->WorkType = "Free Time";
                validChoice = true;
                break;
            case 'f':
                this->WorkType = "Consultancy";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->WorkType;
}

string Adversitement::getExperience() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Work Experience:" << endl;
        cout << "a) Inexperienced" << endl;
        cout << "b) 0-2 years" << endl;
        cout << "c) 2-5 years" << endl;
        cout << "d) 5+ years" << endl;
        cout << "Select Experience (a-d): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->Experience = "Inexperienced";
                validChoice = true;
                break;
            case 'b':
                this->Experience = "0-2 years";
                validChoice = true;
                break;
            case 'c':
                this->Experience = "2-5 years";
                validChoice = true;
                break;
            case 'd':
                this->Experience = "5+ years";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->Experience;
}

string Adversitement::getPositionLevel()  {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Position Level:" << endl;
        cout << "a) Senior executive" << endl;
        cout << "b) Middle manager" << endl;
        cout << "c) Management candidate" << endl;
        cout << "d) Expert" << endl;
        cout << "e) Beginner" << endl;
        cout << "f) Freelancer" << endl;
        cout << "g) Workers and Blue Collar" << endl;
        cout << "h) Intern" << endl;
        cout << "Select position level (a-h): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->PositionLevel = "Senior executive";
                validChoice = true;
                break;
            case 'b':
                this->PositionLevel = "Middle manager";
                validChoice = true;
                break;
            case 'c':
                this->PositionLevel = "Management candidate";
                validChoice = true;
                break;
            case 'd':
                this->PositionLevel = "Expert";
                validChoice = true;
                break;
            case 'e':
                this->PositionLevel = "Beginner";
                validChoice = true;
                break;
            case 'f':
                this->PositionLevel = "Freelancer";
                validChoice = true;
                break;
            case 'g':
                this->PositionLevel = "Workers and Blue Collar";
                validChoice = true;
                break;
            case 'h':
                this->PositionLevel = "Intern";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->PositionLevel;
}

string Adversitement::getEducationLevel() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Education Level:" << endl;
        cout << "a) PhD - Graduate" << endl;
        cout << "b) PhD - Student" << endl;
        cout << "c) Master - Graduate" << endl;
        cout << "d) Master's Degree - Student" << endl;
        cout << "e) University graduate" << endl;
        cout << "f) University student" << endl;
        cout << "g) Vocational School - Graduate" << endl;
        cout << "h) Vocational School - Student" << endl;
        cout << "i) High School - Graduate" << endl;
        cout << "Select Education level (a-i): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->EducationLevel = "PhD - Graduate";
                validChoice = true;
                break;
            case 'b':
                this->EducationLevel = "PhD - Student";
                validChoice = true;
                break;
            case 'c':
                this->EducationLevel = "Master - Graduate";
                validChoice = true;
                break;
            case 'd':
                this->EducationLevel = "Master's Degree - Student";
                validChoice = true;
                break;
            case 'e':
                this->EducationLevel = "University graduate";
                validChoice = true;
                break;
            case 'f':
                this->EducationLevel = "University student";
                validChoice = true;
                break;
            case 'g':
                this->EducationLevel = "Vocational School - Graduate";
                validChoice = true;
                break;
            case 'h':
                this->EducationLevel = "Vocational School - Student";
                validChoice = true;
                break;
            case 'i':
                this->EducationLevel = "High School - Graduate";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->EducationLevel;
}

string Adversitement::getLanguage() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Foreign Languages:" << endl;
        cout << "a) Turkish" << endl;
        cout << "b) English" << endl;
        cout << "c) Chinese" << endl;
        cout << "d) Spanish" << endl;
        cout << "e) Portuguese" << endl;
        cout << "f) Russian" << endl;
        cout << "g) German" << endl;
        cout << "h) French" << endl;
        cout << "i) Hindi" << endl;
        cout << "j) Japanese" << endl;
        cout << "Select Language (a-j): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->Language = "Turkish";
                validChoice = true;
                break;
            case 'b':
                this->Language = "English";
                validChoice = true;
                break;
            case 'c':
                this->Language = "Chinese";
                validChoice = true;
                break;
            case 'd':
                this->Language = "Spanish";
                validChoice = true;
                break;
            case 'e':
                this->Language = "Portuguese";
                validChoice = true;
                break;
            case 'f':
                this->Language = "Russian";
                validChoice = true;
                break;
            case 'g':
                this->Language = "German";
                validChoice = true;
                break;
            case 'h':
                this->Language = "French";
                validChoice = true;
                break;
            case 'i':
                this->Language = "Hindi";
                validChoice = true;
                break;
            case 'j':
                this->Language = "Japanese";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->Language;
}

string Adversitement::getMilitaryService() {
    char choice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Military Service Status:" << endl;
        cout << "a) Done, Exempt" << endl;
        cout << "b) Not Done (Postponed)" << endl;
        cout << "Select Preference (a-b): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                this->MilitaryService = "Done, Exempt";
                validChoice = true;
                break;
            case 'b':
                this->MilitaryService = "Not Done (Postponed)";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
    return this->MilitaryService;
}
/*void Adversitement::displayEducation() {
    cout << "Enter Education level: " << endl;
    cout << "1-PhD - Graduate" << endl;
    cout << "2-PhD - Student" << endl;
    cout << "3-Master - Graduate" << endl;
    cout << "4-Master's Degree - Student" << endl;
    cout << "5-University graduate" << endl;
    cout << "6-College student" << endl;
    cout << "7-Vocational School - Graduate" << endl;
    cout << "8-Vocational School - Student" << endl;
    cout << "9-High School - Graduate" << endl;
}*/
void Adversitement::printMenu(){
    int ch;
    cout << "Welcome to Adverts " << endl;
    cout << "1-Show Adverts: " << endl;
    cout << "2-Add Adverts:" << endl;
    cout << "3-Exit..." << endl;
    cin >> ch;
    if(ch==1){
        display();
    }
    if(ch==2){
        cout << "Welcome to Add Advert " << endl;
        cout << "Enter Number of Quotas: ";
        cin >> adversitements.NumberofQuotas;
        cin.ignore();
        cout << "Enter Advert Title: ";
        getline(cin,adversitements.AdTitle);
        cout << "Emter Company Description: ";
        getline(cin,adversitements.CompanyDescription);
        cin.ignore();
        cout << "Enter Salary Expectation: ";
        cin >> adversitements.Salary;
        cin.ignore();
        cout << "City: ";
        getline(cin,adversitements.City);
        cout << "Enter ApplicationDeadline: ";
        getline(cin,adversitements.ApplicationDeadline);
        cout << getPosition() << endl;
        cout << getSector() << endl;
        cout << getWorkPreference() << endl;
        cout << getWorkType() << endl;
        cout << getExperience() << endl;
        cout << getPositionLevel() << endl;
        cout << getEducationLevel() << endl;
        cout << getLanguage() << endl;
        cout << getMilitaryService() << endl;
        /*
        cin.ignore();
        cout << "Enter Experience (in years):" << endl;
        cout << "Inexperienced" << endl;
        cout << "0-2 years" << endl;
        cout << "2-5 years" << endl;
        cout << "More than 5 " << endl;
        cin >> adversitements.Experience;
        cin.ignore();
         */

    }
}

void Adversitement::display() {
    cout << "Adversitement Information " << endl;
    for (size_t i = 0; i < getNumberofQuotas(); i++) {
        cout << i + 1 << " Advert Title: " << adversitement[i].getAdTitle() << endl;
        cout << " Company Description: " << adversitement[i].getCompanyDescription() << endl;
        cout << " Salary: " << adversitement[i].getSalary() << endl;
        cout << " City: " << adversitement[i].getCity() << endl;
        cout << " Application Deadline: " << adversitement[i].getApplicationDeadline() << endl;
        cout << " Position:" << getPosition() << endl;
        cout << " Sector:" << getSector() << endl;
        cout << " Work Preference: " << getWorkPreference() << endl;
        cout << "Work Type:" << getWorkType() << endl;
        cout << " Experience : " << getExperience() << endl;
        cout << " Position Level: " << getPositionLevel() << endl;
        cout << " Education Level: " << getEducationLevel() << endl;
        cout << " Language: " << getLanguage() << endl;
        cout << " Military Service Status" << getMilitaryService() << endl;
    }
}

