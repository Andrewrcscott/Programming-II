#include <iostream>
#include "Disc.h"  
#include <cmath>
#include <iomanip>
#include <windows.h>

float distanceCalc(const int x1, const int x2, const int y1, const int y2);       
// Function prototype to calculate distance between discs on grid

void winOrLose(float d, const float r1, const float r2);    // Function prototype to determine if discs overlap

int main()
{
    Disc d1;                                                // Two Disc class members created 
    Disc d2;
    float distance = 0;

    cout << "Enter the Radius of Disc 1: ";                 // User input for Disc 1 radius
    d1.setRadius();                                         // Calls public function setRadius for member d1

    cout << endl;

    cout << "Enter the Radius of Disc 2: ";                 // User input for Disc 2 radius
    d2.setRadius();                                         // Calls public function setRadius for member d2

    cout << endl;

    cout << "Press Enter to throw the discs" << endl;
    cin.get();
    cin.get();

    d1.setXCoordinate();                                    // Calls setter functions setXCoordinate and
    d1.setYCoordinate();                                    // setYCoordinate for member d1

    d2.setXCoordinate();                                    // Calls setter functions setXCoordinate and
    d2.setYCoordinate();                                    // setYCoordinate for member d2

    cout << "Disc 1 landed at (" << d1.getXCoordinate() << "," << d1.getYCoordinate() << ")" << endl;
    // Calls getter functions getXCoordinates and getYCoordinates to display member d1 variables

    cout << "Disc 2 landed at (" << d2.getXCoordinate() << "," << d2.getYCoordinate() << ")" << endl;
    // Calls getter functions getXCoordinates and getYCoordinates to display member d2 variables

    distance = distanceCalc(d1.getXCoordinate(), d2.getXCoordinate(), d1.getYCoordinate(), d2.getYCoordinate());
    // Calls distanceCalc function passing d1 & d2 coordinate getter functions as arguments, return value is assigned 
    // to distance variable

    cout << "Total radii is " << fixed << setprecision(2) << (d1.getRadius() + d2.getRadius()) << endl;
    // Outputs the sum of d1 and d2 radii to console

    winOrLose(distance, d1.getRadius(), d2.getRadius());
    // Function determines whether the user wins or loses, passes distance variable, d1 radius and d2 radius as
    // arguments. d1 & d2 are cast as floats for the function calculation

    d1.~Disc();
    d2.~Disc();
    return 0;
}


float distanceCalc(const int x1, const int x2, const int y1, const int y2) { // Const ints as parameters to prevent altering 
    float d = 0.00;                                                          // private member data

    d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));                    // Calculation using Pythagorean theorem
                                                                    // to determine distance between disc center points
    cout << endl << "Distance from Disc 1 to Disc 2 is " << fixed << setprecision(2)<<d << endl;
                                                                    // Outputs results to 2 decimal places
    return d;
}

void winOrLose(float d, const float r1, const float r2) {   

    HANDLE  hConsole;   // Console color code referenced from https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text
    int k;              // Strictly cosmetic
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (d < (r1 + r2)) {                            // If the distance (d) is less than the sum of the radii of d1 and d2,
        k = 2;                                      // the discs are overlapping and the user wins.
        SetConsoleTextAttribute(hConsole, k);
        cout << endl << "WINNER!!!" << endl;
        k = 15;
        SetConsoleTextAttribute(hConsole, k);
    }
    else {                                           // Otherwise the discs are not overlapping and the user loses.
        k = 4;
        SetConsoleTextAttribute(hConsole, k);
        cout << endl << "Sorry, you lose :(" << endl;
        k = 15;
        SetConsoleTextAttribute(hConsole, k);
    }
}