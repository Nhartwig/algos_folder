#pragma once
#ifndef response_h
#define response_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <ostream>

class response {
		
	private:

		int numIncor;
		int numCor;

	public:	

		response(int numIncor = 0, int numCor = 0);

		int getCorrect();

		int getIncorrect();

		void setCorrect(int cor);

		void setIncorrect(int incor);
		
		friend bool operator== (const response& lhs, const response& rhs);

		friend void operator<< (ostream& ostr, const response& Response);

};







#endif