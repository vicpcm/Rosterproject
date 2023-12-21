#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

//Constructor
Student::Student() {
	//initializing variables 
	this->sID = "";
	this->fN = "";
	this->lN = "";
	this->email = "";
	this->age = 0;
	this->amountOfDays[0] = 0;
	this->amountOfDays[1] = 0;
	this->amountOfDays[2] = 0;
	this->degree = SECURITY;
}
//constructor (parameters)
Student::Student(string studentID, string firstName, string lastName, string emailAddress, 
	int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp) 
{
	//these initialize variables as well 
	this->sID = studentID;
	this->fN = firstName;
	this->lN = lastName;
	this->email = emailAddress;
	this->age = studentAge;
	this->amountOfDays[0] = daysInCourse1;
	this->amountOfDays[1] = daysInCourse2;
	this->amountOfDays[2] = daysInCourse3;
	this->degree = dp;
}

//this section utilizes the getters
string Student::getStudentID() { return sID; }
string Student::getFirstName() { return fN; }
string Student::getLastName() { return lN; }
string Student::getEmailAddress() { return email; }
int Student::getStudentAge() {return age; }
int Student::getDays1() { return amountOfDays[0]; }
int Student::getDays2() { return amountOfDays[1]; }
int Student::getDays3() { return amountOfDays[2]; }
DegreeProgram Student::getDegreeProgram() { return degree; }


// Implementation of setters for student class
void Student::SetStudentID(string studentID) {sID = studentID;}

void Student::SetStudentFirstName(string firstName) {fN = firstName;}

void Student::SetStudentLastName(string lastName) {lN = lastName;}

void Student::SetStudentEmailAddress(string emailAddress) {email = emailAddress;}

void Student::SetStudentAge(int studentAge) {age = studentAge;}

void Student::SetDays1(int daysInCourse1) {amountOfDays[0] = daysInCourse1;}

void Student::SetDays2(int daysInCourse2) {amountOfDays[1] = daysInCourse2;}

void Student::SetDays3(int daysInCourse3) {amountOfDays[2] = daysInCourse3;}

void Student::SetDegreeProgram(DegreeProgram dp) {degree = dp;}

//this function will display all the information
void Student::print() {
	cout << sID;
	cout << "	First Name: " << fN;
	cout << "	Last Name: " << lN;
	cout << "	Age: " << age;
	cout << "	Days In Course: (" << amountOfDays[0] << "," << amountOfDays[1] << "," << amountOfDays[2] << ")";
	cout << "	Degree Program: " << DegreeProgramString[degree] << endl;

}
