cmake_minimum_required(VERSION 3.21)
project(Work_Compliance_Analysis_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(Src/User)

add_executable(Work_Compliance_Analysis_System
        "Src/User/Candidate CV/Communication Information/CommunicationInformation.cpp"
        "Src/User/Candidate CV/Communication Information/CommunicationInformation.h"
        "Src/User/Candidate CV/Education Information/EducationInformation.cpp"
        "Src/User/Candidate CV/Education Information/EducationInformation.h"
        "Src/User/Candidate CV/Expertise Areas/ExpertiseAreas.cpp"
        "Src/User/Candidate CV/Expertise Areas/ExpertiseAreas.h"
        "Src/User/Candidate CV/Hobies/Hobie.cpp"
        "Src/User/Candidate CV/Hobies/Hobie.h"
        "Src/User/Candidate CV/Foreign Languages/ForeignLanguage.cpp"
        "Src/User/Candidate CV/Foreign Languages/ForeignLanguage.h"
        "Src/User/Candidate CV/Personal Documents/PersonalDocument.cpp"
        "Src/User/Candidate CV/Personal Documents/PersonalDocument.h"
        "Src/User/Candidate CV/Projects/Projects.cpp"
        "Src/User/Candidate CV/Projects/Projects.h"
        "Src/User/Candidate CV/Certificates/Certificates.cpp"
        "Src/User/Candidate CV/Certificates/Certificates.h"
        "Src/User/Candidate CV/Social Skills/SocialSkills.cpp"
        "Src/User/Candidate CV/Social Skills/SocialSkills.h"
        "Src/User/Candidate CV/Work Conditions/WorkConditions.cpp"
        "Src/User/Candidate CV/Work Conditions/WorkConditions.h"
        "Src/User/Candidate CV/Work Experiences/WorkExperience.cpp"
        "Src/User/Candidate CV/Work Experiences/WorkExperience.h"
        main.cpp
        README.md
        "Src/User/Candidate CV/Exams Information/ExamInformation.h"
        "Src/User/Candidate CV/Exams Information/ExamInformation.cpp"
        "Src/User/Candidate CV/Refarance/Refarance.h"
        "Src/User/Candidate CV/Refarance/Refarance.cpp")
