cmake_minimum_required(VERSION 3.21)
project(Work_Compliance_Analysis_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(Src/User)

add_executable(Work_Compliance_Analysis_System
        "Src/User/Candidate CV/Communication Information/CommunicationInformation.cpp"
        "Src/User/Candidate CV/Communication Information/CommunicationInformation.h"
        Src/User/EducationInformation.cpp
        Src/User/EducationInformation.h
        Src/User/ExamsInformations.cpp
        Src/User/ExamsInformations.h
        "Src/User/Candidate CV/Expertise Areas/ExpertiseAreas.cpp"
        "Src/User/Candidate CV/Expertise Areas/ExpertiseAreas.h"
        "Src/User/Candidate CV/Hobies/Hobies.cpp"
        "Src/User/Candidate CV/Hobies/Hobies.h"
        Src/User/ForeignLanguage.cpp
        Src/User/ForeignLanguage.h
        "Src/User/Candidate CV/Personal Documents/PersonalDocuments.cpp"
        "Src/User/Candidate CV/Personal Documents/PersonalDocuments.h"
        "Src/User/Candidate CV/Projects/Projects.cpp"
        "Src/User/Candidate CV/Projects/Projects.h"
        "Src/User/Candidate CV/Certificates/Certificates.cpp"
        "Src/User/Candidate CV/Certificates/Certificates.h"
        "Src/User/Candidate CV/Social Skills/SocialSkills.cpp"
        "Src/User/Candidate CV/Social Skills/SocialSkills.h"
        "Src/User/Candidate CV/Work Conditions/WorkConditions.cpp"
        "Src/User/Candidate CV/Work Conditions/WorkConditions.h"
        Src/User/WorkExperience.cpp
        Src/User/WorkExperience.h
        main.cpp
        README.md)
