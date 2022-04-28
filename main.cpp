#include"student.h"
#include"roster.h"
#include"degree.h"
#include <iostream>
using namespace std;


int main() {

    //   F1. PRINT OUT SHWETHA'S DETAILS

    cout << "Course: C867 Scripting and Programming - Applications\n" 
         << "Language: C++\n" 
         << "ID: 009620095\n"
         << "Name: Shwetha Mettakadapa" << endl<<endl<<endl;

   const std::string studentData[] = { "A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",

        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
         
        "A5,Shwetha,Mett,shwethamett@wgu.edu,27,14,20,25,SOFTWARE"};



    const int studentsCount = 5;

    

       // F2 . Create an instance of class object called classRoster

    Roster classRoster;

    // F3. ADD EACH STUDENT TO CLASSROSTER INSTANCE

    for (int i = 0; i < studentsCount; i++)
        classRoster.ParseClassRosterArray(studentData[i]);

    ///////////F4///////////////////////////////


    // Printing all Students in the Class Roster Array

    classRoster.PrintAll();



    // Checking and displaying Invalid Emails
 
    classRoster.PrintInvalidEmails();

    
    //Printing Average Days in Course

    cout << endl;

    for (int i = 0; i < studentsCount ; i++)
    {
        classRoster.PrintAverageDaysInCourse(classRoster.RosterArray[i]->get_student_ID());
    }

  
    // Showing Students by Degree Program

    cout << endl;
    cout << "SHOWING STUDENTS IN DEGREE PROGRAM : SOFTWARE" << endl;
    cout << endl;
    classRoster.PrintByDegreeProgram(DegreeProgramEnum::SOFTWARE);
    cout << endl;


    // REMOVE student by ID

    classRoster.Remove("A3");

    classRoster.Remove("A3");



	return 0;
}

