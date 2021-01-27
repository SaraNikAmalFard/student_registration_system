#ifndef PHD_H
#define PHD_H
#include "Student.hpp"
#include<iostream>
using std::string;

class PhD:public Student
{
public:
  PhD(int studentId,string name, string surename, string address, string department, 
  string supervisor, TuitionFeeStatus feeStatus, int yearOfStudy) ;
  int getYearOfStudy();
  int calculateTuitionFee();
  void displayStudents();
  LevelOfStudy whatIsYourLevel();
};

#endif