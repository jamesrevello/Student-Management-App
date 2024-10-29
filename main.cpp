#include "Roster.h"
#include "student.h"


int main() {

	cout << "*********************************************************" << endl << endl;
	cout << "Course Title | C867-Scripting & Programming: Applications" << endl;
	cout << "Written With | Visual Studio C++" << endl;
	cout << "Written By   | James Revello" << endl;
	cout << "Student ID   | 010649181" << endl;
	cout << "*********************************************************" << endl;
	cout << endl;


	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,James,Revello,jamesreve@gmail.com,23,53,30,55,SOFTWARE"
	};

	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid email addresses: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Displaying average days in course: " << endl;
	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Displaying degree type: SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	


	cout << "Removing student A3: " << endl << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Removing student A3: " << endl;
	classRoster.remove("A3");


	return 0;
}