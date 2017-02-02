

#include "response.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>



	// constructor intializes reponse class with 0 for num incorrect and num correct
	response::response(int numIncor, int numCor) {
			setIncorrect(numIncor);
			setCorrect(numCor);
		}

	// "getter" function for num incorrect
	int response::getIncorrect() {
		return numIncor;
	}

	// getter function for num correct
	int response::getCorrect() {
		return numCor;
	}

	// setter function for num incorrect
	void response::setIncorrect(int incor) {
		numIncor = incor;
	}

	// setter function for num correct
	void response::setCorrect(int cor) {
		numCor = cor;
	}

	// boolean type overloaded operator function to check if responses are equal
	// the input is a response object, and gets compared to the response values in the currect object
	bool operator==(response& response_one,response& response_two){
		if (((response_one.numCor) == (response_two.numCor)) && ((response_one.numIncor) == (response_two.numIncor))) {
			return true;
			}
		else
			return false;
	}



	// overloaded operator function to cout the number of correct and incorrect to the player
	std::ostream& operator<<(std::ostream& ostr, response& print_response){
		ostr << "Number of correct elements is: " << print_response.numCor << std::endl;
		ostr << "Number of correct elements in incorrect position is " << print_response.numIncor << std::endl;
		return ostr;
	}










