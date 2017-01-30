

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

	// overloaded operator function to check if responses are equal
	friend bool response::operator==(const response& lhs, const response& rhs){
		if (((lhs.getCorrect) == (rhs.getCorrect)) && ((lhs.getIncorrect) == (rhs.getIncorrect))) {
			return true;
			}
		else
			return false;
		
	}












