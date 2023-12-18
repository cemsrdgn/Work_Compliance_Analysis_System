//
// Created by cemsr on 16.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H

#include <string>
#include <vector>
#include "../Formats/Date.h"

using namespace std;

class User {

private:

    //int id; //Database de oluşan her yeni kullanıcı için 1 artıcak
    string userName; //Biz kendimiz oluşturacağız (name.surname)

    string FirstName;
    string LastName;
    string Gender;
    Date DateOfBirth; //Date formatı association yapıldı(formats/date).
    string Nationality;
    string IdentityNumber; //Kontrol eklenicek tr için
    bool MilitaryService{};
    bool WorkingStatus{};



public:

    //Default Constructor
    User();

    //Parameterized Constructor
    User(
            string firstName,
            string lastName,
            string gender,
            int birthDay,
            int birthMonth,
            int birthYear,
            string nationality,
            string identityNumber,
            bool militaryService,
            bool workingStatus
            );

    //Destructor
    ~User();

    //Display User Information
    void displayUserInformation();

    //Create a Username With FirstName and LastName
    void createUserName();

    //Display Username
    void displayUserName();


    /*
    //Hold User's id
    void idHolder(int id);
     */


};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
