#pragma once
#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	//adds students to the roster
	void add(string studentid, string firstname, string lastname, string emailaddress, int age, 
		int dCourse1, int dCourse2, int dCourse3, DegreeProgram degreeprogram);
	void removeStudentByID(string studentid); //removes student by ID
	void printAll();
	void printAverageDaysInCourse(string studentid); //prints the average of days that each student spends on the courses
	void printInvalidEmails(); //prints invalid emails depending on the variables that are considered invalid
	void parse(string studentDataTable); //parses the string of the "student" data and adds it to the roster
	void printByDegreeProgram(DegreeProgram); //prints details of students with a specific major
	string getStudentID(int spotOnRoster); //it gives specific locations to the student IDs on the roster file
	~Roster(); //destructor


};