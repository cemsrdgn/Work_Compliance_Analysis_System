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
#include "Candidate CV/Hobies/Hobie.h"


#include <iostream>
#include <string>

using namespace std;

int main() {

    MenuMethods menuMethods;

    User AliOzn(User::nextId++, "Ali", "Ozen", "Male", 21, 06, 2000, "Turkish", "21219841060", true, false,false, true);
    AliOzn.createCandidateUserName(); //Login için AliOzn kullanıcısı username: Ali.Ozen
    AliOzn.setPassword("123456"); //Login için AliOzn kullanıcısı password: 123456
    User::users.push_back(AliOzn);

    User MltmKlbk(User::nextId++, "Meltem", "Kelebek", "Female", 17, 05, 1989, "Canadian", "31269966233", false, true,false, true);
    MltmKlbk.createCandidateUserName(); //Login için MltmKlbk kullanıcısı username: Meltem.Kelebek
    MltmKlbk.setPassword("987654"); //Login için MltmKlbk kullanıcısı password: 987654
    User::users.push_back(MltmKlbk);

    Company RecordCompany(Company::nextCompanyId++, "RecordSoftware", "3123226895", "rcrdsftwr@gmail.com", "Berlin","6547983423", "Frankfurt");
    RecordCompany.createCompanyUserName();
    RecordCompany.setCompanyPassword("987654");
    Company::companies.push_back(RecordCompany);

    Company CoreCompany(Company::nextCompanyId++, "CoreBank", "2123654482", "core@gmail.com", "Istanbul","984565123485", "Ankara");
    CoreCompany.createCompanyUserName();
    CoreCompany.setCompanyPassword("123456");
    Company::companies.push_back(CoreCompany);


    Adversitement advert2("Ad Title 2", "Company Description 2", 60000, "Istanbul", "2023-01-20",Adversitement::nextAdId++, CoreCompany.getCompanyId(), "Finance and Banking","Accounting staff", "At the workplace","Periodic / Project based", "2-5 years", "Middle manager", "Master - Graduate", "German","Not Done (Postponed)");
    Adversitement::adversitement.push_back(advert2);

    Adversitement advert1("Ad Title 1", "Company Description 1", 50000, "Berlin", "2023-01-15",Adversitement::nextAdId++, RecordCompany.getCompanyId(), "Technology and Software","Software specialist", "Remote/Remote","Permanent / Full time", "0-2 years", "Beginner", "University graduate", "English","Done, Exempt");
    Adversitement::adversitement.push_back(advert1);


    //User profile infoları için tanımlamalar
    string userFirstName, userLastName, userGender, userNationality, userIdentityNumber;
    bool userDisabilitySituation = false, userRelativeOfMarty = false;
    bool userHasDoneMilitaryService = false, userWorkingStatus = false;
    int userBirthDay, userBirthMonth, userBirthYear;

    //Company profile infoları için tanımlamalar
    string CompanyName, CompanyPhoneNumber, CompanyEmail, CompanyCity, CompanyTaxNumber, CompanyTaxOfficeCity;

    //Advertisement özellikleri için tanımlamalar:
    int AdvertisementId, NumberOfQuotas, Salary;
    string AdTitle, CompanyDescription, City, ApplicationDeadLine;
    string AdSector, AdPosition, AdWorkPreference, AdWorkType, AdExperience, ADPositionLevel, AdEducationLevel, AdLanguage, AdMilitaryService;


    //Back option for user's and company's login and register menu
    bool hasWelcomeScreenBackCalled = true;

    //Back option for user's  main menu menu
    bool hasCandidateMainMenuBackCalled = true;
    bool hasCompanyMainMenuBackCalled = true;

    bool hasCandidateMainMenuCalled = false;
    bool hasCompanyMainMenuCalled = false;


    string nameCheckUser, passwordCheckUser, nameCheckCompany, passwordCheckCompany;
    int back;
    int candidateMyProfileChoice, welcomeChoice, candidateMainMenuChoice, companyMainMenuChoice;


    User newUser;
    Company newCompany;

    Adversitement newAdversitement;

    Hobie Hobies; string hobies;


    int userId;

    while (hasWelcomeScreenBackCalled) {
        switch (menuMethods.WelcomeScreen()) {
            case 1:  //Load Candidates Options
                switch (menuMethods.CandidateLoginAndRegisterMenu()) {
                    case 1:  //Candidate login
                        cout << "User login page is loading.." << endl;

                        hasCandidateMainMenuCalled = false;

                        while (!hasCandidateMainMenuCalled) {

                            cout << "Username:";
                            cin >> nameCheckUser;
                            cout << "Password:";
                            cin >> passwordCheckUser;

                            for (auto &user: User::users) {
                                if (user.getUserName() == nameCheckUser) {
                                    if (user.getPassword() == passwordCheckUser) {
                                        cout << "Successful login. Redirecting to the main menu..." << endl;
                                        newUser = user;
                                        hasCandidateMainMenuCalled = true;
                                        hasCandidateMainMenuBackCalled = true;
                                        break;
                                    } else {
                                        cout << "Invalid password or username!" << endl;
                                        hasCandidateMainMenuCalled = false;
                                        hasCandidateMainMenuBackCalled = false;
                                    }
                                }
                            }
                        }

                        hasWelcomeScreenBackCalled = false;

                        while (hasCandidateMainMenuBackCalled) {
                            candidateMainMenuChoice = menuMethods.CandidateMainMenu();
                            switch (candidateMainMenuChoice) {
                                case 1: // 1-Adverts that might suit me
                                    cout << "Displaying adverts might suit me..." << endl;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                case 2: // 2-Display all adverts
                                    cout << "Displaying all adverts..." << endl;

                                    Adversitement::displayAllAdversitements();

                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }

                                case 3: // 3-My Profile
                                    cout << "Profile page is loading..." << endl;
                                    candidateMyProfileChoice = menuMethods.CandidateMyProfile();
                                    switch (candidateMyProfileChoice) {
                                        case 1: // Display My Profile Information
                                            cout << "Your profile informations:" << endl;
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 2: // Update My Profile Information

                                            User::users.pop_back();
                                            newUser.updateCandidateProfileInformation();
                                            cout << "Your new profile informations:" << endl;
                                            User::users.push_back(newUser);
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }


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

                                            cout << "Hobbies:";
                                            cin >> hobies;
                                            cin.ignore();
                                            Hobies.add(newUser.getID(), hobies);
                                            cout << "Adding Successful..." << endl;

                                            Hobies.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 13: // Back to Candidate Main Menu
                                            cout << "Returning to candidate main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;
                                    }

                                case 5: // 5-My Rank and Applied Ads
                                    cout << "My Rank and Applied Ads page is loading..." << endl;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                case 6:
                                    // Exit to welcome screen
                                    cout << "Exiting to welcome screen..." << endl;
                                    hasWelcomeScreenBackCalled = true;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                default:
                                    cout << "\nInvalid choice. Please enter a valid option." << endl;
                                    break;

                            }
                            break;
                        }
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


                        hasCandidateMainMenuBackCalled = true;

                        cout << "--------------------------------------------------------------------" << endl;

                        while (true) {
                            candidateMainMenuChoice = menuMethods.CandidateMainMenu();
                            switch (candidateMainMenuChoice) {
                                case 1: // 1-Adverts that might suit me
                                    cout << "Displaying adverts might suit me..." << endl;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                case 2: // 2-Display all adverts
                                    cout << "Displaying all adverts..." << endl;

                                    Adversitement::displayAllAdversitements();

                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }
                                    break;

                                case 3: // 3-My Profile
                                    cout << "Profile page is loading..." << endl;
                                    candidateMyProfileChoice = menuMethods.CandidateMyProfile();
                                    switch (candidateMyProfileChoice) {
                                        case 1: // Display My Profile Information
                                            cout << "Your profile informations:" << endl;
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 2: // Update My Profile Information

                                            User::users.pop_back();
                                            newUser.updateCandidateProfileInformation();
                                            cout << "Your new profile informations:" << endl;
                                            User::users.push_back(newUser);
                                            newUser.displayCandidateInformation();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }


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
                                            cout << "Add Hobbies to your cv:" << endl;

                                            cout << "Hobbies:";
                                            cin >> hobies;
                                            cin.ignore();
                                            Hobies.add(newUser.getID(), hobies);
                                            cout << "Adding Successful..." << endl;

                                            Hobies.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

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
                                    hasWelcomeScreenBackCalled = true;
                                    hasCandidateMainMenuBackCalled = false;
                                    break;

                                default:
                                    cout << "\nInvalid choice. Please enter a valid option." << endl;
                                    break;

                            }
                            break;

                        }
                        break;

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
                        hasCompanyMainMenuCalled = false;

                        while (!hasCompanyMainMenuCalled) {

                            cout << "Company Username:";
                            cin >> nameCheckCompany;
                            cout << "Password:";
                            cin >> passwordCheckCompany;

                            for (auto &company: Company::companies) {
                                if (company.getCompanyUserName() == nameCheckCompany) {
                                    if (company.getCompanyPassword() == passwordCheckCompany) {
                                        cout << "Successful login. Redirecting to the main menu..." << endl;
                                        newCompany = company;
                                        hasCompanyMainMenuCalled = true;
                                        hasCompanyMainMenuBackCalled = true;
                                        break;
                                    } else {
                                        cout << "Invalid password or username!" << endl;
                                        hasCompanyMainMenuCalled = false;
                                        hasCompanyMainMenuBackCalled = false;
                                    }
                                }
                            }
                        }

                        hasCompanyMainMenuBackCalled = true;

                        while (hasCompanyMainMenuBackCalled) {

                            switch (menuMethods.CompanyMainMenu()) {
                                case 1: //Candidates Applied My Ads-------------------------------------------sonra

                                    cout << "Candidates Applied My Ads:" << endl;
                                    cout << "No one applied your ads." << endl;

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }

                                case 2: //Display All Candidates

                                    cout << "All candidates in the system:" << endl;
                                    User::displayAllCandidates();

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }


                                case 3: //Candidates Might Suit You
                                    cout << "Candidates Might Suit You:" << endl;

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }


                                case 4: //My Company Profile
                                    switch (menuMethods.CompanyMyProfile()) {
                                        case 1: //Display Company Profile

                                            cout << "Your company profile informations:" << endl;
                                            newCompany.displayCompanyProfileInformation();

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 2: //Update Company Profile

                                            Company::companies.pop_back();
                                            newCompany.updateCompanyProfileInformation();
                                            cout << "Your new profile informations:" << endl;
                                            Company::companies.push_back(newCompany);
                                            newCompany.displayCompanyProfileInformation();

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 3: //Back to Company Main Menu
                                            cout << "Returning to company main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;
                                    }
                                    break;

                                case 5: //My Adverts
                                    switch (menuMethods.CompanyAd()) {

                                        case 1: //Display my all adverts
                                            cout << "Display your ads page is loading..." << endl;

                                            newAdversitement.displayCompanyAdvertisements(newCompany.getCompanyId());

                                            cout << "------------------------------------------------------------"
                                                 << endl;

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 2: //Add adverts
                                            cout << "Add ads page is loading..." << endl;

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

                                            newAdversitement = Adversitement(AdTitle,
                                                                             CompanyDescription,
                                                                             Salary,
                                                                             City,
                                                                             ApplicationDeadLine,
                                                                             AdvertisementId,
                                                                             newCompany.getCompanyId(),
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

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 3: //Back to company main menu
                                            cout << "Returning to company main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;

                                    }
                                    break;

                                case 6: //Exit to Welcome Screen
                                    cout << "Exiting to welcome screen..." << endl;
                                    hasWelcomeScreenBackCalled = true;
                                    hasCompanyMainMenuBackCalled = false;
                                    break;

                                default:
                                    cout << "\nInvalid choice. Please enter a valid option." << endl;
                                    break;
                            }
                        }
                        break;

                    case 2: //Company Register

                        cout << "Company register page is loading..." << endl;

                        int CompanyId = Company::nextCompanyId++;

                        getCompanyProfileInfo(CompanyName,
                                              CompanyPhoneNumber,
                                              CompanyEmail,
                                              CompanyCity,
                                              CompanyTaxNumber,
                                              CompanyTaxOfficeCity);

                        newCompany = Company(CompanyId,
                                             CompanyName,
                                             CompanyPhoneNumber,
                                             CompanyEmail,
                                             CompanyCity,
                                             CompanyTaxNumber,
                                             CompanyTaxOfficeCity);

                        newCompany.createCompanyUserName();
                        newCompany.createCompanyPassword();

                        // Şirketi veri tabanına ekle
                        Company::companies.push_back(newCompany);

                        cout << "Your registration process has been successfully completed!" << endl;

                        newCompany.displayCompanyUserName();
                        newCompany.displayCompanyPassword();


                        cout << "--------------------------------------------------------------------" << endl;

                        hasCompanyMainMenuBackCalled = true;

                        while (hasCompanyMainMenuBackCalled) {

                            switch (menuMethods.CompanyMainMenu()) {
                                case 1: //Candidates Applied My Ads-------------------------------------------sonra

                                    cout << "Candidates Applied My Ads:" << endl;

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }

                                case 2: //Display All Candidates

                                    cout << "All candidates in the system:" << endl;
                                    User::displayAllCandidates();

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }


                                case 3: //Candidates Might Suit You
                                    cout << "Candidates Might Suit You:" << endl;

                                    cout << "1-Back to Company Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }


                                case 4: //My Company Profile
                                    switch (menuMethods.CompanyMyProfile()) {
                                        case 1: //Display Company Profile

                                            cout << "Your company profile informations:" << endl;
                                            newCompany.displayCompanyProfileInformation();

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 2: //Update Company Profile

                                            Company::companies.pop_back();
                                            newCompany.updateCompanyProfileInformation();
                                            cout << "Your new profile informations:" << endl;
                                            Company::companies.push_back(newCompany);
                                            newCompany.displayCompanyProfileInformation();

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 3: //Back to Company Main Menu
                                            cout << "Returning to company main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;
                                    }
                                    break;

                                case 5: //My Adverts
                                    switch (menuMethods.CompanyAd()) {

                                        case 1: //Display my all adverts
                                            cout << "Display your ads page is loading..." << endl;

                                            newAdversitement.displayCompanyAdvertisements(newCompany.getCompanyId());

                                            cout << "------------------------------------------------------------"
                                                 << endl;

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 2: //Add adverts
                                            cout << "Add ads page is loading..." << endl;

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

                                            newAdversitement = Adversitement(AdTitle,
                                                                             CompanyDescription,
                                                                             Salary,
                                                                             City,
                                                                             ApplicationDeadLine,
                                                                             AdvertisementId,
                                                                             newCompany.getCompanyId(),
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

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 3: //Update adverts
                                            cout << "Update ads page is loading..." << endl;

                                            newAdversitement.displayCompanyAdvertisements(newCompany.getCompanyId());


                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 4: //Remove adverts
                                            cout << "Remove your ads page is loading..." << endl;

                                            cout << "1-Back to Company Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 5: //Back to company main menu
                                            cout << "Returning to company main menu..." << endl;
                                            continue;

                                        default:
                                            cout << "\nInvalid choice. Please enter a valid option." << endl;
                                            break;

                                    }
                                    break;

                                case 6: //Exit to Welcome Screen
                                    cout << "Exiting to welcome screen..." << endl;
                                    hasWelcomeScreenBackCalled = true;
                                    hasCompanyMainMenuBackCalled = false;
                                    break;

                                default:
                                    cout << "\nInvalid choice. Please enter a valid option." << endl;
                                    break;
                            }
                        }
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


// Tüm kullanıcıları göster
    User::displayAllCandidates();

    return 0;
}
