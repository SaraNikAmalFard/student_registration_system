#include "Student.hpp"
#include "MSc.hpp"
#include "Ug.hpp"
#include "PhD.hpp"
#include "StudentRegistration.hpp"
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;
using std::cin;



string displayMenu()
{
  string userInput;
    cout<<"\n"<<"************** Student Registration System Main Menu **************"<<"\n"<<endl;
    cout<<"Please choose one of the options below (A-J):"<<"\n"<< endl;
    cout<<"A - Displaying all students"<<endl;
    cout<<"B - Add a student"<<endl;
    cout<<"C - Enrol in modules"<<endl;
    cout<<"D - Remove a student"<<endl;
    cout<<"E - Find student by student Id"<<endl;
    cout<<"F - Find students by type"<<endl; 
    cout<<"G - Find students by modules he/she is enrolled in"<<endl; 
    cout<<"H - Search undergaduate students by advisor"<<endl;
    cout<<"I - Search master's students by department"<<endl;
    cout<<"J - Exit system"<<endl;
    while (userInput != "A" && userInput != "B" && userInput != "C" && userInput != "D" && userInput !="E" && userInput != "F" && userInput != "G" && userInput != "H" && userInput != "I" && userInput != "J")
    {
     getline(cin,userInput);
     if(userInput == "A" || userInput == "B" || userInput == "C" || userInput == "D" || userInput =="E" || userInput == "F" || userInput == "G" || userInput == "H" || userInput == "I" || userInput == "J")
     break;
     else cout<<"Please try again (A-J):"<<endl;
    }
    return userInput;
}

int main()
{
    StudentRegistration registration;
    registration.readStudentsFromFile();
    string input;
    while(input != "J")
    {
    
    input = displayMenu();

    if(input == "A")
    {registration.showAllStudents();}

    else if(input == "B")
    {registration.addStudent();}

    else if(input == "C")
    {registration.enrolProcess();}

    else if(input == "D")
    {registration.removeStudent();}

    else if(input == "E")
    {registration.findStudentById();}

    else if(input == "F")
    {registration.findStudentsByType();}

    else if(input == "G")
    {registration.findStudentsByModulesEnrolled();}

    else if(input == "H")
    {registration.searchUndergardStudentsByAdvisor();}

    else if(input == "I")
    {registration.searchMasterStudentsByDepartment();}
      
    else if(input == "J")
    {
      registration.writeStudentsToFile();
      cout<<"Thanks for using the Student Registration System!"<<endl;
      return 0; 
    }
    }
    return 0;
}