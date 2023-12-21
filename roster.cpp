#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

void Roster::parse(string studentDataTable) { // this is the function that does all the work to parse the string of students and add it to the "roster" file.
	//student ID
	int numberOne = studentDataTable.find(','); 
	string ID = studentDataTable.substr(0, numberOne); 
	//first Name
	int numberTwo = numberOne + 1; 
	int numberThree = studentDataTable.find(',', numberTwo);
	string firstN = studentDataTable.substr(numberTwo, numberThree - numberTwo); 
	//last name
	numberTwo = numberThree + 1; 
	numberThree = studentDataTable.find(',', numberTwo);
	string lastN = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	//email address
	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string emAddress = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	//age using integer 
	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string strAge = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	int iAge = stoi(strAge); 
	//number of courses using integer for all the three variables
	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string strC1 = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	int intC1 = stoi(strC1);

	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string strC2 = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	int intC2 = stoi(strC2);

	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string strC3 = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	int intC3 = stoi(strC3);
	//degree program
	numberTwo = numberThree + 1;
	numberThree = studentDataTable.find(',', numberTwo);
	string strDegreeP = studentDataTable.substr(numberTwo, numberThree - numberTwo);
	DegreeProgram dp; 
	if (strDegreeP == "SECURITY") {
		dp = SECURITY;
	}
	else if (strDegreeP == "NETWORK") {
		dp = NETWORK;
	}
	else {
		dp = SOFTWARE;
	}
	add(ID, firstN, lastN, emAddress, iAge, intC1, intC2, intC3, dp);
}

void Roster::add(string studentid, string firstname, string lastname, string emailaddress, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degreeprogram) {
	classRosterArray[++Roster::lastIndex] = new Student(studentid, firstname, lastname, emailaddress, age, dCourse1, dCourse2, dCourse3, degreeprogram);
}

void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}
//removes student by ID depending on which one is chosen 
void Roster::removeStudentByID(string studentID) {
	bool studentR = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			if (i < Roster::lastIndex) {
				Student* tempStudent = classRosterArray[Roster::lastIndex];
				classRosterArray[Roster::lastIndex] = classRosterArray[i];
				classRosterArray[i] = tempStudent;
				studentR = true;
			}
			Roster::lastIndex--; //keeps track of the index on the last element of the array it returns the value of the variable (decrements by 1)
		}
	}
	if (!studentR) { //student that was removed from the list
		cout << "Student ID -" << studentID << "- not found." << endl;
	}
	else
	{
		cout << "Student ID -" << studentID << "- was removed." << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) { //calculation of the average days that it takes to finish courses.
	cout << "Average days in courses: " << endl;
	{int numofcourses = 3; int averageDays; int i = 0;

	while (classRosterArray[i]->getStudentID() != studentID) {
		i++;
	}
	averageDays = (classRosterArray[i]->getDays1() + classRosterArray[i]->getDays2() + classRosterArray[i]->getDays3()) / numofcourses;
	cout << classRosterArray[i]->getStudentID() << ", " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ": " << averageDays << " days." << endl;
	}
}

void Roster::printInvalidEmails() { //here I added the reasons why the email could be invalid: if it doesn't include @ or ., or if it has spaces on it.
	bool correctEmailAddress = true; cout << "List of invalid emails: " << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string emailaddress = classRosterArray[i]->getEmailAddress();
		if (emailaddress.find('@') == string::npos || emailaddress.find('.') == string::npos ||  emailaddress.find(' ') != string::npos) {
			
			cout << "The email for " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " isn't valid: " << emailaddress << endl;
			correctEmailAddress = false;
		}
	}
}


void Roster::printByDegreeProgram(DegreeProgram degree) { //will print the list of students currently in the same degree program.
	string degreeProgram[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << "Current students that are studying " << degreeProgram[degree] << " " << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
}

string Roster::getStudentID(int spotOnRoster) {
	return classRosterArray[spotOnRoster]->getStudentID();
}

Roster::~Roster() //destructor
{
	cout << "\nDESTRUCTOR CALLED" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "destroying Student' ID #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}
};
