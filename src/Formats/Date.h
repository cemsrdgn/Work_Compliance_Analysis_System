//
// Created by cemsr on 17.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_DATE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_DATE_H


class Date {

private:
    int day;
    int month;
    int year;

public:

    //No args constructor
    Date();

    //Three args constructor
    Date(int d,int m, int y);

    //Displays date
    void displayDate() const;

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_DATE_H
