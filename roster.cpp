#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

//void Add(string student_ID, string first_name, string last_name, string email_address, int age,
//    int daysInCourse1,
//    int daysInCourse2,
//    int daysInCourse3,
//    DegreeProgramEnum course)
//{
//    int DAYSARRAY[3] = { daysInCourse1,daysInCourse2, daysInCourse3 };
//};

Roster::Roster() {

}
void Roster::Add(string student_ID, string first_name, string last_name, string email_address, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgramEnum course) 
{
    int daysArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    RosterArray[++last_index] = new Student(student_ID, first_name, last_name, email_address, age, daysArray, course);
    
}
void Roster::ParseClassRosterArray(string data)


{
    string ch;
    string studentID, studentFName, studentLName, studentEmail;
    int studentAge=0, daysArray1=0, daysArray2=0, daysArray3=0;
    DegreeProgramEnum degreeType = DegreeProgramEnum::SECURITY;
    int count = 0;
    for (auto x : data) {
        if (x == ',') {
            if (count == 0)  studentID = ch;
            else if (count == 1)  studentFName = ch;
            else if (count == 2)  studentLName = ch;
            else if (count == 3)  studentEmail = ch;
            else if (count == 4)  studentAge = stoi(ch); //stoi converts "23" to 23
            else if (count == 5)  daysArray1 = stoi(ch);
            else if (count == 6)  daysArray2 = stoi(ch);
            else if (count == 7)  daysArray3 = stoi(ch);
            count++;
            ch = "";
        }
        else {
            ch = ch + x;
        }
    }
    
    if (count == 8) {
        if (ch == "SECURITY") degreeType = DegreeProgramEnum::SECURITY;
        if (ch == "NETWORK") degreeType = DegreeProgramEnum::NETWORK;
        if (ch == "SOFTWARE") degreeType = DegreeProgramEnum::SOFTWARE;
    }

    Add(studentID, studentFName, studentLName, studentEmail, studentAge, daysArray1, daysArray2, daysArray3, degreeType);

}


//        PrintAll() prints tab seperated list of student data

void Roster::PrintAll() {

    printHeader();

    for (int i = 0; i <= Roster::last_index; i++) Roster::RosterArray[i]->print();
};


                  
void Roster::PrintAverageDaysInCourse(string student_ID) {

   

    for (int i = 0; i <= Roster::last_index; i++)
    {
        if (RosterArray[i]-> get_student_ID() == student_ID)
        {
            cout<<"Student ID : " << student_ID << " Average Days in Course is ";
            cout << (RosterArray[i]->get_days_array()[0] +
                RosterArray[i]->get_days_array()[1] +
                RosterArray[i]->get_days_array()[2]) / (Student::Array_size) << endl; // Array size is 3
            //divide by number of course day counts
        }
    }

}



void Roster:: PrintByDegreeProgram(DegreeProgramEnum course) {

    printHeader();

    

    for (int i = 0; i <= Roster::last_index; i++) {

        if (Roster::RosterArray[i]->get_course() == course)
            RosterArray[i]->print();
    }
    
}

//         ID CANNOT HAVE A SPACE. SHOULD HAVE @ AND .(PERIOD)
//              DISPLAY INVALID EMAIL TO USER

void Roster::PrintInvalidEmails() {

    cout << "" << endl;
    cout << "Displaying invalid emails:" << endl << endl;

    for (int i = 0; i <= Roster::last_index; i++) {

        string checkEmail = Roster::RosterArray[i]->get_email_address();

        if (checkEmail.find(' ') != string::npos || checkEmail.find('.') == string::npos || checkEmail.find('@') == string::npos)

            cout << checkEmail << " - is invalid" << endl;
    }
}


//              REMOVE STUDENT


void Roster::Remove(string studentID) {

    int studentCount = 5;
    
    bool state = false;

    for (int i = 0; i <= Roster::last_index; i++) {
        if (RosterArray[i]->get_student_ID() == studentID)
        {

            state = true;

            Student* temp = RosterArray[i]; //swaps places

            RosterArray[i] = RosterArray[studentCount - 1];

            RosterArray[studentCount - 1] = temp;

            Roster::last_index--;

        }

        
    }

    if (state)
    {
        cout << " Removing A3 " << endl;

        PrintAll();
    }
    else {
        cout << endl;
        cout << "Removing A3 Again" << endl;
        cout << endl;
        cout<< "Student is not found" << endl;
    }

}

//              PRINT HEADER
 void Roster::printHeader() {
    cout << "ID" << '\t' << "FName " << '\t' << "LName " << '\t' << "      Email Address " << '\t' << "Age" << '\t' << "DaysInCourse" << '\t' << "Degree Program" << endl;//format of printout

}

 //               DESTRUCTOR

 Roster::~Roster() {

     int studentCount = 5;

     cout << endl;

     cout << "DESCTRUCTOR CALLED TO RELEASE DYNAMICALLY ALLOCATED MEMORY " << endl;

     for (int i = 0; i < studentCount; i++)
         //size of numBooks stays the same unlike lastIndex
     {
         
         delete RosterArray[i];
         RosterArray[i] = nullptr;
         //set to nullptr so it is no longer pointed at that address otherwise could crash
     }

}