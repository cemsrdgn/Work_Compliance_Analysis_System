//
// Created by cemsr on 15.12.2023.
//

#ifndef WORK_COMPLIANCE_ANALYSIS_SYSTEM_PERSONALDOCUMENT_H
#define WORK_COMPLIANCE_ANALYSIS_SYSTEM_PERSONALDOCUMENT_H

#include <string>
#include <vector>
using namespace std;


class PersonalDocument {
public:
    PersonalDocument();  // Default constructor
    PersonalDocument(const string& title, const string& type, const string& content);  // Parametrized constructor
    ~PersonalDocument();  // Destructor

    void display() const;
    void update(const string& title, const string& type, const string& content);

    static void addDocument(const string& title, const string& type, const string& content);
    static void displayAllDocuments();
    static vector<PersonalDocument> documents;  // Static vector to store document instances

private:
    string title;
    string type;
    string content;

};


#endif //WORK_COMPLIANCE_ANALYSIS_SYSTEM_PERSONALDOCUMENT_H
