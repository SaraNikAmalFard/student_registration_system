#include "StudentRegistration.hpp"
#include "Student.hpp"
#include "Ug.hpp"
#include "MSc.hpp"
#include "PhD.hpp"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using namespace std;

void StudentRegistration::readStudentsFromFile()
{
  ifstream fileStream;
  string fileToRead = "readStudents.txt";
  fileStream.open(fileToRead);
  if(fileStream.is_open())
  {
   string name , surname , address, department , advisor, module;
   int feeStatus , yearOfStudy , level , numOfModules , studentId;
   while(fileStream>>studentId>>name>>surname>>address>>department>>advisor>>feeStatus>>yearOfStudy>>level>>numOfModules)
   {
     
     Student::TuitionFeeStatus fee = static_cast<Student::TuitionFeeStatus>(feeStatus);
     if(level == Student::LevelOfStudy::Ug)
     {
       
       Student* undergraduate = new Ug(studentId,name,surname,address,department,advisor,fee,yearOfStudy);
      for(int i=0 ; i<numOfModules ; i++)
       { 
         fileStream>>module;
         undergraduate->getListOfModules().push_back(module);
       }
      students.push_back(undergraduate); 
     }

     else if (level == Student::LevelOfStudy::MSc)
     {
       Student* master = new MSc(studentId,name,surname,address,department,advisor,fee,yearOfStudy);
      for(int i=0 ; i<numOfModules ; i++)
       { fileStream>>module;
         master->getListOfModules().push_back(module);
       }
      students.push_back(master); 
     }

     else if(level == Student::LevelOfStudy::PhD)
     {
       Student* phd = new PhD(studentId,name,surname,address,department,advisor,fee,yearOfStudy);
      for(int i=0 ; i<numOfModules ; i++)
       { 
         
         fileStream>>module;
         phd->getListOfModules().push_back(module);
       }
      students.push_back(phd); 
     }
   }
  }
  else cerr<<"Couldn't open file"<<endl;
} 

void StudentRegistration::showAllStudents()
{
  
  for(int i=0 ; i<students.size() ; i++)
  {
    if(students[i]->whatIsYourLevel() == Student::LevelOfStudy::Ug)
    {
      cout<<i+1<<"-";
      (dynamic_cast<Ug*>(students[i])) -> displayStudents();
      cout<<"*****************************************************************************************"<<endl;
    }

    else if(students[i] ->whatIsYourLevel() == Student::LevelOfStudy::MSc)
    {
      cout<<i+1<<"-";
      (dynamic_cast<MSc*>(students[i])) -> displayStudents();
      cout<<"*****************************************************************************************"<<endl;
    }
    else if(students[i]->whatIsYourLevel() == Student::LevelOfStudy::PhD)
    {
      cout<<i+1<<"-";
      (dynamic_cast<PhD*>(students[i]))->displayStudents();
      cout<<"*****************************************************************************************"<<endl;
    }
  }
}


void StudentRegistration::addStudent()
{
  string name,surname,address,department,advisor;
  int yearOfStudy , level , feeStatus;
  bool nameNotString = true;

  cout<<"Please enter your name:"<<endl;
  
  while(nameNotString)
  {
   cin>>name;
   for(auto& i:name)
    {
    if(!(std::isalpha(i)))
    {
      nameNotString = true;
      cout<<"Names can contain alphabets only,please re-enter your name"<<endl;
      break;
    }
    else if(std::isalpha(i))
    nameNotString = false;
    }
   }
  
  cout<<"Please enter your surname(If your surname is more than one word please use dash instead of space):"<<endl;
  cin>>surname;
  cout<<"Please enter your address(If your address is more than one word please use dash instead of space):"<<endl;
  cin>>address;
  cout<<"Please enter your advisor's name(if your advisor's name is more than one word please use dash instead of space):"<<endl;
  cin>>advisor;
  cout<<"Please enter your department(CS , EE , Maths , Psycho):"<<endl;
  while (department != "CS" && department != "EE" && department != "Maths" && department != "Psycho")
  {
    cin>>department;
    if(department =="CS" || department =="EE" || department =="Maths" || department == "Psycho")
    break;
    else cout<<"Please enter a valid department"<<endl;
  }
  
  cout<<"Please select your fee Status (1 , 2 or 3):"<<endl;
  cout<<"1- Home"<<"\n"<<"2- EU "<<"\n"<<"3- International"<<endl;
  while(feeStatus !=1 && feeStatus !=2 && feeStatus !=3)
  {
    cin>>feeStatus;
    if(feeStatus ==1 || feeStatus ==2 || feeStatus ==3)
    break;
    else 
    { cin.clear();
     cin.ignore(1000 , '\n');
     cout<<"Please choose a number between 1 and 3 "<<endl;}
  }
  
  Student::TuitionFeeStatus fee = static_cast<Student::TuitionFeeStatus>(feeStatus);
  
  cout<<"Please enter your level of study (1 , 2 or 3):"<<endl;
  cout<<"1- Undergraduate"<<"\n"<<"2- Master's"<<"\n"<<"3- PhD"<<endl;
  while (level !=1 && level !=2 && level !=3)
  {
    cin>>level;
    if(level ==1 || level ==2 || level ==3)
    break;
    else 
    {
     cin.clear();
     cin.ignore(1000 , '\n');
     cout<<"Please enter enter a number between 1 and 3 "<<endl;
    }
  }
  if (level==1)
  {
    cout<<"Please enter your year of study (1,2,3) :"<<endl;
    while(yearOfStudy !=1 && yearOfStudy != 2 && yearOfStudy !=3)
    {
      cin>>yearOfStudy;
      if(yearOfStudy ==1 || yearOfStudy==2 || yearOfStudy ==3)
      break;
      else 
      {
       cin.clear();
       cin.ignore(1000 , '\n'); 
       cout<<"Please enter a correct year of study (1,2,3) "<<endl;
      }
    }
    
    int id = Student::generateUniqueID();
    Student* undergraduate = new Ug(id,name,surname,address,department,advisor,fee,yearOfStudy);
    students.push_back(undergraduate);
  }
  
  else if(level ==2)
  {
    int id= Student::generateUniqueID();
    Student* master = new MSc(id,name,surname,address,department,advisor,fee,0);
    students.push_back(master);
  }

  else if(level ==3)
  {
     cout<<"Please enter your year of study (1,2,3,4) :"<<endl;
    while(yearOfStudy !=1 || yearOfStudy != 2 || yearOfStudy !=3 || yearOfStudy !=4)
    {
      cin>>yearOfStudy;
      if(yearOfStudy ==1 || yearOfStudy==2 || yearOfStudy ==3 || yearOfStudy==4)
      break;
      else cout<<"Please enter a correct year of study (1,2,3) "<<endl;
    }

    int id = Student::generateUniqueID();
    Student* phd = new PhD(id,name,surname,address,department,advisor,fee,yearOfStudy);
    students.push_back(phd);
  }
  cout<<"*** New student is successfully added ***"<<endl;
}


void StudentRegistration::removeStudent()
{
  string stdID;
  int studentId;
  bool found = false;
  bool conversion = false;
  cout<<"Please enter ID of the student you want to remove "<<endl;
  getline(cin,stdID);
  
       try
       {
        studentId = std::stoi(stdID);
        conversion = true;
       }
       catch(...)
       {
        conversion = false;
        cerr<<"You did not enter a number...\n"; 
       } 

  if(conversion)
  {
    for(int i=0 ; i<students.size() ; i++)
   {
    if(studentId == students[i]->getStudentId())
    {students.erase(students.begin()+i);
    found = true;
    }
   }
  if(!found)
  cerr<<"This ID could not be found in the system"<<endl;
  else if(found)
  cout<<"*** Student is successfully removed ***"<<endl;
  }
  
}

void StudentRegistration::findStudentById()
{
  string stdID;
  int studentId;
  bool found = false;
  bool conversion = false;

  cout<<"Please enter a student ID to find the student:"<<endl;
  getline(cin,stdID);
  try
  {
    studentId = std::stoi(stdID);
    conversion = true;
  }
  catch(...)
  {
    conversion = false;
    cerr << "You did not a enter a number ..." << '\n';
  }
  
if(conversion)
{
  for(Student* student : students)
  {
    if(student->getStudentId() == studentId)
    {
      found = true;
      string name = student->getName();
      string surname = student->getSurname();
      string addrress = student->getAddress();
      string department = student->getDepartment();
      string advisor = student->getAdvisor();
      Student::LevelOfStudy level = student->whatIsYourLevel(); 
      int fee = student->calculateTuitionFee();
      Student::TuitionFeeStatus feeStatus = static_cast<Student::TuitionFeeStatus> (fee);
      if(level == Student::LevelOfStudy::Ug)
      {
        cout<<"\n***";
        (dynamic_cast<Ug*> (student))->displayStudents();
      }
      else if(level == Student::LevelOfStudy::MSc)
      {
        cout<<"\n***";
        (dynamic_cast<MSc*>(student))->displayStudents();
      }
      else if(level == Student::LevelOfStudy::PhD)
      {
        cout<<"\n***";
        (dynamic_cast<PhD*>(student))->displayStudents();
      }
    }
  }
  if(!found)
  cerr<<"This ID could not be found in the system"<<endl;
} 
} 

void StudentRegistration::writeStudentsToFile() 
{
  ofstream filestream;
  string fileToWrite = "readStudents.txt";
  filestream.open(fileToWrite);
  if(filestream.is_open())
  {
      for(Student* student:students)
      {
        filestream<<student->getStudentId()<<" "<<student->getName()<<" "<<student->getSurname()<<" "<<student->getAddress()<<" "<<student->getDepartment()<<" "<<student->getAdvisor()<<" "<<student->getFeeStatus()<<" "<<student->getYearOfStudy()<<" "<<student->whatIsYourLevel()<<" "<<student->getListOfModules().size()<<" "; 
        vector<string> modulesList = student->getListOfModules();
        for(int i=0 ;i<student->getListOfModules().size() ; i++)
        {
          filestream<<modulesList[i]<<" ";
        }
        filestream<<"\n";
      }
      if(filestream.fail())
      cerr<<"Failed o write to the file"<<endl;
  }
  else cout<<"Couldn't ioen file"<<endl;
}

void StudentRegistration::enrolProcess()
 {
  string studentId;
  string moduleCode;
  string moduleCount;
  bool alreadyForUg = false;
  bool alreadyForMSc = false;
  bool alreadyForPhD = false;
  bool found = false;
  bool conversion = false;
  int id;
  
  
  cout<<"Please enter your student Id:"<<endl;
  getline(cin,studentId);
    try
       {
         id = std::stoi(studentId);
         conversion = true;
       }
       catch(...)
       {
         conversion = false;
         cerr<<"You did not enter a number...\n"; 
       } 
if(conversion)
{
  for(int i=0 ; i<students.size() ; i++)
  {
    if(id == students[i]->getStudentId())
    { 
     switch (students[i]->whatIsYourLevel())
     {
     case Student::LevelOfStudy::Ug :

       if(students[i]->getListOfModules().size() < 4)
       {
         cout<<"Please enter module's code:"<<endl;
         cin>>moduleCode;
         for(string alreadyEnrolled :students[i]->getListOfModules())
         {
           if(moduleCode == alreadyEnrolled)
           { alreadyForUg = true;
             cout<<"You have already enrolled in this module"<<endl;
             break;
           }
         }
         if(!alreadyForUg){students[i]->enrol(moduleCode);}
       
       cout<<"*** Enrolment Successfully done ***"<<endl;
       }
       else if(students[i]->getListOfModules().size() >= 4)
       {cout<<"You have reached the limit-number of modules for this semester"<<endl;}
       break;

     case Student::LevelOfStudy::MSc :
     if(students[i]->getListOfModules().size() < 3)
     {
         cout<<"Please enter module's code:"<<endl;
         cin>>moduleCode;
         for(string alreadyEnrolled : students[i]->getListOfModules())
         {
           if(alreadyEnrolled == moduleCode)
           {
              alreadyForMSc = true;
              cout<<"You have already enrolled in this module"<<endl;
              break;
           }
         }
         if(!alreadyForMSc) {students[i]->enrol(moduleCode);}
     }
     else if(students[i]->getListOfModules().size() >= 3)
     {cout<<"You have reached the limit-number of modules for this semester"<<endl;}
      
       break;
      
     case Student::LevelOfStudy::PhD :

       cout<<"Please enter module's code:"<<endl;
         cin>>moduleCode;
         for(string alreadyEnrolled : students[i]->getListOfModules())
         {
           if(alreadyEnrolled == moduleCode)
           {
              alreadyForPhD = true;
              cout<<"You have already enrolled in this module"<<endl;
              break;
           }
         }
         if(!alreadyForPhD) {students[i]->enrol(moduleCode);}
       
       break;
     }


     found = true;
     break;
    }
  }
  if(!found)
  cout<<" Student Id could not be found in the system"<<endl;
}
} 


void StudentRegistration::findStudentsByType()
{
  int type;
  cout<<"Please enter the type of the students(1,2 , or 3)"<<endl;
  cout<<"1- Undergraduate Students"<<"\n"<<"2- Master's Students"<<"\n"<<"3- PhD Students"<<endl;
  while(type !=1 && type !=2 && type !=3)
  {
    cin>>type;
    if(type ==1 || type ==2 || type ==3)
    break;
    else
    {
      cin.clear();
      cin.ignore(1000 , '\n');
      cout<<"Please enter a number between 1 and 3"<<endl;
    } 
  }
  Student::LevelOfStudy studentLevel = static_cast<Student::LevelOfStudy>(type);
  vector<Student*> newListOfStudents;
  for(Student* student:students)
  {
    if(student->whatIsYourLevel() == studentLevel)
    {
      newListOfStudents.push_back(student);
    }
  }
  
  if(newListOfStudents.size() != 0)
  {
     for(int i=0 ; i<newListOfStudents.size() ; i++)
   {
    if(studentLevel == Student::LevelOfStudy::Ug)
    { cout<<i+1<<"- "; (dynamic_cast<Ug*>(newListOfStudents[i]))->displayStudents(); cout<<"\n";}

    else if(studentLevel == Student::LevelOfStudy::MSc)
    { cout<<i+1<<"- "; (dynamic_cast<MSc*>(newListOfStudents[i]))->displayStudents(); cout<<"\n";}

    else if(studentLevel == Student::LevelOfStudy::PhD)
    {cout<<i+1<<"- "; (dynamic_cast<PhD*>(newListOfStudents[i]))->displayStudents(); cout<<"\n";}
   }
  }
  else cout<<"No students of this level exist in the system"<<endl;
}

void StudentRegistration::findStudentsByModulesEnrolled()
{
  bool studentFound = false;
  string moduleCode;
  vector<Student*> studentsEnrolled;

  cout<<"Enter a module code to search for all students enrolled in it:"<<endl;
  cin>>moduleCode;

  for(Student* student:students)
  {
    for(string module :student->getListOfModules())
    {
      if(module == moduleCode)
      {
        studentFound = true;
        studentsEnrolled.push_back(student);
      }
    }
  }
  if(studentFound)
  {
    for(int i=0 ; i<studentsEnrolled.size();i++)
    {
      if(studentsEnrolled[i]->whatIsYourLevel() == Student::LevelOfStudy::Ug)
      {
        cout<<i+1<<"- ";
        (dynamic_cast<Ug*>(studentsEnrolled[i]))->displayStudents();
        cout<<"\n";
      }

      else if(studentsEnrolled[i]->whatIsYourLevel() == Student::LevelOfStudy::MSc)
      {
        cout<<i+1<<"- ";
        (dynamic_cast<MSc*>(studentsEnrolled[i])) -> displayStudents(); 
        cout<<"\n";  
      }

      else if(studentsEnrolled[i]->whatIsYourLevel() ==  Student::LevelOfStudy::PhD)
      {
        cout<<i+1<<"- ";
        (dynamic_cast<PhD*>(studentsEnrolled[i]))->displayStudents();
        cout<<"\n";
      }
    }
  }
  else if(!studentFound)
  { cout<<"No students could found for this module-Module code does not exist"<<endl;}
  
}

void StudentRegistration::searchMasterStudentsByDepartment()
{
  string department;
  bool departmentFound = false;
  vector<Student*> allMasterStudents;
  vector<string> allMasterDepartments;
  vector<Student*> mastersWithSameDepartment;

  for(Student* master:students)
  {
    if(master->whatIsYourLevel() == Student::LevelOfStudy::MSc)
    { allMasterStudents.push_back(master);}
  }

  cout<<"Please enter the name of the department(CS , EE , Maths , Psycho):"<<endl;
  while (department != "CS" && department != "EE" && department != "Maths" && department != "Psycho")
  {
    cin>>department;
    if(department =="CS" || department =="EE" || department =="Maths" || department == "Psycho")
    break;
    else cout<<"Please enter a valid department"<<endl;
  }

  for(Student* ms:allMasterStudents)
  {
    if(ms->getDepartment() == department)
    {
      departmentFound = true;
      break;
    }
  }

  if(!departmentFound)
  {cout<<"No Master's students could be found in this department"<<endl;}

  else if(departmentFound)
  {
    for(Student* master : allMasterStudents)
    {
      if(master->getDepartment() == department)
      {mastersWithSameDepartment.push_back(master);}
    }

    cout<<"All master's students in "<<department<<" are :"<<endl;
    for(int i=0 ; i<mastersWithSameDepartment.size() ; i++)
    {
      cout<<i+1<<"- ";
      (dynamic_cast<MSc*>(mastersWithSameDepartment[i]))->displayStudents();
      cout<<"\n";
    }

    cout<<"***Searching master's students by department successfully ended.***"<<endl;
  }

}

void StudentRegistration::searchUndergardStudentsByAdvisor()
{
  string advisorName;
  bool advisorFound = false;
  vector<Student*> allUndergaduates;
  vector<string> allUndergarduateAdvisors;
  vector<Student*> undergradsWithSameAdvisor;
  
  for(Student* undegraduate :students)
  {
    if(undegraduate->whatIsYourLevel() == Student::LevelOfStudy::Ug)
    allUndergaduates.push_back(undegraduate);
  }

cout<<"Please enter advisor's name:"<<endl;
cin>>advisorName;

  for(Student* ug :allUndergaduates)
 {
  if(ug->getAdvisor() == advisorName)
  {
    advisorFound=true;
    break;
  }
 }

 if(!advisorFound)
 {cout<<"Advisor name couldn't be found for undergraduate students"<<endl; }

 else if(advisorFound)
 {
   cout<<"Undergraduate students advised by "<<advisorName<<" are: "<<endl;
   for(Student* undergrad:allUndergaduates)
   {
      if(undergrad->getAdvisor() == advisorName)
      undergradsWithSameAdvisor.push_back(undergrad);
   }

   for(int i=0 ; i<undergradsWithSameAdvisor.size() ; i++)
  {
    cout<<i+1<<"- ";
   (dynamic_cast<Ug*>(undergradsWithSameAdvisor[i]))->displayStudents();
   cout<<"\n";
  }

  cout<<"***Searching undergraduates by advisor successfully ended. ***"<<endl;
 }
}



