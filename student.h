#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {
public:
	//Constructors
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse[],
		DegreeProgram degreeProgram
		);
	//Destructor
	~Student();
	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();
	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	//Student print
	void print();
private:
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age = 0;
	int daysInCourse[3] = { 0, 0, 0 };
	DegreeProgram degreeProgram = SOFTWARE;
};