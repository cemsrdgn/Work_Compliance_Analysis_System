//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H



#include <string>
#include <vector>
using namespace std;

struct Language{
    string LanguageName;
    string Writing;
    string Reading;
    string Listening;
    string Speaking;
};

class ForeignLanguage {
private:
    Language language;
    vector<ForeignLanguage> lan;
public:
    ForeignLanguage(Language language1);
    string getLanguageName();
    string getWriting();
    string getReading();
    string getListening();
    string getSpeaking();
    void setLanguage(Language l);
    void display();

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_FOREIGNLANGUAGE_H
