//
// Created by cemsr on 15.12.2023.
//
/*
#include <string>
#include <vector>
#include "Candidate/User.h"
#include "WorkConditions.h"


using namespace std;
class WorkConditions : public User {
private:
    vector<WorkConditions> workconditions;
    int salaryExcemptions;
    string disaredPositionsTo;
    string desiredCityToWork;
    bool travelCapability;

public:

    WorkConditions();


    WorkConditions(int id,
                   int salaryExcemptions,
                   string disaredPositionsTo,
                   string desiredCityToWork,
                   bool travelCapability){
        this->
    }


    void display() override;
    void update();
    void remove();
    void add(int id, int salaryExcemptions, string disaredPositionsTo, string desiredCityToWork, bool travelCapability);

    // Getter ve Setter metodları
    const string &getDisaredPositionsTo() const;
    void setDisaredPositionsTo(const string &disaredPositionsTo);

    int getSalaryExcemptions() const;
    void setSalaryExcemptions(int salaryExcemptions);

    const string &getDesiredCityToWork() const;
    void setDesiredCityToWork(const string &desiredCityToWork);

    bool isTravelCapability() const;
    void setTravelCapability(bool travelCapability);

    // Diğer fonksiyonlar
    const vector<WorkConditions> &getWorkconditions() const;

    void getAdvertisementInfo(string& adTitle,
                              string& companyDescription,
                              int& salary,
                              string& city,
                              string& applicationDeadLine,
                              string& sector,
                              string& position,
                              string& workPreference,
                              string& workType,
                              string& experience,
                              string& positionLevel,
                              string& educationLevel,
                              string& language,
                              string& militaryService);
};*/