#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


/*2.  Create a student object for each student in the data table and populate classRosterArray.

a.  Parse each set of data identified in the “studentData Table.”*/
void Roster::parse(string data) {

	size_t rhs = data.find(",");
	string sID = data.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string fName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string lName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string eAdd = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int dayCourse1 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int dayCourse2 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int dayCourse3 = stoi(data.substr(lhs, rhs - lhs));


	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string degPro = data.substr(lhs, rhs - lhs);


	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (degPro == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY; 
	}
	else if (degPro == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}

	else if (degPro == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	add(sID, fName, lName, eAdd, age, dayCourse1, dayCourse2, dayCourse3, degreeProgram);


}

void Roster::add(string sID, string fName, string lName, string eAdd, int age, int dayCourse1, int dayCourse2, int dayCourse3, DegreeProgram degPro) {

	Student* stu = new Student(sID, fName, lName, eAdd, age, dayCourse1, dayCourse2, dayCourse3, degPro);
	

	/*E2.  Create a student object for each student in the data table and populate classRosterArray.
b.  Add each student object to classRosterArray. */

	classRosterArray[nextPosition] = stu;
	nextPosition += 1;
}
//F4
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr)
			classRosterArray[i]->print();
	}

}

//F5
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr)
			delete classRosterArray[i];
	}
}
//F4
void Roster::remove(string sID) {
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == sID) {

				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				return;
			}
			

		}
			cout << "Error, a student with " << sID << " was not found.";
			
}


void Roster::printAverageDaysInCourse(string sID) {
	for (int i = 0; i < 5; i++) {
		if (sID == classRosterArray[i]->getStudentID()) {
			cout << "Student's average number of days in the three courses is: " << (classRosterArray[i]->getDaysOfCourse()[0] + classRosterArray[i]->getDaysOfCourse()[1] + classRosterArray[i]->getDaysOfCourse()[2])/3 << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string eAdd = (classRosterArray[i]->getEmailAddress());
		if (eAdd.find("@") == string::npos) {
			cout << eAdd << endl;
		}
		if (eAdd.find(".") == string::npos) {
			cout << eAdd << endl;
		}
		if (eAdd.find(" ") != string::npos) {
			cout << eAdd << endl;
		}
		
		}
}

void Roster::printByDegreeProgram(DegreeProgram degPro) {
	for (int i = 0; i < 5; i++) {
		if (degPro == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->print();
		}
	}

}
