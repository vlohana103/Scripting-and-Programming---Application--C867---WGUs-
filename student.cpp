#include <iostream>
#include <string>

#include "student.h"

using namespace std;


// D1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables: student ID, 
// first name, last name, email address, age, array of number of days to complete each course, degree program

Student::Student() { //default constructor
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		daysOfCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int dayInCourse1, int dayInCourse2, int dayInCourse3, DegreeProgram degreeProgram) { // parameter constructor

	this->studentID=studentID;
	this->firstName=firstName;
	this->lastName=lastName;
	this->emailAddress=emailAddress;
	this->age=age;
	daysOfCourse[0] = dayInCourse1;
	daysOfCourse[1] = dayInCourse2;
	daysOfCourse[2] = dayInCourse3;
	this->degreeProgram = degreeProgram;

}

Student::~Student() {
	cout << "student " << studentID << " destroyed" << endl;
};

/* D2. Create each of the following functions in the Student class : an accessor(i.e., getter) for each instance variable from part D1,
	 a mutator (i.e., setter) for each instance variable from part D1, All external access and changes to any instance variables of the
	 Student class must be done using accessor and mutator functions. Constructor using all of the input parameters provided in the table,
	print() to print specific student data */

string Student::getStudentID() {
	return studentID;
}

void Student::setStudentID(string studentID) {
	studentID = studentID;
}

string Student::getFirstName() {
	return firstName;
}

void Student::setFirstName(string firstName) {
	firstName = firstName;
}

string Student::getLastName() {
	return lastName;
}

void Student::setLastName(string lastName){
	lastName = lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

void Student::setEmailAddress(string emailAddress) {
	emailAddress = emailAddress;
}

int Student::getAge() {
	return age;
}

void Student::setAge(int age) {
	age = age;
}


const int* Student::getDaysOfCourse() {
	return daysOfCourse;
}

void Student::setDaysOfCourse(const int daysCourse[]){
	for (int i = 0; i < 3; ++i)
		daysOfCourse[i] = daysCourse[i];
}


DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	degreeProgram = degreeProgram;
}


void Student::print() {
	string degree_string;
	if (degreeProgram == DegreeProgram::SECURITY) {
		degree_string = "Security";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		degree_string = "Network";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		degree_string = "Software";
	}

	cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << emailAddress << "\t" << age << "\t" << daysOfCourse[0] << ", " << daysOfCourse[1] << ", " << daysOfCourse[2] << "\t" << degree_string << endl;
}