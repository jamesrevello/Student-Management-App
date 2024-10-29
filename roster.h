#pragma once
#include "student.h"


class Roster 
{
public:
	Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

	int studentIndex = -1;


	//Public Members
	void parse(string studentData);
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram
		);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//destructor
	~Roster();

	
	
private:
};

