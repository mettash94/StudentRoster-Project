#pragma once

#include "degree.h"
#include "student.h"
#include <string>
using std::string;

//      

class Roster
{
private:

    // To incrementally add to roster
    int last_index = -1;


    //   Array size. 5 students total
    static const int total_num_students = 5;


public:

    //   Constructor Parameterless

    Roster();


    //   Declaring array of pointers. No students yet so nullptr

    Student* RosterArray[total_num_students] =
    { nullptr, nullptr, nullptr, nullptr, nullptr };


    //   Define the following functions

    //Add() sets the instance variables from D1 and updates the roster

    void Add(string student_ID,string first_name,string last_name,string email_address,int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgramEnum course );


    // Parses each set of data identified in the student record

    void ParseClassRosterArray(string data);


    // Remove() removes students from the roster by Student_ID

    void Remove(string studentID);


    // PrintAll() prints tab seperated list of student data

    void PrintAll();


    // PrintAverageDaysInCourse() prints students average number of days from three courses is identified by studentID

    void PrintAverageDaysInCourse(string student_ID);


    // PrintInvalidEmails

    void PrintInvalidEmails();


    // PrintBydegreeProgram prints out student info for a degree program specified by enum type

    void PrintByDegreeProgram(DegreeProgramEnum course);

    void printHeader();

    // DESTRUCTOR
    
    ~Roster();
};