//
// Created by 90554 on 2.01.2024.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_REFARANCE_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_REFARANCE_H


#include <string>
#include <vector>
using namespace std;

class Reference {
public:
    Reference();  // Default constructor
    Reference(const string& name, const string& position, const string& phoneNumber);  // Parametrized constructor
    ~Reference();  // Destructor

    void display() const;
    void update(const string& name, const string& position, const string& phoneNumber);

    // Getter functions
    string getName() const;
    string getPosition() const;
    string getPhoneNumber() const;

    static void addReference(const string& name, const string& position, const string& phoneNumber);
    static void displayAllReferences();
    static vector<Reference> references;  // Static vector to store reference instances

private:
    string name;
    string position;
    string phoneNumber;
};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_REFARANCE_H
