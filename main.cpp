//
// Created by cemsr on 15.12.2023.
//
#include "Candidate/User.h"
#include "Candidate/User.cpp"
#include "Common/Formats/Date Format/Date.cpp"
#include "Common/Methods/MenuMethods//SelectOptionNumber.cpp"
#include "Common/Methods/GetInformationMethods///GetInfo.cpp"

#include <iostream>
#include <string>
using namespace std;



int main() {

    
    User dummyUser1(User::nextId++,"Dummy1","User1","Male",1,1,1990,
                    "DummyCountry","123456789",false,true);
    User::users.push_back(dummyUser1);

    User dummyUser2(User::nextId++,"Dummy2","User2","Female",2,2,1995,
            "DummyCountry","987654321",true,false);
    User::users.push_back(dummyUser2);


    //User personal infoları için tanımlamalar
    string userFirstName, userLastName, userGender, userNationality, userIdentityNumber;
    bool userHasDoneMilitaryService = false, userWorkingStatus = false;
    int userBirthDay, userBirthMonth, userBirthYear;

    //Continue user actions for which operation has been selected
    bool hasUserLoginPageCalled = false;
    bool hasUserRegisterPageCalled = false;
    bool hasUserBackCalled = false;

    //Continue company actions for which operation has been selected
    bool hasCompanyLoginPageCalled = false;
    bool hasCompanyRegisterPageCalled = false;
    bool hasCompanyBackCalled = false;

    //Continue user main menu actions for which operation has been selected
    bool hasUserMyCVPageCalled = false;


        switch (WelcomeScreen()) {

            //Load User Options for operation number 1
            case 1:
                switch (UserLoginAndRegisterMenu()) {
                    //User login for operation number 1
                    case 1:
                        cout << "User login page is not accessible now. Please try again later!.." << endl;
                        hasUserLoginPageCalled = true;
                        hasUserLoginPageCalled = false;
                        hasUserBackCalled = false;
                        break;
                        //User register for operation number 2
                    case 2:
                        cout << "User register page is loading..." << endl;
                        hasUserLoginPageCalled = false;
                        hasUserRegisterPageCalled = true;
                        hasUserBackCalled = false;
                        break;
                        //Exit from user page for operation number 3
                    case 3:
                        cout << "Returning back from user page...";
                        hasUserLoginPageCalled = false;
                        hasUserRegisterPageCalled = false;
                        hasUserBackCalled = true;
                        break;
                }
                break;
                //Load Company Options for operation number 1
            case 2:
                switch (CompanyLoginAndRegisterMenu()) {
                    //Company login for operation number 1
                    case 1:
                        cout << "Company login page is not accessible now. Please try again later!.." << endl;
                        hasCompanyLoginPageCalled = true;
                        hasUserRegisterPageCalled = false;
                        hasCompanyBackCalled = false;
                        break;
                        //Company Register for operation number 2
                    case 2:
                        cout << "Company register page is not accessible now. Please try again later!.." << endl;

                        hasCompanyLoginPageCalled = false;
                        hasCompanyRegisterPageCalled = true;
                        hasCompanyBackCalled = false;
                        break;
                        //Exit from company page for operation number 3
                    case 3:
                        cout << "Returning back from company page...";
                        hasCompanyLoginPageCalled = false;
                        hasUserRegisterPageCalled = false;
                        hasCompanyBackCalled = true;
                        break;
                }
            case 3:
                cout << "Exiting System..." << endl;
                return 0;
        }


        if (hasUserRegisterPageCalled) {

            cout << "We are delighted to have you among us! Please enter your personal informations:" << endl;

            getUserProfileInfo(userFirstName,userLastName,userGender,userBirthDay, userBirthMonth, userBirthYear,
                        userNationality,userIdentityNumber,userHasDoneMilitaryService,userWorkingStatus);

            int userId = User::nextId++;

            User newUser(
                    userId,
                    userFirstName,
                    userLastName,
                    userGender,
                    userBirthDay,
                    userBirthMonth,
                    userBirthYear,
                    userNationality,
                    userIdentityNumber,
                    userHasDoneMilitaryService,
                    userWorkingStatus
            );

            newUser.createUserName();
            newUser.createPassword();

            // Kullanıcıyı veritabanına ekle
            User::users.push_back(newUser);

            cout << "Your registration process has been successfully completed!" << endl;

            // Tüm kullanıcıları göster
            User::displayUsers();

                switch (UserMainMenu()) {
                    case 1:
                        // Profil Bilgilerimi Görüntüle
                        newUser.displayUserInformation();
                        cout << "1-Back to user main menu.\n2-Exit to welcome screen.";
                        int backOrExitFromDisplayProfileInformation;
                        cin >> backOrExitFromDisplayProfileInformation;
                        if (backOrExitFromDisplayProfileInformation == 1) {
                            cout << "Returning to user main menu..." << endl;
                            break;  // Buraya dönmesini sağlayan function.
                        } else if (backOrExitFromDisplayProfileInformation == 2) {
                            cout << "Exiting to welcome screen..." << endl;
                            return 0;  // Buraya en başa dönmesini sağlayan function.
                        }
                        break;
                    case 2:
                        // Profil Bilgilerimi Güncelle
                        cout << "yapılmadı" << endl;
                        break;
                    case 3:
                        // CV Alanlarım
                        cout << "UserCVAreas page is loading..." << endl;

                        newUser.createPassword();
                        newUser.displayUserPassword();
                        hasUserMyCVPageCalled = true;

                        break;
                    case 4:
                        // Exit to welcome screen
                        cout << "Exiting to welcome screen..." << endl;
                        return 0;  // Buraya en başa dönmesini sağlayan function.
                }
            }







// Bir önceki menüye back methodu oluşturup atmalıyız ve de welcome screene aynısını yapmalıyız!!!!!!!!!!!!!!!




        return 0;
    }
