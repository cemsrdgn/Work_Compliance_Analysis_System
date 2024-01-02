//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_SOCIALSKILLS_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_SOCIALSKILLS_H

#include <string>
#include <vector>
#include "Candidate/User.h"

class SocialFactors: public User {
private:
    string SocialFactor;
    vector<SocialFactors> Social;
    string volunteerwork;
public:

    //default constructor
    SocialFactors();

    // parametreli constructor
    SocialFactors(int id,string socialfactors,string volunteerwork);
    void display () override;
    void update();
    void remove(int id,string socialfactors,string volunteerwork);
    void add(int id,string socialfactors,string volunteerwork);
    void add(int id,string socialfactors);

    const vector<SocialFactors> &getSocialFactor() const;

    void setSocialFactor(const vector<SocialFactors> &socialFactor);

    const string &getSocialfactors() const;

    void setSocialfactors(const string &socialfactors);

    const string &getVolunteerwork() const;

    void setVolunteerwork(const string &volunteerwork);

    const vector<SocialFactors> &getSocial() const;

    void setSocialFactor(const string &socialFactor);

    void setSocial(const vector<SocialFactors> &social);
};



#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_SOCIALSKILLS_H
