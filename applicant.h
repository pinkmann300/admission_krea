#ifndef APPLICANT_H
#define APPLICANT_H

#include <iostream>
#include <string> 

class Applicant {

private:
    std::string name;
    int age;
    std::string previousSchool;
    float previousGPA;

public:
    Applicant(std::string aName, int aAge, std::string aPreviousSchool, float apreviousGpa); 
    std::string getName(); 
    int getAge(); 
    std::string getPrevSchool(); 
    float getGPA(); 
};

#endif // APPLICANT_H 