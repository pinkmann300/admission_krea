#include <iostream>
#include <vector>
#include <memory>

class Grades
{
private:
    std::string courseName;
    int courseCredits;
    std::string letterGrade;
    double gradePointAverage;

public:
    Grades(std::string cName, int cCredits, std::string lGrade)
        : courseName(cName), courseCredits(cCredits), letterGrade(lGrade)
    {
        // Calculate GPA based on letter grade and store it
        gradePointAverage = calculateGPA();
    }

    double getGpa(){
        return gradePointAverage;
    }

    double getCourseCredits(){
        return courseCredits;
    }

    double calculateGPA()
    {
        // Add logic to calculate GPA based on the letter grade
        // You can use your existing logic here
        // For simplicity, we'll use a placeholder GPA calculation
        return 4.0; // Replace this with your GPA calculation logic
    }

    void displayGrade()
    {
        std::cout << "Course Name: " << courseName << std::endl;
        std::cout << "Credits: " << courseCredits << std::endl;
        std::cout << "Letter Grade: " << letterGrade << std::endl;
        std::cout << "GPA: " << gradePointAverage << std::endl;
    }
};

class Student
{
private:
    std::string studentName;
    std::string studentRollNo;
    int studentAge;
    std::string studentMajor;
    std::vector<std::unique_ptr<Grades>> courseGrades;

public:
    Student(std::string sName, std::string sRollNo, int sAge, std::string sMajor)
        : studentName(sName), studentRollNo(sRollNo), studentAge(sAge), studentMajor(sMajor) {}

    void addGrades(std::string cName, int cCredits, std::string lGrade)
    {
        std::unique_ptr<Grades> grade = std::make_unique<Grades>(cName, cCredits, lGrade);
        courseGrades.push_back(std::move(grade));
    }

    void displayGradeReport()
    {
        std::cout << "Student Name: " << studentName << std::endl;
        std::cout << "Roll No: " << studentRollNo << std::endl;
        std::cout << "\n";

        int cred_sum = 0;
        double cgpa = 0.0;

        for (const auto &grade : courseGrades)
        {
            grade->displayGrade();
            cred_sum += grade->getCourseCredits();
            cgpa += grade->getGpa();
            std::cout << "\n";
        }

        std::cout << "Total credits: " << cred_sum << std::endl;
        if (cred_sum > 0)
        {
            std::cout << "CGPA: " << (cgpa / cred_sum) << std::endl;
            std::cout << "Remaining credits for graduation: " << (128 - cred_sum) << std::endl;
        }
    }


};

int main()
{
    std::string studentName, studentRollNo, studentMajor;
    int studentAge;
    std::cout << "Enter student name: ";
    std::cin >> studentName;
    std::cout << "Enter student roll number: ";
    std::cin >> studentRollNo;
    std::cout << "Enter student age: ";
    std::cin >> studentAge;
    std::cout << "Enter student major: ";
    std::cin >> studentMajor;

    Student student(studentName, studentRollNo, studentAge, studentMajor);

    std::string input;
    do
    {
        std::string courseName, letterGrade;
        int courseCredits;

        std::cout << "Enter course name: ";
        std::cin >> courseName;
        std::cout << "Enter course credits: ";
        std::cin >> courseCredits;
        std::cout << "Enter letter grade: ";
        std::cin >> letterGrade;

        student.addGrades(courseName, courseCredits, letterGrade);

        std::cout << "Would you like to add another grade (yes/no)? ";
        std::cin >> input;
    } while (input == "yes");

    std::cout << "\n";
    std::cout << "Final grade report:\n";
    student.displayGradeReport();

    return 0;
}
