#include "Ug.hpp"
#include "Student.hpp"
#include <iostream>
#include <stdexcept>
using std::string;
using std::cin;
using std::cout;
using std::endl;

Ug::Ug(int studentID, string name , string surname,string address, string department 
      ,string advisor , TuitionFeeStatus feeStatus , int yearOfStudy)
      
      :Student(studentID , name , surname, address, department , advisor , feeStatus ,yearOfStudy)
{  }


int Ug::getYearOfStudy()
{return yearOfStudy;}

int Ug::calculateTuitionFee()
{
    int tuition;
    switch (fee)
    {
    case home:
        tuition = 9000; 
        break;
    case eu:
        tuition = 9000;
        break;
    case international:
        tuition = 18000;
        break;
    }
    return tuition;
}

void Ug::displayStudents()
{
    cout<<"StudentID: "<<studentID<<" | "<<"firstname: "<<name<<" | "<<"Surname: "<<surname<<" | "<<"Address: "<<address<<" | "<<"Department: "
    <<department<<" | "<<"Advisor: "<<advisor<<" | "<<"Fee: "<<calculateTuitionFee()<<" | "<<"Fee Status: "<<feeStatusString()<<" | "<<"Level:" <<"Undergaduate"<<" | "<<"Year of Study: "<<yearOfStudy<<endl;
}

Ug::LevelOfStudy Ug::whatIsYourLevel()
{return Ug::LevelOfStudy::Ug;}





