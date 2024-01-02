//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMMUNICATIONINFORMATION_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMMUNICATIONINFORMATION_H


#include <string>
#include <vector>
using namespace std;

class CommunicationInformation {
public:
    CommunicationInformation();  // Default constructor
    CommunicationInformation(const string& email, const string& phone, const string& address);  // Parametrized constructor
    ~CommunicationInformation();  // Destructor

    void display() const;
    void update(const string& email, const string& phone, const string& address);

    // Getter functions
    string getEmail() const;
    string getPhone() const;
    string getAddress() const;

    static void addInfo(const string& email, const string& phone, const string& address);
    static void displayAllInfo();
    static vector<CommunicationInformation> infos;  // Static vector to store info instances

    void addCommuni(int i, string basicString, string basicString1, string basicString2);

    void addReference(int i, string basicString, string basicString1, string basicString2);

private:
    string email;
    string phone;
    string address;
};



#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_COMMUNICATIONINFORMATION_H
