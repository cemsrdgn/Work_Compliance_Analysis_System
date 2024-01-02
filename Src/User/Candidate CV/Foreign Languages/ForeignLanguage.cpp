//
// Created by cemsr on 15.12.2023.
//

#include "ForeignLanguage.h"
#include <iostream>
#include <string>
//#include <vector>

using namespace std;

ForeignLanguage::ForeignLanguage(int id,Language language1)
{
    this->language=language1;
}

string ForeignLanguage::getLanguageName(){
    return this->language.LanguageName;
}
string ForeignLanguage::getWriting(){
    return this->language.Writing;
}
string ForeignLanguage::getReading(){
    return this->language.Reading;
}
string ForeignLanguage::getListening(){
    return this->language.Listening;
}
string ForeignLanguage::getSpeaking(){
    return this->language.Speaking;
}

void ForeignLanguage::setLanguage(int id,Language l) {
    ForeignLanguage newmember(id,l);
    lan.push_back(newmember);
}
void ForeignLanguage::display() {
    cout << "Graduates " << endl;
    for (size_t i = 0; i < lan.size(); i++) {
        cout << i + 1 << " Language " << lan[i].getLanguageName() << endl;
        cout << " Writing Level " << lan[i].getWriting() << endl;
        cout << " Reading level " << lan[i].getReading() << endl;
        cout << " Listening level " << lan[i].getListening() << endl;
        cout << " Speaking level " << lan[i].getSpeaking() << endl;
    }
}
