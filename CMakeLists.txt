cmake_minimum_required(VERSION 3.21)
project(Work_Compliance_Analysis_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/User)

add_executable(Work_Compliance_Analysis_System
        src/User/CommunicationInformation.cpp
        src/User/CommunicationInformation.h
        src/User/EducationInformation.cpp
        src/User/EducationInformation.h
        src/User/ExamInformation.cpp
        src/User/ExamInformation.h
        src/User/ExpertiseAreas.cpp
        src/User/ExpertiseAreas.h
        src/User/Hobies.cpp
        src/User/Hobies.h
        src/User/ForeignLanguage.cpp
        src/User/ForeignLanguage.h
        src/User/PersonalDocuments.cpp
        src/User/PersonalDocuments.h
        src/User/PersonalInformation.cpp
        src/User/PersonalInformation.h
        src/User/Projects.cpp
        src/User/Projects.h
        src/User/Referances.cpp
        src/User/Referances.h
        src/User/Sertificates.cpp
        src/User/Sertificates.h
        src/User/SocialSkills.cpp
        src/User/SocialSkills.h
        src/User/WorkConditions.cpp
        src/User/WorkConditions.h
        src/User/WorkExperience.cpp
        src/User/WorkExperience.h
        main.cpp
        README.md)
