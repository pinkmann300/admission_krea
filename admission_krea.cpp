#include "applicant.h"
#include "admission.h"

#include <iostream>
#include <string>


using namespace std;

    Applicant::Applicant(string aName, int aAge, string aPreviousSchool, float apreviousGpa)
    :name(aName), age(aAge), previousSchool(aPreviousSchool), previousGPA(apreviousGpa)
    {}

    string Applicant::getName() 
    {
        return name;
    }

    int Applicant::getAge()
    {
        return age;
    }

    string Applicant::getPrevSchool()
    {
        return previousSchool;
    }

    float Applicant::getGPA()
    {
        return previousGPA;
    }



    AdmissionProcess::AdmissionProcess()
    {
        cout << "Welcome to Krea University Admission Process!" << endl;
    }

    void AdmissionProcess::start() 
    {
       
        Applicant a1 = gatherInformation();
        evaluateApplication(a1);
    }

    Applicant AdmissionProcess::gatherInformation()
    {

        std::string na, ps;
        int ag; 
        float gp;

        cout << "Please provide your information:" << endl;
        cout << "First Name: ";
        cin >> na;


        cout << "Age: ";
        cin >> ag;

        cout << "Previous GPA: ";
        cin >> gp;

        cout << "Previous School: ";
        cin >> ps;

        return Applicant(na, ag,ps,gp);

    }

    void AdmissionProcess::evaluateApplication(Applicant a1) {

        if (a1.getAge() >= 18 && a1.getGPA() >= 3.0) {
            cout << "Congratulations, " << a1.getName() << "! You have been accepted to Krea University." << endl;
        } else {
            cout << "We regret to inform you that you did not meet the admission criteria." << endl;
        }
    }


