#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
using std::string;
using std::vector;


class Student
{
private:
static int studentGlobalId;

protected:
    int studentID;
    string name;
    string surname;
    string address;
    string department;
    string advisor;
    vector<string> modules;
    int yearOfStudy;
    
public:
    
    enum TuitionFeeStatus {home = 1 , eu = 2  , international = 3};
    TuitionFeeStatus fee;
    enum LevelOfStudy {Ug=1 , MSc=2 , PhD=3};
    
    Student(int studentID , string name, string surname,string address, string department,
    string advisor,TuitionFeeStatus feeStatus , int yearOfStudy);

    string getName();
    string getSurname();
    string getAddress();
    string getDepartment();
    int getStudentId();
    string getAdvisor();
    virtual int calculateTuitionFee()=0;
    void enrol(string moduleCode);
    virtual void displayStudents()=0;
    static int generateUniqueID(); 
    virtual LevelOfStudy whatIsYourLevel()=0;
    TuitionFeeStatus getFeeStatus();
    virtual int getYearOfStudy()=0;
    vector<string>& getListOfModules();
    string feeStatusString();
};



#endif
