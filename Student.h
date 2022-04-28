#pragma once
#include<iostream>
using namespace std;
#include"degree.h"

///            FOLLOWING DR.KRYPTO

class Student

{
public:
	//Array size is constant

	const static int Array_size = 3;

private:

	string student_ID;
	string first_name;
	string last_name;
	string email_address;
	int age;
	int days_array[Array_size];
	DegreeProgramEnum course;

public:


	//Constructor

	//1.Paramaterless Constructor

	Student();
	
     //2. Constructor with paramters Student(string, string, string, string, in);

	Student(
		string student_ID, 
		string first_name,
		string last_name,
		string email_address, 
		int age, 
		int days_array[],
		DegreeProgramEnum course);

	// 3. Destructor

	~Student();


	//  4. static method print()

	void print();

	//5. print header

	//void  printHeader();

	//   Getters

	string get_student_ID();
	string get_first_name();
	string get_last_name();
	string get_email_address();
	int get_age();

	int* get_days_array(); //RETURN AS A POINTER

	DegreeProgramEnum get_course();


	//  Setters

	void set_student_ID(int ID);
	void set_first_name(string f_name);
	void set_last_name(string l_name);
	void set_email_address(string email_id);
	void set_age(int student_age);
	
	void set_days_array(int days_arr[]);   //SEND IT IN AS AN ARRAY

	void set_degree(DegreeProgramEnum course);

	
};

