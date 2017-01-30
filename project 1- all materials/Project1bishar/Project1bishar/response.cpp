

#include "response.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>


/*class response {
private:
	int numIncor;
	int numCor;
public:
	response(int numIncor = 0, int numCor = 0);
	int getIncorrect();
	int getCorrect();
	void setIncorrect(int incor);
	void setCorrect(int cor);
	bool operator== (const response& lhs, const response& rhs);
	void operator<< (ostream& ostr, const response& Response);
};*/

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
		if (((response_one.getCorrect()) == (response_two.getCorrect())) && ((response_one.getIncorrect()) == (response_two.getIncorrect()))) {
			return true;
			}
		else
			return false;
	}



	// overloaded operator function to cout the number of correct and incorrect to the player
	std::ostream& operator<<(std::ostream& ostr, response& print_response){
		ostr << " number of correct elements is: " << print_response.getCorrect() << std::endl;
		ostr << " number of correct elements in incorrect position is" << print_response.getIncorrect() << std::endl;
		return ostr;
	}










