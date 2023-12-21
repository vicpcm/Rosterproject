#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {

private: //private variables used to restrict access from the public class so it does not manipulate it.
	string sID; //student ID
	string fN; //first name 
	string lN; // last name
	string email; // email address
	int age; //age
	int amountOfDays[3]; //the amount of days each student takes courses
	DegreeProgram degree;

public: //public variables define interface and the external code uses it.
	//constructors
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, 
		    int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		    DegreeProgram dp);
	void print(); 

	//accesor, getters which will retrieve values of private variables
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int getDays1();
	int getDays2();
	int getDays3();
	DegreeProgram getDegreeProgram();

	//mutator, setters modify the values of private variables
	void SetStudentID(string studentID);
	void SetStudentFirstName(string firstName);
	void SetStudentLastName(string lastName);
	void SetStudentEmailAddress(string emailAddress);
	void SetStudentAge(int studentAge);
	void SetDays1(int daysInCourse1);
	void SetDays2(int daysInCourse2);
	void SetDays3(int daysInCourse3);
	void SetDegreeProgram(DegreeProgram dp);


};