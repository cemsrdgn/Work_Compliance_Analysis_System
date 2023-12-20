//
// Created by cemsr on 15.12.2023.
//

#include "ExamInformation.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ExamInformation::ExamInformation(string rank,string point)
{
    this->ExamRank=rank;
    this->ExamPoint=point;
}
ExamInformation::ExamInformation(string point)
{
    this->ExamPoint=point;
}
void ExamInformation:: addExamRating(string examrank,string exampoint){
    cout << "enter exam point" << endl;
    cin >> exampoint;
    cout << "enter exam rank" << endl;
    cin >> examrank;
    ExamInformation newgradute(examrank,exampoint);
    graduates.push_back(newgradute);
}
void ExamInformation::addExamRating(string exampoint) {
    cout << "enter exam point" << endl;
    cin >> exampoint;
    ExamInformation newgradute(exampoint);
    graduates.push_back(newgradute);
}

string ExamInformation::getExamRank(){
    return this->ExamRank;
}

string ExamInformation::getExamPoint(){
    return this->ExamPoint;
}
void ExamInformation::displayGraduate(){
    for (size_t i = 0; i < graduates.size(); i++) {
        cout << i + 1 << "Exam Point: " << graduates[i].getExamPoint() << endl;
    }
}
void ExamInformation::displayYksGraduate(){
    for (size_t i = 0; i < graduates.size(); i++) {
        cout << i + 1 << "YKS Exam point: "  << graduates[i].getExamPoint() << endl;
        cout << "YKS Exam Rank: " << graduates[i].getExamRank() << endl;
    }
}
void ExamInformation::selectExam(){
    string examrank,exampoint;
    int choice,ch;
    bool exitMenu=false;
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
                    addExamRating(examrank, exampoint);
                    displayYksGraduate();
                }
                else if (ch == 2) {
                    addExamRating(exampoint);
                    cout << "KPSS   ";
                    displayGraduate();
                }
                else if (ch == 3) {
                    addExamRating(exampoint);
                    cout << "ALES   ";
                    displayGraduate();
                }
                else if (ch == 4) {
                    addExamRating(exampoint);
                    cout << "TUS    ";
                    displayGraduate();
                }
                else if (ch == 5) {
                    addExamRating(exampoint);
                    cout << "YDS    ";
                    displayGraduate();
                }
                else if (ch == 6) {
                    addExamRating(exampoint);
                    cout << "YÖK DİL    ";
                    displayGraduate();
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
                    addExamRating(exampoint);
                    cout << "IELTS    ";
                    displayGraduate();
                }
                else if (ch == 2) {
                    addExamRating(exampoint);
                    cout << "TOEFL    ";
                    displayGraduate();
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
}