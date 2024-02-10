#include "Disc.h"
#include <random>
#include <iostream>

using namespace std;

void Disc::setRadius() {        // Setter funciton for radius variable
    float r = 0;                // Check variable declared, user is prompted for disc radius and only accepts
    cin >> r;                   // positive float values    

    if (r > 0) {                // If r is greater than 0, private member radius is assigned value of r
        radius = r;
    }
    else {
        cout << "Please input positive integer" << endl;    // If r is less than or equal to 0, error is displayed
        setRadius();                                        // and function is repeated
    }    
}

float Disc::getRadius() {               // Getter function returns the float value of radius variable
    return radius;
}
    
void Disc::setXCoordinate() {           // Setter function for X coordinate    
    random_device rd;                   // Random integer generator referenced from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    mt19937 gen(rd());    
    uniform_int_distribution<int> distrib(1, 10);   // X coordinate variable is assigned the value from the 
    xCoordinate = distrib(gen);                     // number generator 
}
int Disc::getXCoordinate() {
    return xCoordinate;                 // Getter function returns the int value of the X coordinate variable
}

void Disc::setYCoordinate() {           // Setter function for Y coordinate 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 10);   // Y coordinate variable is assigned the value from the
    yCoordinate = distrib(gen);                     // number generator
}
int Disc::getYCoordinate() {
    return yCoordinate;                 // Getter function returns the int value of the Y coordinate variable
}

Disc::~Disc() {}

