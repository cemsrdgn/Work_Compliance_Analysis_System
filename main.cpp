//
// Created by cemsr on 15.12.2023.
//
#include <iostream>
#include <string>
#include "User.h"
#include "User.cpp"
#include "../Formats/Date.cpp"
#include "../Methods/MenuMethods//SelectOptionNumber.cpp"


//Getting User Informations From User
void getUserInfo(string& userFirstName,
                 string& userLastName,
                 string& userGender,
                 int& userBirthDay, int& userBirthMonth, int& userBirthYear,
                 string& nationality,
                 string& identityNumber,
                 bool& userHasDoneMilitaryService,
                 bool& userWorkingStatus){

    cout << "Enter your first name:";
    cin >> userFirstName;
    cout << "Enter your last name:";
    cin >> userLastName;
    cout << "Enter gender(Male/Female/Other):"; //Seçenek sunabiliriz. Male/Female/Other ya da sadece Male/Female
    cin >> userGender;
    cout << "Enter date of birth: \n"
         << "Your birth day:" ;
    cin >> userBirthDay;
    cout << "Your birth month:";
    cin >> userBirthMonth;
    cout << "Your birth year:";
    cin >> userBirthYear;
    cout << "Enter nationality:";
    cin >> nationality;
    cout << "Enter identity number:";
    cin >> identityNumber;
    cout << "Has military service? (1 for Yes, 0 for No):";
    cin >>  userHasDoneMilitaryService;
    cout << "Is currently working? (1 for Yes, 0 for No):";
    cin >>  userWorkingStatus;
}

using namespace std;

int main() {

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
    bool hasUserCVAreasPageCalled = false;


    switch (WelcomeScreen()) {

        //Load User Options for operation number 1
        case 1:
            switch (UserLoginAndRegisterMenu()) {
                //User login for operation number 1
                case 1:
                    cout<< "User login page is not accessible now. Please try again later!.." <<endl;
                    hasUserLoginPageCalled = true;
                    hasUserLoginPageCalled = false;
                    hasUserBackCalled = false;
                    break;
                    //User register for operation number 2
                case 2:
                    cout<< "User register page is loading..." << endl;
                    hasUserLoginPageCalled = false;
                    hasUserRegisterPageCalled = true;
                    hasUserBackCalled = false;
                    break;
                    //Exit from user page for operation number 3
                case 3:
                    cout<< "Returning back from user page...";
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
                    cout<< "Company login page is not accessible now. Please try again later!.." <<endl;
                    hasCompanyLoginPageCalled = true;
                    hasUserRegisterPageCalled = false;
                    hasCompanyBackCalled = false;
                    break;
                    //Company Register for operation number 2
                case 2:
                    cout<< "Company register page is not accessible now. Please try again later!.." << endl;

                    hasCompanyLoginPageCalled = false;
                    hasCompanyRegisterPageCalled = true;
                    hasCompanyBackCalled = false;
                    break;
                    //Exit from company page for operation number 3
                case 3:
                    cout<< "Returning back from company page...";
                    hasCompanyLoginPageCalled = false;
                    hasUserRegisterPageCalled = false;
                    hasCompanyBackCalled = true;
                    break;
            }
    }

    if(hasUserRegisterPageCalled) {

        cout << "We are delighted to have you among us! Please enter your personal informations:" << endl;
        getUserInfo(userFirstName,
                    userLastName,
                    userGender,
                    userBirthDay,userBirthMonth,userBirthYear,
                    userNationality,
                    userIdentityNumber,
                    userHasDoneMilitaryService,
                    userWorkingStatus);

        User userId01(
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

        //userId01.createId(); gibi bir şey
        userId01.createUserName();

        cout << "Your registration process has been successfully completed!" << endl;

        //user.displayId(); gibi bir şey           //Kullanıcıya username ve id sini gösteriyoruz
        userId01.displayUserName();

        switch (UserMainMenu()) {

            case 1:   //Profil Bilgilerimi Görüntüle
                userId01.displayUserInformation();
                cout << "1-Back to user main menu.\n2-Exit to welcome screen.";
                int backOrExitFromDisplayProfileInformation;
                cin >> backOrExitFromDisplayProfileInformation;
                if (backOrExitFromDisplayProfileInformation==1){
                    cout << "Returning to user main menu..." << endl;
                    //Buraya dönmesini sağlayan function.
                }
                else if (backOrExitFromDisplayProfileInformation==2){
                    cout << "Exiting to welcome screen..." << endl;
                    //Buraya en başa dönmesini sağlayan function.
                }
                break;
            case 2:   //Profil Bilgilerimi Güncelle
                cout << "yapılmadıığ" << endl;
                break;
            case 3:    //CV Alanlarım
                cout << "UserCVAreas page is loading..." << endl;
                hasUserCVAreasPageCalled= true;

                break;
            case 4:    //Exit to welcome screen
                cout << "Exiting to welcome screen..." << endl;
                //Buraya en başa dönmesini sağlayan function.
                break;
        }
    }

    if (hasUserCVAreasPageCalled){

        switch (UserCVAreas()) {

            case 1:
                cout << "1" << endl;
                break;
            case 2:
                cout << "2" << endl;
                break;
            case 3:
                cout << "3" << endl;
                break;
            case 4:
                cout << "4" << endl;
                break;
            case 5:
                cout << "5" << endl;
                break;
            case 6:
                cout << "6" << endl;
                break;
            case 7:
                cout << "7" << endl;
                break;
            case 8:
                cout << "8" << endl;
                break;
            case 9:
                cout << "9" << endl;
                break;
            case 10:
                cout << "10" << endl;
                break;
            case 11:
                cout << "11" << endl;
                break;
            case 12:
                cout << "12" << endl;
                break;
            case 13: //Back to user main menu
                    cout << "Returning to user main menu..." << endl;
                    //Buraya dönmesini sağlayan function.
                break;
            case 14: //Exit to welcome screen
                cout << "Exiting to welcome screen..." << endl;
                //Buraya en başa dönmesini sağlayan function.
                break;

        }

    }



// Bir önceki menüye back methodu oluşturup atmalıyız ve de welcome screene aynısını yapmalıyız!!!!!!!!!!!!!!!




    return 0;
}