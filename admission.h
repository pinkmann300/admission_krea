#ifndef ADMISSION_H
#define ADMISSION_H


#include "applicant.h"
#include <iostream>
#include <string>

class AdmissionProcess {
    public:
        AdmissionProcess();
        void start(); 
        Applicant gatherInformation(); 
        void evaluateApplication(Applicant a1); 
};

#endif // ADMISSION_H