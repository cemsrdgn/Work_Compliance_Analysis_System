//
// Created by cemsr on 15.12.2023.
//

#include "ForeignLanguage.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ForeignLanguage::ForeignLanguage(Language language1)
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

void ForeignLanguage::setLanguage(Language l) {
    ForeignLanguage newmember(l);
    lan.push_back(newmember);
    cout << language.LanguageName << " Writing level "
         << language.Writing << " Reading level " << language.Reading
         << " Listening level " << language.Listening << " Speaking level "
         << language.Speaking << endl;
}
void ForeignLanguage::display() {
    cout << "Graduates " << endl;
    for (size_t i = 0; i < lan.size(); i++) {
        cout << i + 1 << " Language " << lan[i].getLanguageName()
             << " Writing Level " << lan[i].getWriting()
             << " Reading level " << lan[i].getReading()
             << " Listening level " << lan[i].getListening()
             << " Speaking level " << lan[i].getSpeaking();
    }
}