//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIES_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIES_H


#include <string>
#include <vector>
#include "Candidate/User.h"
class Hobie: public User {
private:
    vector<Hobie> hobie;
    int RelatedSports;
    string Hobies;

public:
    Hobie();

    Hobie(int id,int relatedsports,string hobies);

    void display () override;
    void update();
    void remove();
    void add(int id,int relatedsports,string hobies);
    void remove(int id,int relatedsports,string hobies);
    const string &get() const;

    void setHobies(const string &Hobies);
    void add(int id);

    const vector<Hobie> &getHobie() const;

    void setHobie(const vector<Hobie> &hobie);

    int getRelatedsports() const;

    void setRelatedsports(int relatedsports);

    const string &getHobies() const;
};

#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_HOBIES_H
