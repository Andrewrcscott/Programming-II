// Programming II Lab 1, created by Andrew Scott


#include <iostream>
#include <string>                                                   // <string> and <iomanip> libraries used for string handling and
#include <iomanip>                                                  // string field manipulation.



int main()
{
    using namespace std;                                            

    int classSize = 0;                                              // int variable declared for the number of students in the class 
        
    cout << "How many students are there in the class?" << endl;
    (cin >> classSize).get();                                       // user input for classSize, get() used to clear input stream.
    
    cout << endl << "The class has " << classSize << " students\n"<< endl;
    cin.clear();
                      
    string* firstName = new string[classSize];                      // Three arrays created at runtime based on the classSize variable
    string* lastName = new string[classSize];                       // Memory allocated according to size of string and double data types
    double* grade = new double[classSize];

    for (int i = 0; i < classSize; i++)
    {
        cout << "Student " << i + 1 << endl;                        // For loop iterates i times based on classSize, prompts user
        cout << "First name: ";                                     // for student's first name, last name and grade achieved.
        getline(cin, firstName[i]);                                 // Data is stored in corresponding arrays at index [i].
        cout << "Last name: ";
        getline(cin, lastName[i]);
        
        cout << "Grade achieved: ";
        (cin >> grade[i]).get();
        cout << endl;        
    }

    cout << endl << "Grades before sorting:\n";
    cout << endl;

    for (int i = 0; i < classSize; i++)                             // Loop prints student info before sorting
    {
        cout << left << setw(15) << firstName[i] << " " << setw(15) << lastName[i] << "|  Grade: " << grade[i];
        cout << endl;
    }

    for (int n = 0; n < classSize; n++)                             // Bubble sort as referenced from C How to Program, Ch. 6
    {                                                               // First for loop iterates n times based on classSize
        for (int i = 0; i < (classSize - 1); i++)                   // Second for loop iterates 1 less than classSize, since the last 
        {                                                           // element has nothing to compare to.
            if (grade[i] > grade[i + 1])                            // If statement compares grade[i] to the next value in the array,
            {                                                       // if value is greater, the values are swapped.
                //double hold = grade[i];
                //grade[i] = grade[i + 1];
                //grade[i + 1] = hold;
                swap(grade[i], grade[i + 1]);                       // C++ integrated swap function

                string holdFirst = firstName[i];                    // Swapping using placeholder variable
                firstName[i] = firstName[i + 1];
                firstName[i + 1] = holdFirst;

                string holdLast = lastName[i];
                lastName[i] = lastName[i + 1];
                lastName[i + 1] = holdLast;
            }
        }
    }

    cout << endl << "\nGrades after sorting:\n";
    cout << endl;

    for (int i = 0; i < classSize; i++)                             // Loop prints student info after sorting, in ascending order.
    {
        cout << setw(15) << firstName[i] << " " << setw(15) << lastName[i] << "|  Grade: " << grade[i];
        cout << endl;
    }

    delete[] firstName, lastName, grade;                            // memory is freed 
    
    return 0;
}


