#include "Roster.h"
#include <sstream>	
#include <list>
using namespace std;

void Roster::add(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeProgram
) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++studentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::parse(string studentData) {
	DegreeProgram degreeProgram = SOFTWARE;

		stringstream ss(studentData);
		string token;

		getline(ss, token, ','); // Student ID
		string studentID = token;

		getline(ss, token, ','); // First Name
		string firstName = token;

		getline(ss, token, ','); // Last Name
		string lastName = token;

		getline(ss, token, ','); // Email Address
		string emailAddress = token;

		getline(ss, token, ','); // Age
		int age = stol(token);

		getline(ss, token, ','); // Days in Course 1
		int daysInCourse1 = stol(token);

		getline(ss, token, ','); // Days in Course 2
		int daysInCourse2 = stol(token);

		getline(ss, token, ','); // Days in Course 3
		int daysInCourse3 = stol(token);

		getline(ss, token, ','); // Degree Program
		if (token == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (token == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (token == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		add(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse1,
			daysInCourse2,
			daysInCourse3,
			degreeProgram
		);
	};

void Roster::printAll(){
	for (int i = 0; i <= Roster::studentIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::studentIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
			classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	bool flags = false;
	for (int i = 0; i <= Roster::studentIndex; ++i) {
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos) {
			flags = true;
			cout << "---" << emailAddress << ": is invalid" << endl;
		}
		else if (emailAddress.find('.') == string::npos) {
			flags = true;
			cout << "---" << emailAddress << ": is invalid" << endl;
		}
		else if (emailAddress.find(' ') != string::npos) {
			flags = true;
			cout << "---" << emailAddress << ": is invalid" << endl;
		}
	}
	if (!flags) cout << "No Invalid Emails Found." << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::studentIndex; ++i) {
		
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << studentID << ": ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
		}
	}
}

void Roster::remove(string studentID) {
	bool Present = false;
	for (int i = 0; i < Roster::studentIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			Present = true;
			if (i < 4) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[4];
				classRosterArray[4] = temp;
			}
			Roster::studentIndex--;
		}
	} 
	if (Present) {
		
		this->printAll();
		cout << endl << studentID << " removed from roster." << endl;
	}
	else
		cout << studentID << " not found." << endl << endl;
}

Roster::~Roster() {
	cout << "Destructor initiated" << endl << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Clearing Student: " << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}