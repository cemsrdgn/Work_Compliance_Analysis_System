//
// Created by cemsr on 20.12.2023.
//

#include <iostream>
#include <string>
using namespace std;


//Getting UserProfile Information's from User
void getUserProfileInfo(string& userFirstName,string& userLastName,string& userGender,
                 int& userBirthDay, int& userBirthMonth, int& userBirthYear,
                 string& nationality,string& identityNumber,
                 bool& userHasDoneMilitaryService,bool& userWorkingStatus){

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
