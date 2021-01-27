#include "Student.hpp"
#include<iostream>
#include<random>
using std::cout;
using std::string;
using std::endl;

int Student::studentGlobalId = 0;

Student::Student(int studentId , string name, string surname,string address,
                  string department , string advisor, TuitionFeeStatus feeStatus, int yearOfStudy)
{
    this->name = name;
    this->surname = surname;
    this->department = department;
    this->address = address;
    this->advisor = advisor;
    this->fee = feeStatus;
    this->studentID = studentId;
    this->yearOfStudy = yearOfStudy;
    if(studentGlobalId < studentId)
    {studentGlobalId = studentId ;}
}

string Student::getName()
{return name;}

string Student::getSurname()
{return surname;}

string Student::getAddress()
{return address;}

string Student::getDepartment()
{return department;}

int Student::getStudentId()
{return studentID;}

string Student::getAdvisor()
{return advisor;}

int Student::generateUniqueID()
{return ++studentGlobalId;}

Student::TuitionFeeStatus Student::getFeeStatus()
{return fee;}

vector<string>& Student::getListOfModules()
{return this->modules;}

void Student::enrol(string moduleCode)
{   
    modules.push_back(moduleCode);
}

string Student::feeStatusString()
{
    string status;
    switch (fee)
    {
    case home:
       status = "Home";
        break;
    case eu:
       status = "Eu";
      break;
    case international:
         status = "International";
        break;
    }
    return status;
}
