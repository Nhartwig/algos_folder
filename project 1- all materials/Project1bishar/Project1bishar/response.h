
// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Prototype of the response Class
// Response class performs the action of the number of correct and incorrect
// for a given pair of codes which are the secret code and guess code.
// These values are then checked using the Code class functionality,
// then these are then stored in variables correct and incorrect.
// Overloaded operators are used to compare two responses and also
// to print out the value of correct and incorrect. 
// In the object is contained a definition for set/getCorrect, 
// set/getIncorrect, ==overload and << overload
#pragma once
#ifndef response_h
#define response_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <ostream>

// class response, stores the response to a guess (num correct and num incorrect)
class response {
		
	private:

		int numIncor;								// number of incorrect valyes bettween two objects
		int numCor;									// number of correct valyes bettween two objects

	public:
		
		response(int numIncor = 0, int numCor = 0); // Constructor passing in number of correct and incorrect
		int getCorrect();							// returns the number of correct digits
		int getIncorrect();							// returns the number of correct-valued digits in the incorrect positions
		void setCorrect(int cor);					// sets the number of correct 
		void setIncorrect(int incor);				// sets the number of incorrect 
		
		// friend function of response class which defines overloaded equality operator
        // the equality is compared bettween two response objects
		friend bool operator== (response& response_one, response& response_two);

        // friend function of class which defines overloaded << operator
        // the << operator returns an ostream to print the response
        // which is the number of correct and incorrect digits
		friend std::ostream&  operator<<(std::ostream& ostr, response& print_response);

}; // end of the response class

#endif
