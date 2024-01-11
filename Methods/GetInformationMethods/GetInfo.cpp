//
// Created by cemsr on 20.12.2023.
//

#include <iostream>
#include <string>
using namespace std;


//Getting Candidate Profile Information's from Candidate
void getCandidateProfileInfo(string& candidateFirstName, string& candidateLastName, string& candidateGender,int& candidateBirthDay, int& candidateBirthMonth, int& candidateBirthYear,string& candidateNationality, string& candidateIdentityNumber,bool& candidateDisabilitySituation, bool& candidateRelativeOfMartyr,bool& candidateHasDoneMilitaryService, bool& candidateWorkingStatus){

    cout << "We are delighted to have you among us! Please enter your personal informations:" << endl;

    cout << "Enter your first name:";
    cin >> candidateFirstName;
    cout << "Enter your last name:";
    cin >> candidateLastName;
    cout << "Enter gender(Male/Female/Other):";
    cin >> candidateGender;
    cout << "Enter date of birth: \n"
         << "Your birth day:" ;
    cin >> candidateBirthDay;
    cout << "Your birth month:";
    cin >> candidateBirthMonth;
    cout << "Your birth year:";
    cin >> candidateBirthYear;
    cout << "Enter nationality:";
    cin >> candidateNationality;
    cout << "Enter identity number:";
    cin >> candidateIdentityNumber;
    cout << "Is there any disability or limitation on your end? (1 for Yes, 0 for No):";
    cin >> candidateDisabilitySituation;
    cout << "Are you a relative of a martyr or a veteran? (1 for Yes, 0 for No):";
    cin >> candidateRelativeOfMartyr;
    cout << "Has military service? (1 for Yes, 0 for No):";
    cin >>  candidateHasDoneMilitaryService;
    cout << "Is currently working? (1 for Yes, 0 for No):";
    cin >>  candidateWorkingStatus;
}

//Getting Company Profile Information's from Company
void getCompanyProfileInfo(string& companyName, string& number, string& email, string& city, string& taxNumber, string& taxOfficecity){

    cout << "We are delighted to have you among us! Please enter your personal informations:" << endl;

    cin.ignore();
    cout << "Enter your company name:";
    getline(cin,companyName);
    cout << "Your company's communication informations:" << endl;
    cout << "Phone number:";
    getline(cin,number);
    cout << "Email address:";
    getline(cin,email);
    cout << "The city where your company is located:";
    getline(cin,city);
    cout << "Your company's tax number:";
    getline(cin,taxNumber);
    cout << "Your company's tax office-city:";
    getline(cin,taxOfficecity);
}

//Getting Advertisement Information
void getAdvertisementInfo(string& adTitle,
                          string& companyDescription,
                          int& salary,
                          float& point,
                          string& city,
                          string& applicationDeadLine,
                          string& sector,
                          string& position,
                          string& workPreference,
                          string& workType,
                          string& experience,
                          string& positionLevel,
                          string& educationLevel,
                          string& language,
                          string& militaryService) {
    cin.ignore();

    cout << "Enter Your Advertisement Title:";
    getline(cin,adTitle);

    cout << "Enter Your Company Description:";
    getline(cin,companyDescription);

    cin.ignore();

    cout << "Enter The Your Salary You Will Provide($):";
    cin >> salary;

    cout << "Enter Your Advertisement's Quality(0-100):";
    cin >> point;
    cin.ignore();

    cout << "City:";
    getline(cin,city);

    cout << "Enter ApplicationDeadLine:";
    getline(cin,applicationDeadLine);

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
                sector = "Technology and Software";
                validChoice = true;
                break;
            case 'b':
                sector = "Finance and Banking";
                validChoice = true;
                break;
            case 'c':
                sector = "Retail and Sales";
                validChoice = true;
                break;
            case 'd':
                sector = "Media and Entertainment";
                validChoice = true;
                break;
            case 'e':
                sector = "Agriculture and Farming";
                validChoice = true;
                break;
            case 'f':
                sector = "Automotive";
                validChoice = true;
                break;
            case 'g':
                sector = "Tourism and Accommodation";
                validChoice = true;
                break;
            case 'h':
                sector = "Civil Engineering";
                validChoice = true;
                break;
            case 'i':
                sector = "Electric Engineering";
                validChoice = true;
                break;
            case 'j':
                sector = "Energy and Renewable Resources";
                validChoice = true;
                break;
            case 'k':
                sector = "Service Sector (Consulting, Cleaning, Transportation)";
                validChoice = true;
                break;
            case 'l':
                sector = "Fashion and Clothing";
                validChoice = true;
                break;
            case 'm':
                sector = "Logistics and Distribution";
                validChoice = true;
                break;
            case 'n':
                sector = "Textile";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
//----------------------------------------------------------------------------------------------------------------------
    validChoice = false;
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
                position = "Customer Representative";
                validChoice = true;
                break;
            case 'b':
                position = "Sales Representative";
                validChoice = true;
                break;
            case 'c':
                position = "Software specialist";
                validChoice = true;
                break;
            case 'd':
                position = "Accounting staff";
                validChoice = true;
                break;
            case 'e':
                position = "Software developing expert";
                validChoice = true;
                break;
            case 'f':
                position = "Store manager";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
//----------------------------------------------------------------------------------------------------------------------
    validChoice = false;
    while (!validChoice) {
        cout << "Work Preference:" << endl;
        cout << "a) Remote/Remote" << endl;
        cout << "b) At the workplace" << endl;
        cout << "c) Hybrid" << endl;
        cout << "Select Preference (a-c): ";
        cin >> choice;

        switch (choice) {
            case 'a':
                workPreference = "Remote/Remote";
                validChoice = true;
                break;
            case 'b':
                workPreference = "At the workplace";
                validChoice = true;
                break;
            case 'c':
                workPreference = "Hybrid";
                validChoice = true;
                break;

            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
//----------------------------------------------------------------------------------------------------------------------
    validChoice = false;
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
                workType = "Permanent / Full time";
                validChoice = true;
                break;
            case 'b':
                workType = "Periodic / Project based";
                validChoice = true;
                break;
            case 'c':
                workType = "Intern";
                validChoice = true;
                break;
            case 'd':
                workType = "Part time";
                validChoice = true;
                break;
            case 'e':
                workType = "Free Time";
                validChoice = true;
                break;
            case 'f':
                workType = "Consultancy";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
//----------------------------------------------------------------------------------------------------------------------
    validChoice = false;
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
                experience = "Inexperienced";
                validChoice = true;
                break;
            case 'b':
                experience = "0-2 years";
                validChoice = true;
                break;
            case 'c':
                experience = "2-5 years";
                validChoice = true;
                break;
            case 'd':
                experience = "5+ years";
                validChoice = true;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
    }
//----------------------------------------------------------------------------------------------------------------------
        validChoice = false;
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
                    positionLevel = "Senior executive";
                    validChoice = true;
                    break;
                case 'b':
                    positionLevel = "Middle manager";
                    validChoice = true;
                    break;
                case 'c':
                    positionLevel = "Management candidate";
                    validChoice = true;
                    break;
                case 'd':
                    positionLevel = "Expert";
                    validChoice = true;
                    break;
                case 'e':
                    positionLevel = "Beginner";
                    validChoice = true;
                    break;
                case 'f':
                    positionLevel = "Freelancer";
                    validChoice = true;
                    break;
                case 'g':
                    positionLevel = "Workers and Blue Collar";
                    validChoice = true;
                    break;
                case 'h':
                    positionLevel = "Intern";
                    validChoice = true;
                    break;
                default:
                    cout << "Invalid choice! Please select again." << endl;
                    break;
            }
        }
//----------------------------------------------------------------------------------------------------------------------
         validChoice = false;
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
                    educationLevel = "PhD - Graduate";
                    validChoice = true;
                    break;
                case 'b':
                    educationLevel = "PhD - Student";
                    validChoice = true;
                    break;
                case 'c':
                    educationLevel = "Master - Graduate";
                    validChoice = true;
                    break;
                case 'd':
                    educationLevel = "Master's Degree - Student";
                    validChoice = true;
                    break;
                case 'e':
                    educationLevel = "University graduate";
                    validChoice = true;
                    break;
                case 'f':
                    educationLevel = "University student";
                    validChoice = true;
                    break;
                case 'g':
                    educationLevel = "Vocational School - Graduate";
                    validChoice = true;
                    break;
                case 'h':
                    educationLevel = "Vocational School - Student";
                    validChoice = true;
                    break;
                case 'i':
                    educationLevel = "High School - Graduate";
                    validChoice = true;
                    break;
                default:
                    cout << "Invalid choice! Please select again." << endl;
                    break;
            }
        }
//----------------------------------------------------------------------------------------------------------------------
        validChoice = false;
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
                    language = "Turkish";
                    validChoice = true;
                    break;
                case 'b':
                    language = "English";
                    validChoice = true;
                    break;
                case 'c':
                    language = "Chinese";
                    validChoice = true;
                    break;
                case 'd':
                    language = "Spanish";
                    validChoice = true;
                    break;
                case 'e':
                    language = "Portuguese";
                    validChoice = true;
                    break;
                case 'f':
                    language = "Russian";
                    validChoice = true;
                    break;
                case 'g':
                    language = "German";
                    validChoice = true;
                    break;
                case 'h':
                    language = "French";
                    validChoice = true;
                    break;
                case 'i':
                    language = "Hindi";
                    validChoice = true;
                    break;
                case 'j':
                    language = "Japanese";
                    validChoice = true;
                    break;
                default:
                    cout << "Invalid choice! Please select again." << endl;
                    break;
            }
        }
//----------------------------------------------------------------------------------------------------------------------
        validChoice = false;
        while (!validChoice) {
            cout << "Military Service Status:" << endl;
            cout << "a) Done, Exempt" << endl;
            cout << "b) Not Done (Postponed)" << endl;
            cout << "Select Preference (a-b): ";
            cin >> choice;

            switch (choice) {
                case 'a':
                    militaryService = "Done, Exempt";
                    validChoice = true;
                    break;
                case 'b':
                    militaryService = "Not Done (Postponed)";
                    validChoice = true;
                    break;
                default:
                    cout << "Invalid choice! Please select again." << endl;
                    break;
            }
        }
    cin.ignore();
}