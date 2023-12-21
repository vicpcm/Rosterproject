#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {

	cout << "\t\t\t\t\tScripting and programming applications (C867)" << endl;
	cout << "\t\t\t\t\t\tVictoria Paulina Koletsos" << endl;
	cout << "\t\t\t\t\t\tStudent ID: 011062763" << endl;
	cout << "\t\t\t\t\t\t\tC++\n" << endl;
	
	const string studentDataTable[] =
	{
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Victoria,Koletsos,vkolets@wgu.edu,24,35,62,5,SOFTWARE"
	};

	// creates roster object
	Roster classRoster;

	//parses "student" data to be added to the file "roster" 
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentDataTable[i]);
	}

	classRoster.printAll(); cout << endl; 

	classRoster.printInvalidEmails(); cout << endl; 

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getStudentID(i)); } cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE); cout << endl;

	classRoster.removeStudentByID("A3");cout << endl; //removes student with "A3" ID

	classRoster.printAll(); cout << endl; //prints all the current students after the A3 student was removed from the list.

	classRoster.removeStudentByID("A3"); //confirming it was removed

	return 0;
}
   