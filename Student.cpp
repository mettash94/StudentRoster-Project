#include "Student.h"
#include "degree.h"
#include <iostream>
using namespace std;


//   DEFAULT EMPTY CONSTRUCTOR

Student::Student() {

	cout << "Hey you've created an object of the class Student";

	this->student_ID = "";

	this->first_name = "";

	this->last_name = "";

	this->email_address = "";

	this->age = 0;

	for (int i = 0; i < 3; i++)
		this->days_array[i] = 0;

	this->course = DegreeProgramEnum::SECURITY;

	

}

//    CONSTRUCTOR DEFINITION

Student::Student(
	std::string student_ID,
	std::string first_name,
	std::string last_name,
	std::string email_address,
	int age,
	int days_array[],
	DegreeProgramEnum course)

{
	this->student_ID = student_ID;

	this->first_name = first_name;

	this->last_name = last_name;

	this->email_address = email_address;

	this->age = age;

	this->course = course;

	for (int i = 0; i < 3; i++)
		this->days_array[i] = days_array[i];

}

//      DESTRUCTOR

Student::~Student() {};

//             PRINT FUNCTION DEFINITION


void Student::print() {
	
	
	cout << this->get_student_ID() << "  " " "<< '\t';
	cout << this->get_first_name() << '\t';
	cout << this->get_last_name() << '\t';
	cout << this->get_email_address() << '\t';
	cout << this->get_age() << '\t';

	cout << this->get_days_array()[0] << ',';
	cout << this->get_days_array()[1] << ',';
	cout << this->get_days_array()[2] << '\t';

	if (course == DegreeProgramEnum::SECURITY) cout << "SECURITY" << '\n';
	else if (course == DegreeProgramEnum::NETWORK) cout << "NETWORK" << '\n';
	else if (course == DegreeProgramEnum::SOFTWARE) cout << "SOFTWARE" << '\n';

	

}




//     GETTERS

string Student::get_student_ID() {
	return this->student_ID;

}

string Student::get_first_name() {
	return this->first_name;
}

string Student::get_last_name() {
	return this->last_name;
}

string Student::get_email_address() {
	return this->email_address;
}

int Student::get_age() {
	return this->age;

}

int* Student::get_days_array() {
	return this->days_array;

};

DegreeProgramEnum Student::get_course() {
	return this->course;
}



 
//          SETTERS

void Student::set_student_ID(int ID) {
	student_ID = ID;
}

void Student::set_first_name(string f_name) {
	first_name = f_name;
}

void Student::set_last_name(string l_name) {
	last_name = l_name;
}

void Student::set_email_address(string email_id) {
	email_address = email_id;
}

void Student::set_age(int student_age) {
	age = student_age;
}

void Student::set_days_array(int days_arr[]) {

	for (int i = 0; i < 3; i++)
		this->days_array[i] = days_arr[i];

}

void Student::set_degree(DegreeProgramEnum course) {
	this->course = course;
}

