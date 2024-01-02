//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_CERTIFICATES_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_CERTIFICATES_H


#include "Candidate/User.h"
#include <vector>
#include <string>
using namespace std;

class Certificates: public User{
private:
    string Certificate;
    vector<Certificates>Certificatess;
public:
    Certificates();
    Certificates(int id,string certificates);
    string getCertificates();
    void addCertificates(int id,string certificates);
    void display() override;
};



#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_CERTIFICATES_H
