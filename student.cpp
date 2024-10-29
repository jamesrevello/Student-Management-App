#include "Student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; ++i) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

//Constructor def
Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse[],
	DegreeProgram degreeProgram
) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i) { this->daysInCourse[i] = daysInCourse[i]; }
	this->degreeProgram = degreeProgram;
}

//Destructor def
Student::~Student() {}

//Getter function defs
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return  this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setter function defs
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) { for (int i = 0; i < 3; ++i) { this->daysInCourse[i] = daysInCourse[i]; } }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Print function def
void Student::print() {
	cout << "ID: " << this->getStudentID() << '\t';
	cout << "First: " << this->getFirstName() << '\t';
	cout << "Last: " << this->getLastName() << '\t';
	cout << "Email: " << this->getEmailAddress() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "DaysInCourse: {" << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << "}" << '\t';
	cout << "Program: " << degreeProgramConvert[this->getDegreeProgram()] << endl;

	return;
}
