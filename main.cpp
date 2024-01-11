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
#include "Candidate CV/Foreign Languages/ForeignLanguage.h"
#include "Candidate CV/Certificates/Certificates.h"
#include "Candidate CV/Projects/Projects.h"
#include "Candidate CV/Education Information/EducationInformation.h"
#include "Candidate CV/Work Experiences/WorkExperience.h"
#include "Candidate CV/Exams Information/ExamInformation.h"
#include "Candidate CV/Social Skills/SocialSkills.h"
#include "Candidate CV/Communication Information/CommunicationInformation.h"
#include "Candidate CV/Refarance/Refarance.h"
#include "Candidate CV/Work Conditions/WorkConditions.h"


#include <iostream>
#include <string>
float AlgoPoint=0;
using namespace std;

int main() {

    ///Creating Classes Instances

    ///BaseClass
    User newUser;
    //User(Candidate) profile infoları için tanımlamalar
    string userFirstName, userLastName, userGender, userNationality, userIdentityNumber;
    bool userDisabilitySituation = false, userRelativeOfMarty = false;
    bool userHasDoneMilitaryService = false, userWorkingStatus = false;
    int userBirthDay, userBirthMonth, userBirthYear;

    ///Subclasses
    //Work Experience
    string name,description,startDate,endDate;
    Experience experience;
    User* user2 = new WorkExperience();
    WorkExperience* WorkExper = dynamic_cast<WorkExperience*>(user2);

    //Education Information
    float schoolRank;
    bool Erasmus;
    University myUni;
    string school1;
    User* user = new EducationInformation();
    EducationInformation* myEducation = dynamic_cast<EducationInformation*>(user);

    //Foreign Language
    Language language;
    User* user1 = new ForeignLanguage();
    ForeignLanguage* myLanguage = dynamic_cast<ForeignLanguage*>(user1);

    //Exam Information
    float examranks,exampoints;
    User* user3 = new ExamInformation();
    ExamInformation* myExam = dynamic_cast<ExamInformation*>(user3);

    //Social Skills
    int volcount = 0, clubcount = 0;
    string socialfactor, volunteerwork;
    SocialFactors social(user->getID(),socialfactor,volunteerwork);

    //Project
    Project proje(name,description,startDate,endDate);
    int projecount=0;

    //References
    Reference reference;

    //Certificates
    int certifcount=0;
    string certif;
    Certificates Cer;

    //Communication Information
    string email, phone, address;
    CommunicationInformation commInfo;

    //Hobies
    string hobies;
    Hobie Hobies;

    //Work Conditions
    int salaryException;
    string desiredPosition,desiredCityToWork;
    bool travelCapability;
    WorkConditions workConditions;


    ///Company Class
    Company newCompany;
    //Company profile infoları için tanımlamalar
    string CompanyName, CompanyPhoneNumber, CompanyEmail, CompanyCity, CompanyTaxNumber, CompanyTaxOfficeCity;


    ///Advertisement Class
    Adversitement newAdversitement;
    //Advertisement özellikleri için tanımlamalar:
    int AdvertisementId, NumberOfQuotas, Salary;
    float Point;
    string AdTitle, CompanyDescription, City, ApplicationDeadLine;
    string AdSector, AdPosition, AdWorkPreference, AdWorkType, AdExperience, ADPositionLevel, AdEducationLevel,AdLanguage,
    AdMilitaryService;

    float myRank=0;

    int choice;
    int id;
    int ch;
    int year;

    //For loop controls
    bool validChoice=false;
    bool exitMenu;

    string namee;
    string position;
    string phoneNumber;

    MenuMethods menuMethods;

    //Datas for Database-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    User AliOzn(User::nextId++, "Ali", "Ozen", "Male", 21, 06, 2000, "Turkish", "21219841060", true, false,false, true);
    AliOzn.createCandidateUserName(); //Login için AliOzn kullanıcısı username: Ali.Ozen
    AliOzn.setPassword("123456"); //Login için AliOzn kullanıcısı password: 123456
    User::users.push_back(AliOzn);

    User MltmKlbk(User::nextId++, "Meltem", "Kelebek", "Female", 17, 05, 1989, "Canadian", "31269966233", false, true,false, true);
    MltmKlbk.createCandidateUserName(); //Login için MltmKlbk kullanıcısı username: Meltem.Kelebek
    MltmKlbk.setPassword("987654"); //Login için MltmKlbk kullanıcısı password: 987654
    User::users.push_back(MltmKlbk);

    Company RecordCompany(Company::nextCompanyId++, "RecordSoftware", "3123226895", "rcrdsftwr@gmail.com", "Berlin","6547983423", "Frankfurt");
    RecordCompany.createCompanyUserName();   //Login için RecordCompany şirketi username: RecordSoftware.company
    RecordCompany.setCompanyPassword("987654"); //Login için RecordCompany şirketi şifre: 987654
    Company::companies.push_back(RecordCompany);

    Company CoreCompany(Company::nextCompanyId++, "CoreBank", "2123654482", "core@gmail.com", "Istanbul","984565123485", "Ankara");
    CoreCompany.createCompanyUserName();   //Login için CoreBank şirketi username: CoreBank.company
    CoreCompany.setCompanyPassword("123456"); //Login için CoreBank şirketi şifre: 123456
    Company::companies.push_back(CoreCompany);

    Adversitement advert1("Ad Title 1", "Company Description 1", 50000,  "Berlin", "2023-01-15",Adversitement::nextAdId++, RecordCompany.getCompanyId(),40, "Technology and Software","Software specialist", "Remote/Remote","Permanent / Full time", "0-2 years", "Beginner", "University graduate", "English","Done, Exempt");
    Adversitement::adversitement.push_back(advert1);

    Adversitement advert2("Ad Title 2", "Company Description 2", 60000, "Istanbul", "2023-01-20",Adversitement::nextAdId++, CoreCompany.getCompanyId(), 10, "Finance and Banking","Accounting staff", "At the workplace","Periodic / Project based", "2-5 years", "Middle manager", "Master - Graduate", "German","Not Done (Postponed)");
    Adversitement::adversitement.push_back(advert2);
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //Back option for user's and company's login and register menu
    bool hasWelcomeScreenBackCalled = true;

    //Company ve Candidate login sırasında kullanılıyor.
    string nameCheckUser, passwordCheckUser, nameCheckCompany, passwordCheckCompany;

    //User's  main menu  and bak option
    bool hasCandidateMainMenuCalled = false;
    bool hasCandidateMainMenuBackCalled = true;

    //Company's  main menu  and bak option

    bool hasCompanyMainMenuCalled = false;
    bool hasCompanyMainMenuBackCalled = true;

    int candidateMyProfileChoice, welcomeChoice, candidateMainMenuChoice, companyMainMenuChoice;

    int userId; int back;

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

                                    cout << "Your Algorithm Point:" << AlgoPoint << endl;

                                    for (auto &ads: Adversitement::adversitement) {

                                        if ( AlgoPoint >= ads.getAdPoint() && AlgoPoint-20 <= ads.getAdPoint()){

                                            ads.display();
                                        }
                                    }

                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }

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
                                            cin.ignore();
                                            cout << "Add email:" << endl;
                                            getline(cin, email);
                                            cout << "Add phone:" << endl;
                                            getline(cin, phone);
                                            cout << "Add Address:" << endl;
                                            getline(cin, address);

                                            commInfo= CommunicationInformation(email,phoneNumber,address);

                                            cout << "Adding Successful..." << endl;
                                            commInfo.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 2: // Add Education Information
                                            cout << "Add education information to your cv:" << endl;
                                            //user= new EducationInformation();
                                            //myEducation = dynamic_cast<EducationInformation&>(*user);
                                            cin.ignore();
                                            cout << "Enter Graduated High School:";
                                            getline(cin,school1);
                                            cin.ignore();
                                            cout << "Enter Graduated point High School";
                                            cin >> schoolRank;
                                            cin.ignore();
                                            cout << "Enter University Name: ";
                                            getline(cin,myUni.UniversityName);
                                            cout << "Enter University's Faculty: ";
                                            getline(cin,myUni.Faculty);
                                            cout << "Enter University's Department: ";
                                            getline(cin,myUni.Department);
                                            cout << "Enter University's Education Language: ";
                                            getline(cin,myUni.EducationLanguage);
                                            cout << "Enter University's Education Type: ";
                                            getline(cin,myUni.EducationType);
                                            cout << "If you done double Major enter please: ";
                                            getline(cin,myUni.DoubleMajor);
                                            cout << "If you done Minor enter please ";
                                            getline(cin,myUni.Minors);
                                            cin.ignore();
                                            cout << "Enter University's GPA ";
                                            cin >> myUni.GPA;
                                            cin.ignore();
                                            cout << "Is do Complete Erasmus? 1-(Yes) 2-(No)";
                                            cin >> Erasmus;
                                            //myEducation->addEducationInformation(user->getID(),school1,myUni);
                                            myEducation->addEducationInformation(user->getID(),school1,schoolRank,myUni,Erasmus);
                                            user->display();

                                            if(schoolRank>=90){AlgoPoint+=2.5;}
                                            else{AlgoPoint+=0.5;}
                                            if(myUni.GPA>=2 && myUni.GPA<3){AlgoPoint+=1.5;}
                                            if(myUni.GPA>=3 && myUni.GPA<3.5){AlgoPoint+=3.5;}
                                            if(myUni.GPA>=3.5 && myUni.GPA<4){AlgoPoint+=7.5;}
                                            if(Erasmus==true){AlgoPoint+=12.5;}
                                            cout << "Algo point " << AlgoPoint << endl;

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 3: // Add Language Skills
                                            cout << "Add language skill to your cv:" << endl;
                                            //user= new ForeignLanguage(user->getID(),language);
                                            //myLanguage = dynamic_cast<ForeignLanguage&>(*user);
                                            cin.ignore();
                                            cout << "Education Language:";
                                            getline(cin,language.LanguageName);
                                            cout << "Enter " << language.LanguageName << " Writing Level: ";
                                            getline(cin,language.Writing);
                                            cout << "Enter " << language.LanguageName << " Reading Level: ";
                                            getline(cin,language.Reading);
                                            cout << "Enter " << language.LanguageName << " Listening Level: ";
                                            getline(cin,language.Listening);
                                            cout << "Enter " << language.LanguageName << " Speaking Level: ";
                                            cin >> language.Speaking;

                                            myLanguage->setLanguage(user->getID(),language);
                                            if(language.Speaking == "A1"){myRank=myRank+0.2;}
                                            if(language.Speaking == "A2"){myRank=myRank+0.4;}
                                            if(language.Speaking == "B1"){myRank=myRank+0.6;}
                                            if(language.Speaking == "B2"){myRank=myRank+0.8;}
                                            if(language.Speaking == "C1"){myRank=myRank+1;}
                                            if(language.Listening == "A1"){myRank=myRank+0.2;}
                                            if(language.Listening == "A2"){myRank=myRank+0.4;}
                                            if(language.Listening == "B1"){myRank=myRank+0.6;}
                                            if(language.Listening == "B2"){myRank=myRank+0.8;}
                                            if(language.Listening == "C1"){myRank=myRank+1;}
                                            if(language.Reading == "A1"){myRank=myRank+0.2;}
                                            if(language.Reading == "A2"){myRank=myRank+0.4;}
                                            if(language.Reading == "B1"){myRank=myRank+0.6;}
                                            if(language.Reading == "B2"){myRank=myRank+0.8;}
                                            if(language.Reading == "C1"){myRank=myRank+1;}
                                            if(language.Writing == "A1"){myRank=myRank+0.2;}
                                            if(language.Writing == "A2"){myRank=myRank+0.4;}
                                            if(language.Writing == "B1"){myRank=myRank+0.6;}
                                            if(language.Writing == "B2"){myRank=myRank+0.8;}
                                            if(language.Writing == "C1"){myRank=myRank+1;}
                                            cout <<  "rank:" << myRank << endl;
                                            user1->display();

                                            if(myRank>=0 && myRank<=0.8){AlgoPoint+=1;}
                                            if(myRank>=0.8 && myRank<=1.6){AlgoPoint+=2.5;}
                                            if(myRank>=1.6 && myRank<=2.4){AlgoPoint+=5;}
                                            if(myRank>=2.4 && myRank<=3.2){AlgoPoint+=10;}
                                            if(myRank>=3.2 && myRank<=4){AlgoPoint+=22.5;}
                                            cout << "Algo Point:" << AlgoPoint << endl;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 4: // Add Work Experiences
                                            cout << "Add work experience to your cv:" << endl;
                                           // user=new WorkExperience;
                                            //WorkExper= dynamic_cast<WorkExperience&>(*user);
                                            cin.ignore();

                                            cout << "Enter Company Name:";
                                            getline(cin,experience.CompanyName);
                                            cout << "Enter Work Position: ";
                                            getline(cin,experience.Position);
                                            cout << "Enter Work Type: ";
                                            getline(cin,experience.WorkType);
                                            cout << "Enter Which City Did You Work In?: ";
                                            getline(cin,experience.City);
                                            cout << "Enter What Field Do You Work In The Company? ";
                                            getline(cin,experience.CompanyWorkingArea);
                                            cin.ignore();
                                            cout << "Enter The year you started working";
                                            cin >> experience.StartDate;
                                            cout << "Enter The year you left workplace";
                                            cin >> experience.FinishDate;
                                            WorkExper->addExperience(user->getID(),experience);

                                            user2->display();
                                            year=WorkExper->CalculateWorkTime(experience.StartDate,experience.FinishDate);
                                            cout << year;

                                            if(year>1 && year <=5){AlgoPoint+=5;}
                                            if(year>5 && year<10){AlgoPoint+=11;}
                                            if(year>=10){AlgoPoint+=18;}

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 5: // Add Projects
                                            cout << "Add project to your cv:" << endl;
                                            cin.ignore();
                                            while (!validChoice) {
                                                cout << "Welcome Project Insertion" << endl;
                                                cout << "1-Add Project" << endl;
                                                cout << "2-Exit..." << endl;
                                                cin >> ch;
                                                cin.ignore();
                                                switch (ch) {
                                                    case 1:
                                                        cout << "Project name:" << endl;
                                                        getline(cin,name);
                                                        cout << "Project Description:" << endl;
                                                        getline(cin,description);
                                                        cout << "Project Start Date:" << endl;
                                                        getline(cin,startDate);
                                                        cout << "Project End Date:" << endl;
                                                        getline(cin,endDate);
                                                        proje.addProject(name,description,startDate,endDate);
                                                        cout << "Adding Successful..." << endl;

                                                        if(projecount<11){AlgoPoint+=2;}
                                                        break;
                                                    case 2:
                                                        cout << "Exit Successful..." << endl;
                                                        validChoice=true;
                                                        break;
                                                    default:
                                                        cout << "Invalid choice..." << endl;
                                                        break;
                                                }
                                            }
                                            proje.displayAllProjects();
                                            cout << "Algo" << AlgoPoint;

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 6: // Add Exams Information
                                            cout << "Add exams information to your cv:" << endl;
                                            //user= new ExamInformation(user->getID(),examranks,exampoints);
                                            //myExam = dynamic_cast<ExamInformation&>(*user);
                                            cin.ignore();
                                            exitMenu=false;
                                            while (!exitMenu) {
                                                cout << "WELCOME TO EXAM INFORMATION SYSTEM" << endl;
                                                cout << "1-Add OSYM exams" << endl;
                                                cout << "2-Add other exams" << endl;
                                                cout << "3-Exit..." << endl;
                                                cin >> choice;

                                                switch (choice) {
                                                    case 1:
                                                        cout << "SELECT EXAM" << endl;
                                                        cout << "1-YKS" << endl;
                                                        cout << "2-KPSS" << endl;
                                                        cout << "3-ALES" << endl;
                                                        cout << "4-TUS" << endl;
                                                        cout << "5-YDS" << endl;
                                                        cout << "6-YOK DIL" << endl;
                                                        cout << "7-Exit..." << endl;
                                                        cout << "Please choice one" << endl;
                                                        cin >> ch;
                                                        cin.ignore();

                                                        if (ch == 1) {
                                                            cout << "Enter your YKS grade:" << endl;
                                                            cin >> exampoints;
                                                            cout << "Enter your YKS rank:" << endl;
                                                            cin >> examranks;

                                                            myExam->addExamRating(id,examranks, exampoints);
                                                            if(exampoints>=180 && exampoints<=250){AlgoPoint+=0.25;}
                                                            if(exampoints>=250 && exampoints<=350){AlgoPoint+=0.75;}
                                                            if(exampoints>=350 && exampoints<=400){AlgoPoint+=2;}
                                                            if(exampoints>400){AlgoPoint+=5;}
                                                            myExam->displayYksGraduate();
                                                        }
                                                        else if (ch == 2) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "KPSS   ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 3) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "ALES   ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 4) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "TUS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 5) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "YDS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 6) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "YÖK DİL    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 7) {
                                                            exitMenu = true;
                                                        }
                                                        else {
                                                            cout << "Wrong choice, please try again." << endl;
                                                        }

                                                        break;

                                                    case 2:

                                                        cout << "SELECT EXAM" << endl;
                                                        cout << "1-IELTS" << endl;
                                                        cout << "2-TOEFL" << endl;
                                                        cout << "3- Exit..." << endl;
                                                        cin.ignore();
                                                        cin >> ch;
                                                        if (ch == 1) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "IELTS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 2) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "TOEFL    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 3) {
                                                            exitMenu = true;
                                                        }
                                                        else {
                                                            cout << "Wrong choice, please try again." << endl;
                                                        }

                                                        break;
                                                    case 3:
                                                        exitMenu= true;
                                                        break;

                                                    default:
                                                        cout << "Wrong Choice please click 1 or 2" << endl;

                                                }

                                            }
                                            cout << "Algo:" << AlgoPoint;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 7: // Add Expertise Areas
                                            cout << "Add expertise area to your cv:" << endl;
                                            break;
                                        case 8: // Add Reference
                                            cout << "Add reference to your cv:" << endl;
                                            cin.ignore();
                                            cout << "Add name:" << endl;
                                            getline(cin, namee);
                                            cout << "Add position:" << endl;
                                            getline(cin, position);
                                            cout << "Add Phone Number:" << endl;
                                            getline(cin, phoneNumber);

                                            commInfo.addReference(newUser.getID(), namee, position, phoneNumber);  // Metod adı 'addCommuni' yerine 'addReference' olarak değiştirildi

                                            cout << "Adding Successful..." << endl;
                                            commInfo.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 9: // Add Certificate
                                            cout << "Add certificate to your cv:" << endl;
                                            cin.ignore();
                                            //Certificates* user = new Certificates();
                                            //user=new Certificates;
                                            //Certificates cer;
                                            //Certificates cer(user->getID(),certif);
                                            //Cer = dynamic_cast<Certificates&>(*user);
                                            validChoice=false;

                                            while (!validChoice) {
                                                cout << "Welcome Certifica Insertion" << endl;
                                                cout << "1-Add Certifica" << endl;
                                                cout << "2-Exit..." << endl;
                                                cin >> ch;
                                                cin.ignore();
                                                switch (ch) {
                                                    case 1:
                                                        cout << "Certifica name:" << endl;
                                                        getline(cin,certif);
                                                        Cer.addCertificates(user->getID(),certif);
                                                        cout << "Adding Succesfull..." << endl;
                                                        if(certifcount<10){
                                                            AlgoPoint+=0.5;
                                                        }
                                                        break;
                                                    case 2:
                                                        cout << "Exit Succesfull..." << endl;
                                                        validChoice=true;
                                                        break;
                                                    default:
                                                        cout << "Invalid choice..." << endl;
                                                        break;
                                                }
                                            }
                                            Cer.display();
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                            break;
                                        case 10: // Add Working Conditions
                                            cout << "Add working condition to your cv:" << endl;

                                            cout << "Your salary exception:";
                                            cin >> salaryException;
                                            cout << "Your desire work position:";
                                            cin >> desiredPosition;
                                            cout << "Your desire city to work in:";
                                            cin >> desiredCityToWork;
                                            cout << "Can u travel everywhere for work? (1 for yes,0 for no):";
                                            cin >> travelCapability;

                                            workConditions.add(newUser.getID(),salaryException,desiredPosition,desiredCityToWork,travelCapability);
                                            workConditions.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                        case 11: // Add Social Skills
                                            cout << "Add social skill to your cv:" << endl;
                                            cin.ignore();
                                            validChoice = false;
                                            while (!validChoice) {
                                                cout << "Welcome Socials:" << endl;
                                                cout << "1-Please Enter Social Clubs if you do" << endl;
                                                cout << "2-Please Enter VolunteerWorks if you do" << endl;
                                                cout << "3-there was no social participation" << endl;
                                                cin >> ch;

                                                switch (ch) {
                                                    case 1:
                                                        cout << "Enter Club :" << endl;
                                                        cin >> socialfactor;
                                                        if(clubcount<5){
                                                            AlgoPoint+=1;
                                                        }
                                                        clubcount++;
                                                        cout << "Adding Succesfull..." << endl;

                                                        break;
                                                    case 2:
                                                        cout << "Enter Volunteer:" << endl;
                                                        cin >> volunteerwork;

                                                        if(volcount<2){
                                                            AlgoPoint+=5;
                                                        }
                                                        volcount++;
                                                        cout << "Adding Succesfull...." << endl;

                                                        break;
                                                    default:
                                                        cout << "Exit Succesfull..." << endl;
                                                        validChoice=true;
                                                        break;
                                                }
                                                social.add(user->getID(),socialfactor,volunteerwork);
                                            }
                                            social.display();
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 12: // Add Hobbies
                                            cout << "Add Hobbies to your cv:" << endl;
                                            cin.ignore();
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
                                    cout << "My Rank:" << AlgoPoint << endl;
                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }
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

                        AlgoPoint=0;

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

                                    cout << "Your Algorithm Point:" << AlgoPoint << endl;

                                    for (auto &ads: Adversitement::adversitement) {

                                        if ( AlgoPoint >= ads.getAdPoint() && AlgoPoint-20 <= ads.getAdPoint()){

                                            ads.display();
                                        }
                                    }

                                    cout << "1-Back to Candidate Main Menu\n>";
                                    back = menuMethods.getUserInputWithControl();
                                    if (back == 1) { continue; }

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
                                            cin.ignore();
                                            cout << "Add email:" << endl;
                                            getline(cin, email);
                                            cout << "Add phone:" << endl;
                                            getline(cin, phone);
                                            cout << "Add Address:" << endl;
                                            getline(cin, address);

                                            commInfo= CommunicationInformation(email,phoneNumber,address);

                                            cout << "Adding Successful..." << endl;
                                            commInfo.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 2: // Add Education Information
                                            cout << "Add education information to your cv:" << endl;
                                            //user= new EducationInformation();
                                            //myEducation = dynamic_cast<EducationInformation&>(*user);
                                            cin.ignore();

                                            cout << "Enter Graduated High School:";
                                            getline(cin,school1);
                                            cin.ignore();
                                            cout << "Enter Gradıated point High School";
                                            cin >> schoolRank;
                                            cin.ignore();
                                            cout << "Enter University Name: ";
                                            getline(cin,myUni.UniversityName);
                                            cout << "Enter University's Faculty: ";
                                            getline(cin,myUni.Faculty);
                                            cout << "Enter University's Department: ";
                                            getline(cin,myUni.Department);
                                            cout << "Enter University's Education Language: ";
                                            getline(cin,myUni.EducationLanguage);
                                            cout << "Enter University's Education Type: ";
                                            getline(cin,myUni.EducationType);
                                            cout << "If you done double Major enter please: ";
                                            getline(cin,myUni.DoubleMajor);
                                            cout << "If you done Minor enter please ";
                                            getline(cin,myUni.Minors);
                                            cin.ignore();
                                            cout << "Enter University's GPA ";
                                            cin >> myUni.GPA;
                                            cin.ignore();
                                            cout << "Is do Complete Erasmus? 1-(Yes) 2-(No)";
                                            cin >> Erasmus;

                                            //myEducation->addEducationInformation(user->getID(),school1,myUni);
                                            myEducation->addEducationInformation(user->getID(),school1,schoolRank,myUni,Erasmus);
                                            user->display();

                                            if(schoolRank>=90){
                                                AlgoPoint+=2.5;
                                            }
                                            else{
                                                AlgoPoint+=0.5;
                                            }
                                            if(myUni.GPA>=2 && myUni.GPA<3){
                                                AlgoPoint+=1.5;
                                            }
                                            if(myUni.GPA>=3 && myUni.GPA<3.5){
                                                AlgoPoint+=3.5;
                                            }
                                            if(myUni.GPA>=3.5 && myUni.GPA<4){
                                                AlgoPoint+=7.5;
                                            }
                                            if(Erasmus==true){
                                                AlgoPoint+=12.5;
                                            }

                                            cout << "Algo point " << AlgoPoint << endl;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }

                                            break;
                                        case 3: // Add Language Skills
                                            cout << "Add language skill to your cv:" << endl;
                                            //user= new ForeignLanguage(user->getID(),language);
                                            //myLanguage = dynamic_cast<ForeignLanguage&>(*user);
                                            cin.ignore();
                                            cout << "Education Language:";
                                            getline(cin,language.LanguageName);
                                            cout << "Enter " << language.LanguageName << " Writing Level: ";
                                            getline(cin,language.Writing);
                                            cout << "Enter " << language.LanguageName << " Reading Level: ";
                                            getline(cin,language.Reading);
                                            cout << "Enter " << language.LanguageName << " Listening Level: ";
                                            getline(cin,language.Listening);

                                            cout << "Enter " << language.LanguageName << " Speaking Level: ";
                                            getline(cin,language.Speaking);

                                            myLanguage->setLanguage(user->getID(),language);
                                            if(language.Speaking == "A1"){
                                                myRank=myRank+0.2;
                                            }
                                            if(language.Speaking == "A2"){
                                                myRank=myRank+0.4;
                                            }
                                            if(language.Speaking == "B1"){
                                                myRank=myRank+0.6;
                                            }
                                            if(language.Speaking == "B2"){
                                                myRank=myRank+0.8;
                                            }
                                            if(language.Speaking == "C1"){
                                                myRank=myRank+1;
                                            }
                                            if(language.Listening == "A1"){
                                                myRank=myRank+0.2;
                                            }
                                            if(language.Listening == "A2"){
                                                myRank=myRank+0.4;
                                            }
                                            if(language.Listening == "B1"){
                                                myRank=myRank+0.6;
                                            }
                                            if(language.Listening == "B2"){
                                                myRank=myRank+0.8;
                                            }
                                            if(language.Listening == "C1"){
                                                myRank=myRank+1;
                                            }
                                            if(language.Reading == "A1"){
                                                myRank=myRank+0.2;
                                            }
                                            if(language.Reading == "A2"){
                                                myRank=myRank+0.4;
                                            }
                                            if(language.Reading == "B1"){
                                                myRank=myRank+0.6;
                                            }
                                            if(language.Reading == "B2"){
                                                myRank=myRank+0.8;
                                            }
                                            if(language.Reading == "C1"){
                                                myRank=myRank+1;
                                            }
                                            if(language.Writing == "A1"){
                                                myRank=myRank+0.2;
                                            }
                                            if(language.Writing == "A2"){
                                                myRank=myRank+0.4;
                                            }
                                            if(language.Writing == "B1"){
                                                myRank=myRank+0.6;
                                            }
                                            if(language.Writing == "B2"){
                                                myRank=myRank+0.8;
                                            }
                                            if(language.Writing == "C1"){
                                                myRank=myRank+1;
                                            }
                                            cout <<  "rank:" << myRank << endl;
                                            user1->display();

                                            if(myRank>=0 && myRank<=0.8){
                                                AlgoPoint+=1;
                                            }
                                            if(myRank>=0.8 && myRank<=1.6){
                                                AlgoPoint+=2.5;
                                            }
                                            if(myRank>=1.6 && myRank<=2.4){
                                                AlgoPoint+=5;
                                            }
                                            if(myRank>=2.4 && myRank<=3.2){
                                                AlgoPoint+=10;
                                            }
                                            if(myRank>=3.2 && myRank<=4){
                                                AlgoPoint+=22.5;
                                            }
                                            cout << "Algo Point:" << AlgoPoint << endl;

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 4: // Add Work Experiences
                                            cout << "Add work experience to your cv:" << endl;
                                            //user=new WorkExperience;
                                            //WorkExper= dynamic_cast<WorkExperience&>(*user);

                                            cin.ignore();
                                            cout << "Enter Company Name:";
                                            getline(cin,experience.CompanyName);
                                            cout << "Enter Work Position: ";
                                            getline(cin,experience.Position);
                                            cout << "Enter Work Type: ";
                                            getline(cin,experience.WorkType);
                                            cout << "Enter Which City Did You Work In?: ";
                                            getline(cin,experience.City);
                                            cout << "Enter What Field Do You Work In The Company? ";
                                            getline(cin,experience.CompanyWorkingArea);
                                            cin.ignore();
                                            cout << "Enter The year you started working";
                                            cin >> experience.StartDate;
                                            cout << "Enter The year you left workplace";
                                            cin >> experience.FinishDate;
                                            WorkExper->addExperience(user->getID(),experience);

                                            user2->display();
                                            year=WorkExper->CalculateWorkTime(experience.StartDate,experience.FinishDate);
                                            cout << year;
                                            if(year>1 && year <=5){
                                                AlgoPoint+=5;
                                            }
                                            if(year>5 && year<10){
                                                AlgoPoint+=11;
                                            }
                                            if(year>=10){
                                                AlgoPoint+=18;
                                            }
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 5: // Add Projects
                                            cout << "Add project to your cv:" << endl;
                                            cin.ignore();
                                            while (!validChoice) {
                                                cout << "Welcome Project Insertion" << endl;
                                                cout << "1-Add Project" << endl;
                                                cout << "2-Exit..." << endl;
                                                cin >> ch;
                                                cin.ignore();
                                                switch (ch) {
                                                    case 1:
                                                        cout << "Project name:" << endl;
                                                        getline(cin,name);
                                                        cout << "Project Description:" << endl;
                                                        getline(cin,description);
                                                        cout << "Project Start Date:" << endl;
                                                        getline(cin,startDate);
                                                        cout << "Project End Date:" << endl;
                                                        getline(cin,endDate);
                                                        proje.addProject(name,description,startDate,endDate);
                                                        cout << "Adding Succesfull..." << endl;
                                                        if(projecount<11){
                                                            AlgoPoint+=2;
                                                        }
                                                        break;
                                                    case 2:
                                                        cout << "Exit Succesfull..." << endl;
                                                        validChoice=true;
                                                        break;
                                                    default:
                                                        cout << "Invalid choice..." << endl;
                                                        break;
                                                }
                                            }
                                            proje.displayAllProjects();

                                            cout << "Algo" << AlgoPoint << endl;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 6: // Add Exams Information
                                            cout << "Add exams information to your cv:" << endl;
                                            cin.ignore();
                                            //user= new ExamInformation(user->getID(),examranks,exampoints);
                                           // myExam = dynamic_cast<ExamInformation&>(*user);

                                            exitMenu=false;
                                            while (!exitMenu) {
                                                cout << "WELCOME TO EXAM INFORMATION SYSTEM" << endl;
                                                cout << "1-Add ÖSYM exams" << endl;
                                                cout << "2-Add other exams" << endl;
                                                cout << "3-Exit..." << endl;
                                                cin >> choice;

                                                switch (choice) {
                                                    case 1:
                                                        cout << "SELECT EXAM" << endl;
                                                        cout << "1-YKS" << endl;
                                                        cout << "2-KPSS" << endl;
                                                        cout << "3-ALES" << endl;
                                                        cout << "4-TUS" << endl;
                                                        cout << "5-YDS" << endl;
                                                        cout << "6-YÖK DİL" << endl;
                                                        cout << "7-Exit..." << endl;
                                                        cout << "Please choice one" << endl;
                                                        cin >> ch;
                                                        cin.ignore();

                                                        if (ch == 1) {
                                                            cout << "Enter your YKS grade:" << endl;
                                                            cin >> exampoints;
                                                            cout << "Enter your YKS rank:" << endl;
                                                            cin >> examranks;
                                                            myExam->addExamRating(id,examranks, exampoints);
                                                            if(exampoints>=180 && exampoints<=250){
                                                                AlgoPoint+=0.25;
                                                            }
                                                            if(exampoints>=250 && exampoints<=350){
                                                                AlgoPoint+=0.75;
                                                            }
                                                            if(exampoints>=350 && exampoints<=400){
                                                                AlgoPoint+=2;
                                                            }
                                                            if(exampoints>400){
                                                                AlgoPoint+=5;
                                                            }
                                                            myExam->displayYksGraduate();
                                                        }
                                                        else if (ch == 2) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "KPSS   ";
                                                            myExam->displayGraduate();
                                                        }

                                                        else if (ch == 3) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "ALES   ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 4) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "TUS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 5) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "YDS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 6) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "YÖK DİL    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 7) {
                                                            exitMenu = true;
                                                        }
                                                        else {
                                                            cout << "Wrong choice, please try again." << endl;
                                                        }

                                                        break;

                                                    case 2:

                                                        cout << "SELECT EXAM" << endl;
                                                        cout << "1-IELTS" << endl;
                                                        cout << "2-TOEFL" << endl;
                                                        cout << "3- Exit..." << endl;
                                                        cin.ignore();
                                                        cin >> ch;
                                                        if (ch == 1) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "IELTS    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 2) {
                                                            myExam->addExamRating(id,exampoints);
                                                            cout << "TOEFL    ";
                                                            myExam->displayGraduate();
                                                        }
                                                        else if (ch == 3) {
                                                            exitMenu = true;
                                                        }
                                                        else {
                                                            cout << "Wrong choice, please try again." << endl;
                                                        }

                                                        break;
                                                    case 3:
                                                        exitMenu= true;
                                                        break;

                                                    default:
                                                        cout << "Wrong Choice please click 1 or 2" << endl;

                                                }

                                            }
                                            cout << "Algo:" << AlgoPoint;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 7: // Add Expertise Areas
                                            cout << "Add expertise area to your cv:" << endl;
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;

                                        case 8: // Add Reference
                                            cout << "Add reference to your cv:" << endl;
                                            cin.ignore();
                                            cout << "Add name:" << endl;
                                            getline(cin, namee);
                                            cout << "Add position:" << endl;
                                            getline(cin, position);
                                            cout << "Add Phone Number:" << endl;
                                            getline(cin, phoneNumber);

                                            commInfo.addReference(newUser.getID(), namee, position, phoneNumber);  // Metod adı 'addCommuni' yerine 'addReference' olarak değiştirildi

                                            cout << "Adding Successful..." << endl;
                                            commInfo.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 9: // Add Certificate
                                            cout << "Add certificate to your cv:" << endl;
                                            cin.ignore();
                                            //Certificates* user = new Certificates();
                                            //user=new Certificates;
                                            //Certificates cer;
                                            //Certificates cer(user->getID(),certif);
                                            //Cer = dynamic_cast<Certificates&>(*user);
                                            validChoice=false;

                                            while (!validChoice) {
                                                cout << "Welcome Certifica Insertion" << endl;
                                                cout << "1-Add Certifica" << endl;
                                                cout << "2-Exit..." << endl;
                                                cin >> ch;
                                                cin.ignore();
                                                switch (ch) {
                                                    case 1:
                                                        cout << "Certifica name:" << endl;
                                                        getline(cin,certif);
                                                        Cer.addCertificates(user->getID(),certif);
                                                        cout << "Adding Succesfull..." << endl;
                                                        if(certifcount<10){
                                                            AlgoPoint+=0.5;
                                                        }
                                                        break;
                                                    case 2:
                                                        cout << "Exit Succesfull..." << endl;
                                                        validChoice=true;
                                                        break;
                                                    default:
                                                        cout << "Invalid choice..." << endl;
                                                        break;
                                                }
                                            }
                                            Cer.display();
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 10: // Add Working Conditions
                                            cout << "Add working condition to your cv:" << endl;

                                            cout << "Your salary exception:";
                                            cin >> salaryException;
                                            cout << "Your desire work position:";
                                            cin >> desiredPosition;
                                            cout << "Your desire city to work in:";
                                            cin >> desiredCityToWork;
                                            cout << "Can u travel everywhere for work? (1 for yes,0 for no):";
                                            cin >> travelCapability;

                                            workConditions.add(newUser.getID(),salaryException,desiredPosition,desiredCityToWork,travelCapability);
                                            workConditions.display();

                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
                                            break;
                                        case 11: // Add Social Skills
                                            cout << "Add social skill to your cv:" << endl;
                                            validChoice = false;
                                            while (!validChoice) {
                                                cout << "Welcome Socials:" << endl;
                                                cout << "1-Please Enter Social Clubs if you do" << endl;
                                                cout << "2-Please Enter VolunteerWorks if you do" << endl;
                                                cout << "3-there was no social participation" << endl;
                                                cin >> ch;

                                                switch (ch) {
                                                    case 1:
                                                        cout << "Enter Club :" << endl;
                                                        cin >> socialfactor;
                                                        if(clubcount<5){
                                                            AlgoPoint+=1;
                                                        }
                                                        clubcount++;
                                                        cout << "Adding Succesfull..." << endl;

                                                        break;
                                                    case 2:
                                                        cout << "Enter Volunteer:" << endl;
                                                        cin >> volunteerwork;

                                                        if(volcount<2){
                                                            AlgoPoint+=5;
                                                        }
                                                        volcount++;
                                                        cout << "Adding Succesfull...." << endl;

                                                        break;
                                                    default:
                                                        cout << "Exit Succesfull..." << endl;
                                                        validChoice=true;
                                                        break;
                                                }
                                                social.add(user->getID(),socialfactor,volunteerwork);
                                            }
                                            social.display();
                                            cout << "1-Back to Candidate Main Menu\n>";
                                            back = menuMethods.getUserInputWithControl();
                                            if (back == 1) { continue; }
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

                                        case 13: // Back to User Main Menu
                                            cout << "Returning to candidate main menu..." << endl;
                                            continue;
                                    }
                                    break;

                                case 5: // 5-My Rank and Applied Ads
                                    cout << "My Rank:"<< AlgoPoint << endl;
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
                                                                 Point,
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
                                                                             Point,
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
                                                                 Point,
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
                                                                             Point,
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

delete user;
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
