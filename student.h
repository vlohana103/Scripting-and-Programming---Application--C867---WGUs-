#pragma once
#include <iostream>
#include <string>

#include "degree.h"

using std::string;

/* D1. Create the class Student in the files student.hand student.cpp, which includes each of the following variables : student ID,
 first name, last name, email address, age, array of number of days to complete each course, degree program*/

class Student {

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysOfCourse[3];
	DegreeProgram degreeProgram;

public:
	/* D2. Create each of the following functions in the Student class : an accessor(i.e., getter) for each instance variable from part D1,
	 a mutator (i.e., setter) for each instance variable from part D1, All external access and changes to any instance variables of the 
	 Student class must be done using accessor and mutator functions. Constructor using all of the input parameters provided in the table,
	print() to print specific student data */


	Student(); //No argu or defualt constructor (wgu constructor video)
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int dayInCourse1, int dayInCourse2, int dayInCourse3, DegreeProgram degreeProgram); //parameterized constructor
	~Student();

	string getStudentID();
	void setStudentID(string studentID);

	string getFirstName();
	void setFirstName(string firstName);

	string getLastName();
	void setLastName(string lastName);

	string getEmailAddress();
	void setEmailAddress(string emailAddress);

	int getAge();
	void setAge(int age);

	const int* getDaysOfCourse(); 
	void setDaysOfCourse(const int daysCourse[]);
	
	DegreeProgram getDegreeProgram();
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

};	
