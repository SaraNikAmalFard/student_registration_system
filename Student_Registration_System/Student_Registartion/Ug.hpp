#ifndef UG_H
#define UG_H
#include "Student.hpp"
#include <iostream>
#include <array>
using std::string;

class Ug:public Student
{   
public:
   Ug(int studentId ,string name, string surname, string address, string department,
      string advisor, TuitionFeeStatus feeStatus , int yearOfStudy);
   
   int getYearOfStudy();
   int calculateTuitionFee();
   void displayStudents();
   LevelOfStudy whatIsYourLevel();
   
};

#endif