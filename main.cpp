//
// Created by cemsr on 15.12.2023.
//
#include <iostream>
#include <string>
#include <limits>
#include "User.h"
#include "User.cpp"

//Options and MenuLoop For Starting App
int MenuForLoginAndRegister() {

    int numberOfOperation;

    cout << "Welcome, Work Compliance Analysis System! \n"
         << "Please enter the number of the operation you would like to perform: " << endl;

    while (true) {

        cout << "1-Login \n"
             << "2-Register \n"
             << "3-Exit \n"
             << ">";

        cin >> numberOfOperation;

        //------------------------------------------------------------------------------------------
        //It is for non number inputs. Like chars or symbols. (From ChatGPT)
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number." << std::endl;}
        //------------------------------------------------------------------------------------------

        else if (numberOfOperation == 1 || numberOfOperation == 2 || numberOfOperation == 3) {
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }

    return numberOfOperation;
}

//Getting User Informations From User
void getUserInfo(string& firstName, string& lastName,string& gender,string& dateOfBirth,
                 string& nationality,string& identityNumber,bool& militaryService,bool& workingStatus){

    cout << "Enter your first name:";
    cin >> firstName;
    cout << "Enter your last name:";
    cin >> lastName;
    cout << "Enter gender:"; //Seçenek sunabiliriz. Male/Female/Other ya da sadece Male/Female
    cin >> gender;
    cout << "Enter date of birth:"; //Date formatında kullanacağız.
    cin >> dateOfBirth;
    cout << "Enter nationality:";
    cin >> nationality;
    cout << "Enter identity number:";
    cin >> identityNumber;
    cout << "\n Has military service? (1 for Yes, 0 for No):";
    cin >>  militaryService;
    cout << "Is currently working? (1 for Yes, 0 for No):";
    cin >>  workingStatus;
}

using namespace std;

int main() {


    string firstName, lastName, gender, dateOfBirth, nationality, identityNumber;
    bool militaryService = false, workingStatus = false;

    //Continue actions for which operation has been selected
    bool hasLoginPageCalled = false;
    bool hasRegisterPageCalled = false;


    switch (MenuForLoginAndRegister()) {

        //Login for operation number 1
        case 1:
            cout<< "Login page is not accessible now. Please try again later!.." <<endl;
            hasLoginPageCalled = true;
            break;
        //Register for operation number 2
        case 2:
            cout<< "Register page is loading..." << endl;
            getUserInfo(firstName,lastName,gender,dateOfBirth,nationality,identityNumber,militaryService,workingStatus);
            hasRegisterPageCalled = true;
            break;
        //Exit for operation number 3
        case 3:
            cout<< "Exiting...";
            hasLoginPageCalled = false;
            hasRegisterPageCalled = false;
            break;
    }

    if(hasRegisterPageCalled) {

        User CemSaridogan(
                firstName,
                lastName,
                gender,
                dateOfBirth,
                nationality,
                identityNumber,
                militaryService,
                workingStatus
        );

        CemSaridogan.displayUserInformation();
        CemSaridogan.createUserName();
        CemSaridogan.displayUserName();
    }





    return 0;
}