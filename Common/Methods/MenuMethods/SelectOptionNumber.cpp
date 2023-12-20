//
// Created by cemsr on 18.12.2023.
//

#include <iostream>
#include <limits>
using namespace std;

//It is control for non number inputs. Like chars or symbols. (From ChatGPT)
int getUserInputWithControl() {
    int input;
    while (true) {
        cout << "> ";
        cin >> input;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            break;
        }
    }
    return input;
}

//Welcome screen to distinguish between company and user login
int WelcomeScreen(){
    int numberOfOperation;
    cout << "Welcome to Work Compliance Analysis System!\n"
         << "Please enter the number of the operation you would like to perform: " << endl;

    while (true) {

        cout << "1-Candidate (Are you looking for a job?) \n"
             << "2-Company (Will you post an Advertisement?) \n"
             << "3-Exit \n"
             << ">";

        numberOfOperation = getUserInputWithControl();

        if (numberOfOperation == 1 || numberOfOperation == 2 || numberOfOperation == 3) {
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }
    return numberOfOperation;
};
//----------------------------------------------------------------------------------------------------------------------
//Options and MenuLoop After Select User Option
int UserLoginAndRegisterMenu() {

    int numberOfOperation;

    cout << "----------------------Work Compliance Analysis System----------------------\n"
         << "Please enter the number of the operation you would like to perform: " << endl;

    while (true) {

        cout << "1-Login as User \n"
             << "2-Register as User \n"
             << "3-Exit to welcome screen\n"
             << ">";

        numberOfOperation = getUserInputWithControl();

        if (numberOfOperation == 1 || numberOfOperation == 2 || numberOfOperation == 3) {
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }
    return numberOfOperation;
}

//----------------------------------------------------------------------------------------------------------------------
//Options and MenuLoop After Select Company Option
int CompanyLoginAndRegisterMenu() {

    int numberOfOperation;

    cout << "---Work Compliance Analysis System---\n"
         << "Dear Employer, please select the operation you would like to perform:" << endl;

    while (true) {

        cout << "1-Login as Company \n"
             << "2-Register as Company\n"
             << "3-Exit \n"
             << ">";

        numberOfOperation = getUserInputWithControl();

        if (numberOfOperation == 1 || numberOfOperation == 2 || numberOfOperation == 3) {
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }
    return numberOfOperation;
}

//----------------------------------------------------------------------------------------------------------------------
//User Main Menu
int UserMainMenu() {

    int numberOfOperation;

    while (true) {

        cout << "1-Adverts that might suit you \n"
             << "2-Display all adverts\n"
             << "3-My Profile \n"
             << "4-My CV\n"
             << "5-My Rank and Applied Ads\n"
             << "6-Exit to welcome screen \n"
             << ">";

        numberOfOperation = getUserInputWithControl();

        if (numberOfOperation >= 1 && numberOfOperation <= 6){
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }
    return numberOfOperation;
}

//----------------------------------------------------------------------------------------------------------------------
//User's other classes(informations) which wants to add
int UserMyCV(){

    int numberOfOperation;

    while (true) {

        cout << "1-Add Communication Information\n"
             << "2-Add Education Information\n"
             << "3-Add Language Skills\n"
             << "4-Add Work Experiences\n"
             << "5-Add Projects\n"
             << "6-Add Exams Information\n"
             << "7-Add Expertise Areas\n"
             << "8-Add Reference\n"
             << "9-Add Certificate\n"
             << "10-Add Working Conditions\n"
             << "11-Add Social Skills\n"
             << "12-Add Hobbies\n"
             << "13-Back to User Main Menu\n"
             << "13-Exit to Welcome Screen \n"
             << ">";

        numberOfOperation = getUserInputWithControl();

        if (numberOfOperation >= 1 && numberOfOperation <= 14){
            break;
        } else {
            cout << "You entered a invalid number. Please try again!" << endl;
        }
    }
    return numberOfOperation;
}