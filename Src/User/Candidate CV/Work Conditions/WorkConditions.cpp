//
// Created by cemsr on 15.12.2023.
//

#include <string>
#include <vector>
#include "Candidate/User.h" //

class WorkConditions : public User {
private:
    std::vector<WorkConditions> workconditions;
    int salaryExcemptions;
    std::string disaredPositionsTo;
    std::string desiredCityToWork;
    bool travelCapability;

public:

    WorkConditions();


    WorkConditions(int id,
                   int salaryExcemptions,
                   string disaredPositionsTo,
                   string desiredCityToWork,
                   bool travelCapability);


    void display() override;
    void update();
    void remove();
    void add(int id, int salaryExcemptions, std::string disaredPositionsTo, std::string desiredCityToWork, bool travelCapability);

    // Getter ve Setter metodları
    const std::string &getDisaredPositionsTo() const;
    void setDisaredPositionsTo(const std::string &disaredPositionsTo);

    int getSalaryExcemptions() const;
    void setSalaryExcemptions(int salaryExcemptions);

    const std::string &getDesiredCityToWork() const;
    void setDesiredCityToWork(const std::string &desiredCityToWork);

    bool isTravelCapability() const;
    void setTravelCapability(bool travelCapability);

    // Diğer fonksiyonlar
    const std::vector<WorkConditions> &getWorkconditions() const;

    void getAdvertisementInfo(std::string& adTitle,
                              std::string& companyDescription,
                              int& salary,
                              std::string& city,
                              std::string& applicationDeadLine,
                              std::string& sector,
                              std::string& position,
                              std::string& workPreference,
                              std::string& workType,
                              std::string& experience,
                              std::string& positionLevel,
                              std::string& educationLevel,
                              std::string& language,
                              std::string& militaryService);
};