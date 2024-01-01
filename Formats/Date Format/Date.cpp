//
// Created by cemsr on 17.12.2023.
//

#include "Date.h"
#include <iostream>

using namespace std;

Date::Date() : day{1},month{1},year{2000}{
    cout << "No Args Constructor Called.";
}

Date::Date(int d, int m, int y) {

    this->day=d;
    this->month=m;
    this->year=y;

    cout << "Three Args Constructor Called.";
}

void Date::displayDate() const{

    cout << day <<"/"<<month<<"/"<<year<<endl;
}

void Date::setDay(int day) {Date::day = day;}
void Date::setMonth(int month) {Date::month = month;}
void Date::setYear(int year) {Date::year = year;}

void Date::updateDate(int bday,int bmonth,int byear) {

    setDay(bday);
    setMonth(bmonth);
    setYear(byear);
}