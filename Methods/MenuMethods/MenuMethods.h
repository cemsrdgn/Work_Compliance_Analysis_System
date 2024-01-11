//
// Created by cemsr on 22.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_MENUMETHODS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_MENUMETHODS_H


class MenuMethods {

public:

    //It is control for non number inputs. Like chars or symbols.
    int getUserInputWithControl();

    //Welcome screen to distinguish between company and candidate login
    int WelcomeScreen();

    //Options and MenuLoop After Select Candidate Option
    int CandidateLoginAndRegisterMenu();

    //Candidate Main Menu
    int CandidateMainMenu();

    //Candidate My Profile Menu
    int CandidateMyProfile();

    //Candidate's other classes(CV) which wants to add
    int CandidateCV();

    //Options and MenuLoop After Select Company Option
    int CompanyLoginAndRegisterMenu();

    //Company Main Menu
    int CompanyMainMenu();

    //Company Profile
    int CompanyMyProfile();

    //Company Advertisement
    int CompanyAd();
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_MENUMETHODS_H
