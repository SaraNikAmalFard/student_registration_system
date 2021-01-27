#include"Student.hpp"
#include"MSc.hpp"
#include<iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

MSc::MSc(int studentId ,string  name, string surname,string address, string department
         ,string advisor , TuitionFeeStatus feeStatus , int yearOfStudy)
         :Student(studentId , name, surname, address, department,advisor, feeStatus, yearOfStudy)
         { /*this->yearOfStudy = 0; */}
         

int MSc::calculateTuitionFee()
{
   int tuition;
   switch (fee)
   {
   case home:
      tuition = 10000;
      break;
   case eu:
      tuition = 10000;
      break;
   case international:
      tuition = 20000;
      break;
   }
 return tuition;
}

void MSc::displayStudents()
{
   cout<<"StudentID: "<<studentID<<" | "<<"firstname: "<<name<<" | "<<"Surname: "<<surname<<" | "<<"Address: "<<address<<" | "<<"Department: "
    <<department<<" | "<<"Advisor: "<<advisor<<" | "<<"Fee: "<<calculateTuitionFee()<<" | "<<"Fee Status: "<<feeStatusString()<<" | "<<"Level: "<<"Master's"<<endl;
}

MSc::LevelOfStudy MSc::whatIsYourLevel()
{return MSc::LevelOfStudy::MSc;}

int MSc::getYearOfStudy()
{ int year=0; 
  return year;
}


