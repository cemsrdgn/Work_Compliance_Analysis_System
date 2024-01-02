//
// Created by cemsr on 16.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H

#include <string>
#include <vector>

#include "../../../Formats/Date Format/Date.h"
#include "../../../Methods/MenuMethods/MenuMethods.h"
#include "../../Company/Company.h"

using namespace std;

class User {

private:

    string UserName; //Biz kendimiz oluşturuyoruz.
    string Password; //Kayıt işleminin sonunda kullanıcı şifresini oluşturuyor.

    string FirstName;
    string LastName;
    string Gender;
    Date DateOfBirth; //Date formatı association yapıldı(formats/date).
    string Nationality;
    string IdentityNumber;

    bool DisabilitySituation; //Engel durumu (şimdilik bool kalsın sonra stringe döndürebiliriz)
    bool RelativeOfMartyr; //Gazi-sehit yakını (şimdilik bool kalsın sonra stringe döndürebiliriz)
    bool MilitaryService;
    bool WorkingStatus;

protected:
    int ID; //Database de oluşan her yeni kullanıcı için 1 artıyor

public:

    MenuMethods menuMethods; //Menu Method içinde bulunan fonksiyonu kullanmak istiyoruz

    //Bizim kendi databasemiz. Tüm userları tutuyoruz
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
            bool disabilitySituation,
            bool relativeOfMartyr,
            bool militaryService,
            bool workingStatus
    );

    static int nextId;

    //Destructor
    ~User();

    //Display Candidate Information
    void displayCandidateInformation() const;

    //Display all Users in vector
    static void displayAllCandidates();

    //Create a Username for Candidate With FirstName and LastName
    void createCandidateUserName();

    //Create a Password
    void createCandidatePassword();

    //Display User Password
    void displayCandidatePassword();

    //Display Username
    void displayCandidateUserName();

    //Updates Candidate Profile Infos by Inputs on Console
    void updateCandidateProfileInformation();

    //Setters of Candidate Class Attributes
    void setUserName(const string &userName);
    void setPassword(const string &password);
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setGender(const string &gender);
    void setNationality(const string &nationality);
    void setIdentityNumber(const string &identityNumber);
    void setDisabilitySituation(bool disabilitySituation);
    void setRelativeOfMartyr(bool relativeOfMartyr);
    void setMilitaryService(bool militaryService);
    void setWorkingStatus(bool workingStatus);

    const string &getUserName() const;

    const string &getPassword() const;

    const string &getFirstName() const;

    const string &getLastName() const;
    int getID();
    virtual void display();

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_USER_H
