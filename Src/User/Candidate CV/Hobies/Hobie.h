//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIE_H


#include <string>
#include <vector>
#include "Candidate/User.h"
class Hobie: public User {
private:
    vector<Hobie> hobie;
    string Hobies;

public:
    Hobie();

    Hobie(int id,string hobies);

    void display ();
    void update();
    void remove();
    void add(int id,string hobies);
    void remove(int id,string hobies);
    const string &get() const;

    void setHobies(const string &hobies);

    void add(int id);

    const vector<Hobie> &getHobie() const;

    void setHobie(const vector<Hobie> &hobie);


    const string &getHobies() const;


};

#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIE_H
