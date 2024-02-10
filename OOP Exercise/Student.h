#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

using namespace std;

class Student {

private:
	string studentName;
	char* grade;
	int courses;
	int* hours;
	double Gpa;

public:

	void setName();
	string getName();

	void setCourses();
	int getCourses();

	void setHours();
	int getHours();

	void setGrades();
	string getGrades();

	void setGpa();
	double getGpa();

	void Print();

	float gradePoints(const char grade);

};


#endif