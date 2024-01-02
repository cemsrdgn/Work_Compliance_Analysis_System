//
// Created by cemsr on 15.12.2023.
//

#include "PersonalDocument.h"
#include <iostream>
using namespace std;

// Static vector definition
vector<PersonalDocument> PersonalDocument::documents;

// Default constructor
PersonalDocument::PersonalDocument() : title(""), type(""), content("") {}

// Parametrized constructor
PersonalDocument::PersonalDocument(const string& title, const string& type, const string& content)
        : title(title), type(type), content(content) {}

// Destructor
PersonalDocument::~PersonalDocument() {
}

// Display function
void PersonalDocument::display() const {
    cout << "Title: " << title << endl;
    cout << "Type: " << type << endl;
    cout << "Content: " << content << endl;
}

// Update function
void PersonalDocument::update(const string& title, const string& type, const string& content) {
    this->title = title;
    this->type = type;
    this->content = content;
}

// Add new PersonalDocument to the static vector
void PersonalDocument::addDocument(const string& title, const string& type, const string& content) {
    PersonalDocument newDocument(title, type, content);
    documents.push_back(newDocument);
}

// Static function to display all documents
void PersonalDocument::displayAllDocuments() {
    for (size_t i = 0; i < documents.size(); i++) {
        documents[i].display();
        cout << endl;
    }
}