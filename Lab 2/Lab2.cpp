// Programming Lab 2, created by Andrew Scott


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float Gpa(const char grades[], const int hours[], const int arrLength);             // Function prototypes listed before main()
                                                                                    // 2 separate functions name Gpa can be called with different
float Gpa(const float gradePoints[], const int hours[], const int arrLength);       // arguments. Example of Function Overloading

float gradePoints(const char grade);

int main()
{
    

    const float gradePoint[5] = { 4,3,2,1,0 };                                      // conctant float array for the numerical grade value
    const char grade[5] = { 'A','B','C','D','F' };                                  // constant character array for the alphabetical grade

    int numCourses = 0;
    
    cout << "Please enter the number of courses:" << endl;
    cin >> numCourses;                                                              // User input for number of courses
    cin.ignore();

    do {                                                                            // Checks for only positive integers being entered
        if (numCourses <= 0) {
            cout << "Invalid entry" << endl;            
            cin >> numCourses; 
            cin.ignore();
        }
    } while (numCourses <= 0);
    
    cout << endl;
            
    int* courses = new int[numCourses];                                             // Memory allocated for 3 separate arrays, each the size
    char* courseGrade = new char[numCourses];                                       // of numCourses
    int* hours = new int[numCourses];

    for (int i = 0; i < numCourses; i++) {                                          // Loop to input alphabetical grade value into array courseGrade[]
        courses[i] = i + 1;
        cout << "Please enter the grade for course " << courses[i] << " (A, B, C, D or F)" << endl;
                
        cin.get(courseGrade[i]);
        cin.ignore();       
        
        while (courseGrade[i] != 'A' && courseGrade[i] != 'B' && courseGrade[i]     // While loop ensures only valid grade values can be input
            != 'C' && courseGrade[i] != 'D' && courseGrade[i] != 'F') {
            cout << "Invalid entry" << endl;
            cin.get(courseGrade[i]);                                                
            cin.ignore();            
        }            
    }

    cout << endl;

    for (int i = 0; i < numCourses; i++) {                                          // Loop to input the course hours into array hours[]
        cout << "How many hours in course " << i + 1 << "?" << endl;
        cin >> hours[i];
    }

    cout << endl;

    for (int i = 0; i < numCourses; i++) {                                          // Lists the number of courses, alphabetical grade, and hours
        cout << "Course: " << courses[i] << "  Grade: " 
            << courseGrade[i] << "  Hours: "<< hours[i] << endl;
    }

    cout << endl;

    cout << "Part D - Gpa is: " << setprecision(3)                                  // function Gpa is called passing char array courseGrade
        << Gpa(courseGrade, hours, numCourses) << endl << endl;                     // as first argument

    float* gradeArray = new float[numCourses];                                      // Memory allocated for gradeArray to store numerical grade values

    for (int i = 0; i < numCourses; i++) {
        gradeArray[i] = gradePoints(courseGrade[i]);                                // Function gradePoints is called passing gradeArray as argument
    }                                                                               

    cout << "Part E - Gpa is: " << setprecision(3)                                  // Function Gpa is called again, this time passing float array
        << Gpa(gradeArray, hours, numCourses) << endl;                              // gradeArray as first argument

    delete[] courses;                                                               // Memory is freed
    delete[] courseGrade;
    delete[] hours;
    delete[] gradeArray;

    return 0;
}


float Gpa(const char grades[], const int hours[], const int arrLength) 
{
    float sumGrade = 0;                                                             // float sumGrade and int hourTotal variables declared locally
    float hourTotal = 0;
    for (int i = 0; i < arrLength; i++) {        
        sumGrade = sumGrade + (gradePoints(grades[i]) * hours[i]);                  // Loop calculates the sum of (grades / hours) 
    }                                                                               // Function gradePoints is called within the loop to convert
                                                                                    // alphabetical grade to numerical grade
    for (int i = 0; i < arrLength; i++) {
        hourTotal = hourTotal + hours[i];                                           // Loop calculates the sum of the hours
    }

    return sumGrade / hourTotal;                                                    // Function returns the final Gpa result
}


float Gpa(const float gradePoints[], const int hours[], const int arrLength)
{
    float sumGrade = 0;                                                             // Function operates similarly to above, though no char
    float hourTotal = 0;                                                              // conversion is required since float array gradePoints
    for (int i = 0; i < arrLength; i++) {                                           // is taken as a parameter
        sumGrade = sumGrade + (gradePoints[i] * hours[i]);
    }

    for (int i = 0; i < arrLength; i++) {
        hourTotal = hourTotal + hours[i];
    }
    return sumGrade / hourTotal;
}


float gradePoints(const char grade) {                                               // Function takes a constant char array as a parameter
    if (grade == 'A') {                                                             // and returns the numerical value of the alphabetical 
        return 4.0;                                                                 // grade being passed
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
    else if (grade == 'F'){
        return 0.0;
    }
}