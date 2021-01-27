#ifndef MSC_H
#define MSC_H
#include "Student.hpp"
#include<iostream>
using std::string;

class MSc:public Student
{
public:
 MSc(int studentId , string name, string surname ,string address, 
    string department, string advisor, TuitionFeeStatus feeStatus ,int yearOfStudy);
 int calculateTuitionFee();
 void displayStudents();
 void setYearOfStudy();
 LevelOfStudy whatIsYourLevel();
 int getYearOfStudy();
};

#endif