#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
    Student s1;
    
    s1.setName();
    s1.setCourses();
    s1.setHours();
    s1.setGrades();
    s1.setGpa();

    s1.Print();
           
}

