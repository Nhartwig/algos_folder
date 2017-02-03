// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1a
// Implementation of the Code Class
// Responese class performs the action of the number of correct and incorrect
// for a given pair of codes whcih are the secret code and guess code
// these values are checked using the Code class functionality
// these are then stored in variables correct and incorrect
//overloaded operators are used to compare two responeses andalso
//to print out the value of correct and incorrect in object contains definitnion
//for set/getCorrect, set/getIncorrect, ==overload and << overload
#include "response.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>




	response::response(int numIncor, int numCor)
    // constructor intializes reponse class with 0 for
    //num incorrect and num correct and uses user passed
    //values for correct and incorrrect
    {
			setIncorrect(numIncor);//sets the number of inccorect in reponese
			setCorrect(numCor);//sets the number of correct in responese
		}


	int response::getIncorrect()
    // "getter" function for num incorrect
    //input nothing but reutrn number of
    //incorrect which is a integer
    {
		return numIncor;
        //returns number of incorrect
	}


	int response::getCorrect()
    // getter function for num correct
    //input nothing but reutrn number of
    //correct which is a integer
    {
		return numCor;
        //returns number of correct
	}


	void response::setIncorrect(int incor)
    // setter function for num incorrect
    //input value to set number incorrect
    //returns nothing just void return
    {
		numIncor = incor;
	}

	void response::setCorrect(int cor)
    // setter function for num correct
    //input value to set number correc
    //returns nothing just void return
    {
		numCor = cor;
	}


	bool operator==(response& response_one,response& response_two)
    // boolean === overloaded operator function to check if responses are equal
    // the input are responses , and gets compared to the response values in the  objects
    //checks the number of correct and incorrect in each objects and checks if they are equal
    //therefore returning the value of true or false
    {
		//checks number of correct and incorrect in each object and tests if they are equal
        
        if (((response_one.numCor) == (response_two.numCor)) && ((response_one.numIncor) == (response_two.numIncor))) {
			return true;//return true if all equal
			}
		else
			return false;//return false if not equal
	}




	std::ostream& operator<<(std::ostream& ostr, response& print_response)
    // overloaded operator function to cout the number of correct and incorrect to the player
    //takes in the ostream object which is used for the cout and takes in a printreponses which
    //contains the number of correct and incorrect the object and prints these values
    //retunrs an ostream which is the output of the function
    {
		ostr << "Number of correct elements is: " << print_response.numCor << std::endl;
        //prints to output the number of incorrect elements
		ostr << "Number of correct elements in incorrect position is " << print_response.numIncor << std::endl;
        //prints to output the number of correct elements
		return ostr;//returns ostream of output stream
	}










