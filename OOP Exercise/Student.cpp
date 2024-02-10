#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Student::setName() {
	cout << "What is the student's name?" << endl;
	getline(cin, studentName);
	}

string Student::getName() {
	return studentName;
}


void Student::setCourses() {
	cout << endl << "How many courses did " << studentName << " take?" << endl;
	cin >> courses;
	cin.ignore();
}

int Student::getCourses() {
	return courses;
}


void Student::setHours() {
	hours = new int[courses];
	cout << endl;
	if (courses > 0) {
		for (int i = 0; i < courses; i++) {
			cout << "How many hours in course " << i + 1 << "?" << endl;
			cin >> hours[i];
			cin.ignore();
		}
	}
}

int Student::getHours() {
	int sum = 0;
	for (int i = 0; i < courses; i++) {
		 sum = sum + hours[i];
	}
	return sum;
}

void Student::setGrades() {
	grade = new char[courses];
	cout << endl;
	for (int i = 0; i < courses; i++) {
		cout << "Letter grade for Course " << i + 1 << ": " << endl;
		cin.get(grade[i]);
		cin.ignore();
	}
}

string Student::getGrades() {	
	string gradeArray;
	for (int i = 0; i < courses; i++) {
		gradeArray += grade[i];
		gradeArray.append(" ");
	}
	return gradeArray;
}

void Student::setGpa() {
	float sumGrade = 0;                                                             
	float hourTotal = 0;
	for (int i = 0; i < courses; i++) {
		sumGrade = sumGrade + (gradePoints(grade[i]) * hours[i]);                  
	}                                                                               
	for (int i = 0; i < courses; i++) {
		hourTotal = hourTotal + hours[i];                                           
	}	
	Gpa = sumGrade / hourTotal;
}

double Student::getGpa() {
	return Gpa;
}


void Student::Print() {
	cout << endl;
	cout << "Student name is " << studentName << endl;
	cout << studentName << " took " << courses << " courses." << endl;
	cout << "There were " << getHours() << " total hours of classes." << endl;
	cout << "Letter grades for courses were: " << getGrades() << endl;
	cout << "Gpa is: " <<setprecision(3)<< getGpa() << endl;
}

float Student::gradePoints(const char grade) {                                               
	if (grade == 'A') {                                                              
		return 4.0;                                                                 
	}
	else if (grade == 'B') {
		return 3.0;
	}
	else if (grade == 'C') {
		return 2.0;
	}
	else if (grade == 'D') {
		return 1.0;
	}
	else if (grade == 'F') {
		return 0.0;
	}
}