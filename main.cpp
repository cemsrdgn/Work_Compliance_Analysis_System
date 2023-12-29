//
// Created by cemsr on 15.12.2023.
//

#include "Candidate/User.cpp"
#include "Src/Company/Company.cpp"
#include "Src/Adversitement/Adversitement.h"
#include "Src/Adversitement/Adversitement.cpp"
#include "Formats/Date Format/Date.cpp"
#include "Methods/MenuMethods/MenuMethods.cpp"
#include "Methods/GetInformationMethods//GetInfo.cpp"


#include <iostream>
#include <string>

using namespace std;

int main() {

    MenuMethods menuMethods;

    User dummyUser1(User::nextId++, "Dummy1", "User1", "Male", 1, 1, 1990, "DummyCountry", "123456789", false, true,
                    false, false);
    User::users.push_back(dummyUser1);
    User dummyUser2(User::nextId++, "Dummy2", "User2", "Female", 2, 2, 1995, "DummyCountry", "987654321", true, false,
                    true, false);
    User::users.push_back(dummyUser2);


    //Advertisement özellikleri için tanımlamalar:
    int AdvertisementId, NumberOfQuotas, Salary;
    string AdTitle, CompanyDescription, City, ApplicationDeadLine;
    string AdSector, AdPosition, AdWorkPreference, AdWorkType, AdExperience, ADPositionLevel, AdEducationLevel, AdLanguage, AdMilitaryService;

    AdvertisementId = Adversitement::nextAdId;

    getAdvertisementInfo(AdTitle,
                         CompanyDescription,
                         Salary,
                         City,
                         ApplicationDeadLine,
                         AdSector,
                         AdPosition,
                         AdWorkPreference,
                         AdWorkType,
                         AdExperience,
                         ADPositionLevel,
                         AdEducationLevel,
                         AdLanguage,
                         AdMilitaryService);

    Adversitement newAdversitement;

    newAdversitement = Adversitement(AdTitle,
                                     CompanyDescription,
                                     Salary,
                                     City,
                                     ApplicationDeadLine,
                                     AdvertisementId,
                                     AdSector,
                                     AdPosition,
                                     AdWorkPreference,
                                     AdWorkType,
                                     AdExperience,
                                     ADPositionLevel,
                                     AdEducationLevel,
                                     AdLanguage,
                                     AdMilitaryService);

    Adversitement::adversitement.push_back(newAdversitement);

    newAdversitement.display();













    // Tüm kullanıcıları göster
    User::displayAllCandidates();

    //User personal infoları için tanımlamalar
    string userFirstName, userLastName, userGender, userNationality, userIdentityNumber;
    bool userDisabilitySituation = false, userRelativeOfMarty = false;
    bool userHasDoneMilitaryService = false, userWorkingStatus = false;
    int userBirthDay, userBirthMonth, userBirthYear;



    //Back option for user's and company's login and register menu
    bool hasWelcomeScreenBackCalled = true;

    //Back option for user's  main menu menu
    bool hasCandidateMainMenuBackCalled = true;


    bool hasCandidateMainMenuCalled = false;


    string nameCheck, passwordCheck;
    int back;
    int candidateMyProfileChoice,welcomeChoice,candidateMainMenuChoice;


    User loggedInUser;
    User newUser;

    Company newCompany;
    Company loggedInCompany;

    int userId;

    while (hasWelcomeScreenBackCalled) {
        welcomeChoice=menuMethods.WelcomeScreen();
        switch (welcomeChoice) {
            case 1:  //Load Candidates Options
                switch (menuMethods.CandidateLoginAndRegisterMenu()) {
                    case 1:  //Candidate login
                        cout << "User login page is loading.." << endl;
                        hasCandidateMainMenuCalled=false;

                        while (!hasCandidateMainMenuCalled) {

                            cout << "User is not found.Please try again!" << endl;

                            cout << "Username:";
                            cin >> nameCheck;
                            cout << "Password:";
                            cin >> passwordCheck;

                            for (auto & user : User::users) {
                                if (user.getFirstName() == nameCheck) {
                                    if (user.getLastName() == passwordCheck) {
                                        cout << "Successful login. Redirecting to the main menu..." << endl;
                                        loggedInUser = user;
                                        hasCandidateMainMenuCalled = true;
                                        break;}
                                    else{
                                        cout << "Invalid password or username!" << endl;
                                        hasCandidateMainMenuCalled = false;}
                                }}}

                        hasWelcomeScreenBackCalled = false;
                        hasCandidateMainMenuBackCalled=true;
                        break;

                    case 2: // Candidate register
                        cout << "User register page is loading..." << endl;

                        userId = User::nextId++;

                        getCandidateProfileInfo(userFirstName, userLastName, userGender, userBirthDay,
                                                userBirthMonth,
                                                userBirthYear, userNationality, userIdentityNumber,
                                                userDisabilitySituation,
                                                userRelativeOfMarty, userHasDoneMilitaryService, userWorkingStatus);

                        newUser = User(userId, userFirstName, userLastName, userGender,
                                       userBirthDay, userBirthMonth, userBirthYear,
                                       userNationality, userIdentityNumber,
                                       userDisabilitySituation, userRelativeOfMarty,
                                       userHasDoneMilitaryService, userWorkingStatus);

                        newUser.createCandidateUserName();
                        newUser.createCandidatePassword();

                        // Kullanıcıyı veritabanına ekle
                        User::users.push_back(newUser);

                        cout << "Your registration process has been successfully completed!" << endl;

                        newUser.displayCandidateUserName();
                        newUser.displayCandidatePassword();

                        loggedInUser = newUser;


                        cout << "--------------------------------------------------------------------" << endl;

                        while(hasCandidateMainMenuBackCalled) {
                            candidateMainMenuChoice=menuMethods.CandidateMainMenu();
                            switch (candidateMainMenuChoice) {
                                case 1: // 1-Adverts that might suit me
                                    cout << "Displaying adverts might suit me..." << endl;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                case 2: // 2-Display all adverts
                                    cout << "Displaying all adverts..." << endl;

                                   // Adversitement::displayAllAdversitements();

                                    hasCandidateMainMenuBackCalled = false;

                                    //newAdversitement.display();
                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back=menuMethods.getUserInputWithControl();
                                    if(back==1){continue;}
                                    break;

                                case 3: // 3-My Profile
                                    cout << "Profile page is loading..." << endl;
                                    candidateMyProfileChoice = menuMethods.CandidateMyProfile();
                                    switch (candidateMyProfileChoice) {
                                        case 1: // Display My Profile Information
                                            cout << "Your profile informations:" << endl;
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back=menuMethods.getUserInputWithControl();
                                            if(back==1){continue;}
                                            break;

                                        case 2: // Update My Profile Information

                                            User::users.pop_back();
                                            newUser.updateCandidateProfileInformation();
                                            cout << "Your new profile informations:" << endl;
                                            User::users.push_back(newUser);
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back=menuMethods.getUserInputWithControl();
                                            if(back==1){continue;}


                                        case 3: // Back to Candidate Main Menu
                                            cout << "Returning to candidate main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;
                                    }
                                    break;

                                case 4: // 4-My CV
                                    cout << "My CV page is loading..." << endl;
                                    switch (menuMethods.CandidateCV()) {
                                        case 1: // Add Communication Information
                                            cout << "Add communication information to your cv:" << endl;
                                            break;
                                        case 2: // Add Education Information
                                            cout << "Add education information to your cv:" << endl;
                                            break;
                                        case 3: // Add Language Skills
                                            cout << "Add language skill to your cv:" << endl;
                                            break;
                                        case 4: // Add Work Experiences
                                            cout << "Add work experience to your cv:" << endl;
                                            break;
                                        case 5: // Add Projects
                                            cout << "Add project to your cv:" << endl;
                                            break;
                                        case 6: // Add Exams Information
                                            cout << "Add exams information to your cv:" << endl;
                                            break;
                                        case 7: // Add Expertise Areas
                                            cout << "Add expertise area to your cv:" << endl;
                                            break;
                                        case 8: // Add Reference
                                            cout << "Add reference to your cv:" << endl;
                                            break;
                                        case 9: // Add Certificate
                                            cout << "Add certificate to your cv:" << endl;
                                            break;
                                        case 10: // Add Working Conditions
                                            cout << "Add working condition to your cv:" << endl;
                                            break;
                                        case 11: // Add Social Skills
                                            cout << "Add social skill to your cv:" << endl;
                                            break;
                                        case 12: // Add Hobbies
                                            cout << "Add Hobbies to your cv:" << endl;
                                            break;
                                        case 13: // Back to User Main Menu
                                            cout << "Returning to candidate main menu..." << endl;
                                            continue;
                                    }
                                    break;

                                case 5: // 5-My Rank and Applied Ads
                                    cout << "My Rank and Applied Ads page is loading..." << endl;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                case 6:
                                    // Exit to welcome screen
                                    cout << "Exiting to welcome screen..." << endl;
                                    hasWelcomeScreenBackCalled=true;
                                    hasCandidateMainMenuBackCalled= false;
                                    break;

                                default:
                                    cout << "\nInvalid choice. Please enter a valid option." << endl;
                                    break;

                            }
                            break;

                        }

                    case 3: // Return back to welcome screen from Candidate page
                    cout << "Returning back from candidate page..." << endl;
                    hasWelcomeScreenBackCalled = true;
                    break;

                }
                break;

            case 2: //Load Company Options
                switch (menuMethods.CompanyLoginAndRegisterMenu()) {
                    case 1: //Company login
                        cout << "Company login page is loading.." << endl;

                        hasWelcomeScreenBackCalled = false;
                        break;

                    case 2: //Company Register
                        cout << "Company register page is loading..." << endl;

                        hasWelcomeScreenBackCalled = false;
                        break;

                    case 3: //Return back to welcome screen from Company page
                        cout << "Returning back from company page...";

                        hasWelcomeScreenBackCalled = true;
                        break;
                }
                break;

            case 3: //Exit from system
                cout << "Exiting System..." << endl;
                return 0;

            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
                break;
        }
    }


    while(hasCandidateMainMenuBackCalled) {
        candidateMainMenuChoice = menuMethods.CandidateMainMenu();
        switch (candidateMainMenuChoice) {
            case 1: // 1-Adverts that might suit me
                cout << "Displaying adverts might suit me..." << endl;
                hasCandidateMainMenuBackCalled = false;
                break;

            case 2: // 2-Display all adverts
                cout << "Displaying all adverts..." << endl;
                hasCandidateMainMenuBackCalled = false;
                break;

            case 3: // 3-My Profile
                cout << "Profile page is loading..." << endl;
                candidateMyProfileChoice = menuMethods.CandidateMyProfile();
                switch (candidateMyProfileChoice) {
                    case 1: // Display My Profile Information
                        cout << "Your profile informations:" << endl;
                        newUser.displayCandidateInformation();

                        back = menuMethods.getUserInputWithControl();
                        if (back == 1) { hasCandidateMainMenuBackCalled = true; }
                        break;

                    case 2: // Update My Profile Information

                        User::users.pop_back();
                        newUser.updateCandidateProfileInformation();
                        cout << "Your new profile informations:" << endl;
                        User::users.push_back(newUser);
                        newUser.displayCandidateInformation();

                        cout << "1-Back to Candidate Main Menu\n>";
                        back = menuMethods.getUserInputWithControl();
                        if (back == 1) { hasCandidateMainMenuBackCalled = true; }
                        break;

                    case 3: // Back to Candidate Main Menu
                        cout << "Returning to candidate main menu..." << endl;
                        hasCandidateMainMenuBackCalled = true;
                        break;

                    default:
                        cout << "\nInvalid choice. Please enter a valid option." << endl;
                        break;
                }
                break;

            case 4: // 4-My CV
                cout << "My CV page is loading..." << endl;
                switch (menuMethods.CandidateCV()) {
                    case 1: // Add Communication Information
                        cout << "Add communication information to your cv:" << endl;
                        break;
                    case 2: // Add Education Information
                        cout << "Add education information to your cv:" << endl;
                        break;
                    case 3: // Add Language Skills
                        cout << "Add language skill to your cv:" << endl;
                        break;
                    case 4: // Add Work Experiences
                        cout << "Add work experience to your cv:" << endl;
                        break;
                    case 5: // Add Projects
                        cout << "Add project to your cv:" << endl;
                        break;
                    case 6: // Add Exams Information
                        cout << "Add exams information to your cv:" << endl;
                        break;
                    case 7: // Add Expertise Areas
                        cout << "Add expertise area to your cv:" << endl;
                        break;
                    case 8: // Add Reference
                        cout << "Add reference to your cv:" << endl;
                        break;
                    case 9: // Add Certificate
                        cout << "Add certificate to your cv:" << endl;
                        break;
                    case 10: // Add Working Conditions
                        cout << "Add working condition to your cv:" << endl;
                        break;
                    case 11: // Add Social Skills
                        cout << "Add social skill to your cv:" << endl;
                        break;
                    case 12: // Add Hobbies
                        cout << "Add Hobbies to your cv:" << endl;
                        break;
                    case 13: // Back to User Main Menu
                        cout << "Returning to candidate main menu..." << endl;
                        break;
                }
                break;

            case 5: // 5-My Rank and Applied Ads
                cout << "My Rank and Applied Ads page is loading..." << endl;
                hasCandidateMainMenuBackCalled = false;
                break;

            case 6:
                // Exit to welcome screen
                cout << "Exiting to welcome screen..." << endl;
                hasWelcomeScreenBackCalled = true;
                hasCandidateMainMenuBackCalled=false;

            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
                break;
        }
    }
    // Tüm kullanıcıları göster
    User::displayAllCandidates();





// Bir önceki menüye back methodu oluşturup atmalıyız ve de welcome screene aynısını yapmalıyız!!!!!!!!!!!!!!!




    return 0;
}
