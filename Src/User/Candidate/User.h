//
// Created by cemsr on 16.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H

#include <string>
#include <vector>

#include "../../../Common/Formats/Date Format/Date.h"

using namespace std;

class User {

private:

    string userName; //Biz kendimiz oluşturuyoruz.
    string Password; //Kayıt işleminin sonunda kullanıcı şifresini oluşturuyor.

    string FirstName;
    string LastName;
    string Gender;
    Date DateOfBirth; //Date formatı association yapıldı(formats/date).
    string Nationality;
    string IdentityNumber;
    bool MilitaryService;
    bool WorkingStatus;

protected:
    int ID; //Database de oluşan her yeni kullanıcı için 1 artıyor

public:

    //Bizim kendi databasemiz. Tüm userları tutuyoruz.
    static vector<User> users;

    //Default Constructor
    User();

    //One Parameter Constructor
    User(int id);

    //Parameterized Constructor
    User(
            int ID,
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

    //Setter for Password
    void setPassword(const string &password);


    //Display User Information
    void displayUserInformation() const;

    //Create a Username With FirstName and LastName
    void createUserName();

    //Confirm password with writing two times
    void createPassword();

    //Display User Password
    void displayUserPassword();

    //Display Username
    void displayUserName();

    //Display all Users in vector
    static void displayUsers();


    static int nextId;
    int getID();
    virtual void display();

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
