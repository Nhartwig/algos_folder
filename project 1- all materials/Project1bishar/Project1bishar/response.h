// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Prototype of the responese Class
// Responese class performs the action of the number of correct and incorrect
// for a given pair of codes whcih are the secret code and guess code
// these values are checked using the Code class functionality
// these are then stored in variables correct and incorrect
//overloaded operators are used to compare two responeses andalso
//to print out the value of correct and incorrect in object contains definitnion
//for set/getCorrect, set/getIncorrect, ==overload and << overload
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

		int numIncor;//number of incorrect valyes bettween two objects
		int numCor;//number of correct valyes bettween two objects

	public:
        //Constructor passing in number of correct and incorrect
		response(int numIncor = 0, int numCor = 0);
        //returns the number of correct variable
		int getCorrect();
        //returns the number of incorrect variable
		int getIncorrect();
        //sets the number of correct variable
		void setCorrect(int cor);
        //sets the number of incorrect variable
		void setIncorrect(int incor);
		//friend function of class which defines overloaded equality operator
        //the equality is compared bettween two responese objects
		friend bool operator== (response& response_one,response& response_two);
        //friend function of class which defines overloaded << operator
        //the << operator returns an ostream to print out of the print responese
        //which is the number of correct and incorrect
		friend std::ostream&  operator<<(std::ostream& ostr, response& print_response);

};

#endif
