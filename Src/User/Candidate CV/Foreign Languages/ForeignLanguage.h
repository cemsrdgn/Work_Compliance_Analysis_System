//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H



#include <string>
#include <vector>
#include "Candidate/User.h"
using namespace std;

struct Language{
    string LanguageName;
    string Writing;
    string Reading;
    string Listening;
    string Speaking;
};

class ForeignLanguage : public User{
private:
    Language language;
    vector<ForeignLanguage> lan;
public:
    ForeignLanguage(int id,Language language1);
    string getLanguageName();
    string getWriting();
    string getReading();
    string getListening();
    string getSpeaking();
    void setLanguage(int id,Language l);
    void display() override;

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H
