#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

int main() {

	//A.  Modify the “studentData Table” to include your personal information as the last item.

	const string studentData[] =
	{	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Vikas,Lohana,vlohan1@wgu.edu,26,20,30,40,SOFTWARE" };
	//F1.
	cout << "Course Title: Scripting and Programming - Applications - C867, Language used: C++, Student ID: 010138181, Name: Vikas Lohana\n";
	
	
	// F2. changed myRoster to classRoster
	Roster classRoster;
	for (int i = 0; i < 5; i++) {
		 classRoster.parse(studentData[i]); //F3
	}

	//F4
	classRoster.printAll();
	cout << endl;
	
	classRoster.printInvalidEmails();
	cout << endl;

	
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE); 
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3");
	cout << endl;
	


	return 0;
}