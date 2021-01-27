#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H
#include "Student.hpp"
#include<iostream>

class StudentRegistration
{
public:
  vector<Student*> students;
  void addStudent();
  void showAllStudents();  
  void readStudentsFromFile();  
  void removeStudent();
  void writeStudentsToFile();
  void findStudentById();
  void enrolProcess();
  void findStudentsByType();
  void findStudentsByModulesEnrolled();
  void searchUndergardStudentsByAdvisor();
  void searchMasterStudentsByDepartment();
};
#endif