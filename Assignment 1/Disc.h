#pragma once
#ifndef DISC_H_
#define DISC_H_

using namespace std;

class Disc {

private:					// Private member variables declared

	int xCoordinate;
	int yCoordinate;
	float radius;

public:							// Public member functions declared, setter and getter functions used to 
								// access private member data.

	void setRadius();			// Setter and getter functions for the disc radius
	float getRadius();

	void setXCoordinate();		// Setter and getter functions for the disc X coordinate
	int getXCoordinate();

	void setYCoordinate();		// Setter and getter functions for the disc Y coordinate
	int getYCoordinate();
		
	~Disc();					// Destructor
};

#endif