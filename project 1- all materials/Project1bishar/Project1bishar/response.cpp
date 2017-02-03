
// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Implementation of the Code Class
// Responese class performs the action of the number of correct and incorrect
// for a given pair of codes whcih are the secret code and guess code
// these values are checked using the Code class functionality
// these are then stored in variables correct and incorrect
// overloaded operators are used to compare two responses and also
// to print out the value of correct and incorrect in object contains definition
// for set/getCorrect, set/getIncorrect, ==overload and << overload
#include "response.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>


	// constructor intializes response class with 0 for
	// num incorrect and num correct and times user has passed
	// values for correct and incorrrect
	response::response(int numIncor, int numCor)
    {
			setIncorrect(numIncor);	// sets the number of incorrect in response
			setCorrect(numCor);		// sets the number of correct in response
	}


	// "getter" function for num incorrect
	// input nothing but reutrn number of
	// incorrect which is a integer
	int response::getIncorrect()
    {
		return numIncor; // returns number of incorrect
        
	}

	// getter function for num correct
	// input nothing but return number of
	// correct which is a integer
	int response::getCorrect()
    {
		return numCor; // returns number of correct
	}

	// setter function for num incorrect
	// input value to set number incorrect
	// returns nothing just void return
	void response::setIncorrect(int incor)
    {
		numIncor = incor;
	}

	// setter function for num correct
	// input value to set number correct
	// returns nothing just void return
	void response::setCorrect(int cor)
    {
		numCor = cor;
	}
	
	// boolean == overloaded operator function to check if responses are equal.
	// The inputs are responses, and get compared to the response values in the objects.
	// Checks the number of correct and incorrect in each objects and checks if they are equal
	// therefore returning the value of true or false.
	bool operator == (response& response_one,response& response_two)
    {
		// checks number of correct and incorrect in each object and tests if they are equal        
        if (((response_one.numCor) == (response_two.numCor)) && ((response_one.numIncor) == (response_two.numIncor))) 
		{
			return true;  // return true if all equal
		}
		else
			return false; // return false if not equal
	} // end of overloaded == operator function



	// Overloaded operator function to cout the number of correct and incorrect to the player.
	// Takes in the ostream object which is used for the cout and takes in a print_response which
	// contains the number of correct and incorrect in the object, and prints these values.
	// Returns an ostream which is the output of the function.
	std::ostream& operator<<(std::ostream& ostr, response& print_response)
    {
		// prints to output the number of incorrect elements
		ostr << "Number of correct elements is: " << print_response.numCor << std::endl;

		// prints to output the number of correct elements
		ostr << "Number of correct elements in incorrect position is " << print_response.numIncor << std::endl;
        
		return ostr; // returns ostream of output stream
	} // end of overloaded cout<< operator function










