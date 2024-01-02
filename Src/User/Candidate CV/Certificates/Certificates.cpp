//
// Created by cemsr on 15.12.2023.
//

#include "Certificates.h"
#include <string>
#include <iostream>

using namespace std;

Certificates::Certificates() {

}
Certificates::Certificates(int id,string certifica) {
    this->Certificate=certifica;
    this->ID=id;
}
string Certificates::getCertificates() {
    return this->Certificate;
}
void Certificates::addCertificates(int id, string certificates) {
    Certificates newCertifica(id,certificates);
    Certificatess.push_back(newCertifica);
}

void Certificates::display() {
    for(int i = 0; i < Certificatess.size(); i++) {
        cout << "Certificate: " << Certificatess[i].Certificate << endl;
    }
}
