#include "PhD.hpp"
#include "Student.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

PhD::PhD(int studentId, string name, string surname, string address, 
string department,string supervisor, TuitionFeeStatus feeStatus, int yearOfStudy)
:Student(studentId , name, surname, address, department , supervisor , feeStatus , yearOfStudy)
{
    if(yearOfStudy>4 || yearOfStudy<1)
    {throw std::invalid_argument("Year is not valid");}
    else this->yearOfStudy = yearOfStudy;   
}

int PhD::getYearOfStudy()
{return yearOfStudy;}

int PhD::calculateTuitionFee()
{
    int tuition;
    switch (fee)
    {
    case home:
        tuition = 12000;
        break;
    case eu:
        tuition = 12000;

    case international:
        tuition = 24000;
        break;
    }
 return tuition;
}

void PhD::displayStudents()
{
    cout<<"StudentID: "<<studentID<<" | "<<"firstname: "<<name<<" | "<<"Surname: "<<surname<<" | "<<"Address: "<<address<<" | "<<"Department: "
    <<department<<" | "<<"Supervisor: "<<advisor<<" | "<<"Fee: "<<calculateTuitionFee()<<" | "<<"Fee Status: "<<feeStatusString()<<" | "<<"Level: "<<"PhD"<<" | "<<"Year of Study: "<<yearOfStudy<<endl;
}

PhD::LevelOfStudy PhD::whatIsYourLevel()
{
  return PhD::LevelOfStudy::PhD;
}




